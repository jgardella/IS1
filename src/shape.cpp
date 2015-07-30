#include "shape.hh"

int Shape::shapeId = 0;

Shape::Shape(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->id = Shape::shapeId++;
	vertices = new std::vector<Vertex>();
	faces = new std::vector<TFace>();
}

Shape::Shape(float x, float y, float z, unsigned char r, unsigned char g, unsigned char b)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->id = Shape::shapeId++;
	vertices = new std::vector<Vertex>();
	faces = new std::vector<TFace>();
	this->r = r;
	this->g = g;
	this->b = b;
}

int Shape::addVertex(Vertex& v, bool absolute)
{
	if(!absolute) // offset from shape center if not absolute (relative)
	{
		v.x += this->x;
		v.y += this->y;
		v.z += this->z;
	}

	vertices->push_back(v);
	return vertices->size() - 1;
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

int Shape::getId()
{
	return id;
}

void Shape::setFaces(std::vector<TFace>* newFaces)
{
	delete faces;
	this->faces = newFaces;
}

float Shape::getX()
{
	return x;
}

float Shape::getY()
{
	return y;
}

float Shape::getZ()
{
	return z;
}

unsigned char Shape::getR()
{
	return r;
}

unsigned char Shape::getG()
{
	return g;
}

unsigned char Shape::getB()
{
	return b;
}
