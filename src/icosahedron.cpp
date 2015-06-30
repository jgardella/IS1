#include "icosahedron.hh"

Icosahedron::Icosahedron(float x, float y, float z, float radius, int resolution) : Shape(x, y, z)
{
	this->radius = radius;
	int i;
	unsigned int j;
	float t = (1.0 + std::sqrt(5)) / 2.0; // golden ratio (approx. 1.618)

	// add vertices
	addVertex(*new Vertex(-1,  t,  0));
	addVertex(*new Vertex( 1,  t,  0));
	addVertex(*new Vertex(-1, -t,  0));
	addVertex(*new Vertex( 1, -t,  0));

	addVertex(*new Vertex( 0, -1,  t));
	addVertex(*new Vertex( 0,  1,  t));
	addVertex(*new Vertex( 0, -1, -t));
	addVertex(*new Vertex( 0,  1, -t));

	addVertex(*new Vertex( t,  0, -1));
	addVertex(*new Vertex( t,  0,  1));
	addVertex(*new Vertex(-t,  0, -1));
	addVertex(*new Vertex(-t,  0,  1));

	// add faces
	// 5 faces around point 0
	addTFace(0, 11, 5);
	addTFace(0, 5, 1);
	addTFace(0, 1, 7);
	addTFace(0, 7, 10);
	addTFace(0, 10, 11);

	// 5 adjacent faces
	addTFace(1, 5, 9);
	addTFace(5, 11, 4);
	addTFace(11, 10, 2);
	addTFace(10, 7, 6);
	addTFace(7, 1, 8);

	// 5 faces around point 3
	addTFace(3, 9, 4);
	addTFace(3, 4, 2);
	addTFace(3, 2, 6);
	addTFace(3, 6, 8);
	addTFace(3, 8, 9);

	// 5 adjacent faces
	addTFace(4, 9, 5);
	addTFace(2, 4, 11);
	addTFace(6, 2, 10);
	addTFace(8, 6, 7);
	addTFace(9, 8, 1);

	// refinement
	for(i = 0; i < resolution; i++)
	{
	  this->refinementMap = new std::map<std::pair<int,int>, int>();
	  std::vector<TFace>* newFaces = new std::vector<TFace>();
	  for(j = 0; j < this->getFaces()->size(); j++)
	  {
		  TFace face = this->getFaces()->at(j);

		  int aIdx = createMiddlePoint(face.v1Idx, face.v2Idx);
		  int bIdx = createMiddlePoint(face.v2Idx, face.v3Idx);
		  int cIdx = createMiddlePoint(face.v3Idx, face.v1Idx);

		  newFaces->push_back(*new TFace(face.v1Idx, aIdx, cIdx));
		  newFaces->push_back(*new TFace(face.v2Idx, bIdx, aIdx));
		  newFaces->push_back(*new TFace(face.v3Idx, cIdx, bIdx));
		  newFaces->push_back(*new TFace(aIdx, bIdx, cIdx));
	  }
	  this->setFaces(newFaces);
	  delete refinementMap;
	}
}

int Icosahedron::addVertex(Vertex& v)
{
	// normalize vertex to unit circle
	double length = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	// change positioning to absolute
	Vertex* adjustedV = new Vertex(radius * v.x/length, radius * v.y/length, radius * v.z/length);
	adjustedV->x += this->x;
	adjustedV->y += this->y;
	adjustedV->z += this->z;
	this->getVertices()->push_back(*adjustedV);
	return this->getVertices()->size() - 1;
}

int Icosahedron::createMiddlePoint(int v1Idx, int v2Idx)
{
	std::pair<int, int> vPair1 = std::make_pair(v1Idx, v2Idx);
	std::pair<int, int> vPair2 = std::make_pair(v2Idx, v1Idx);

	// check if map already contains this vertex pair
	std::map<std::pair<int, int>, int>::iterator i1 = refinementMap->find(vPair1);
	if(i1 != refinementMap->end())
	{
		return i1->second;
	}

	// check if map contains reverse of vertex pair
	std::map<std::pair<int, int>, int>::iterator i2 = refinementMap->find(vPair2);
	if(i2 != refinementMap->end())
	{
		return i2->second;
	}

	// calculate refined point
	Vertex v1 = this->getVertices()->at(v1Idx);
	Vertex v2 = this->getVertices()->at(v2Idx);

	// subtract icosahedron's coordinates to get relative positioning
	float newX = (v1.x + v2.x) / 2 - this->x;
	float newY = (v1.y + v2.y) / 2 - this->y;
	float newZ = (v1.z + v2.z) / 2 - this->z;

	// add new vertex to refinement map and return index
	int storedIdx = this->addVertex(*new Vertex(newX, newY, newZ));
	refinementMap->insert(std::make_pair(std::make_pair(v1Idx, v2Idx), storedIdx));
	return storedIdx;
}

float Icosahedron::getRadius()
{
	return radius;
}

bool Icosahedron::contains(float x, float y, float z)
{
	return (x - this->x) * (x - this->x) + (y - this->y) * (y - this->y) + (z - this->z) * (z - this->z) <= this->radius * this->radius;
}

bool Icosahedron::intersectsCube(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
{
	float dist_squared = radius * radius;
	if(this->x < minX)
	{
		dist_squared -= (this->x - minX) * (this->x - minX);
	}
	else if(this->x > maxX)
	{
		dist_squared -= (this->x - maxX) * (this->x - maxX);
	}

	if(this->y < minY)
	{
		dist_squared -= (this->y - minY) * (this->y - minY);
	}
	else if(this->y > maxY)
	{
		dist_squared -= (this->y - maxY) * (this->y - maxY);
	}

	if(this->z < minZ)
	{
		dist_squared -= (this->z - minZ) * (this->z - minZ);
	}
	else if(this->z > maxZ)
	{
		dist_squared -= (this->z - maxZ) * (this->z - maxZ);
	}

	return dist_squared > 0;
}
