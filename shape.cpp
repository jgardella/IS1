#include "shape.hh"

Shape::Shape(int x, int y)
{
	this->x = x;
	this->y = y;
	vertices = new std::vector<Vertex>();
	faces = new std::vector<TFace>();
}

void Shape::addVertex(Vertex& v, bool absolute)
{
	if(!absolute) // offset from shape center if not absolute (relative)
	{
		v.x += this->x;
		v.y += this->y;
	}

	vertices->push_back(v);
}

void Shape::addTFace(int v1Idx, int v2Idx, int v3Idx)
{
	faces->push_back(TFace(v1Idx, v2Idx, v3Idx));
}
