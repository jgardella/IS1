#include "shape.hh"

Shape::Shape(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	vertices = new std::vector<Vertex>();
	faces = new std::vector<TFace>();
}

void Shape::addVertex(Vertex& v, bool absolute)
{
	if(!absolute) // offset from shape center if not absolute (relative)
	{
		v.x += this->x;
		v.y += this->y;
		v.z += this->z;
	}

	vertices->push_back(v);
}

void Shape::addTFace(int v1Idx, int v2Idx, int v3Idx)
{
	faces->push_back(TFace(v1Idx, v2Idx, v3Idx));
}

std::vector<Vertex>* Shape::getVertices()
{
	return vertices;
}

std::vector<TFace>* Shape::getFaces()
{
	return faces;
}
