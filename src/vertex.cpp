#include "vertex.hh"

Vertex::Vertex()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vertex::Vertex(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vertex::Vertex(Vertex& v1, Vertex& v2)
{
	this->x = (v1.x + v2.x) / 2;
	this->y = (v1.y + v2.y) / 2;
	this->z = (v1.z + v2.z) / 2;
}
