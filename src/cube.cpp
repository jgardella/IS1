#include "cube.hh"

Cube::Cube(float x, float y, float z, float w) : Shape(x, y, z)
{
	this->width = w;

	// add vertices
	addVertex(*new Vertex(-w / 2, -w / 2, -w / 2), false);
	addVertex(*new Vertex(w / 2, -w / 2, -w / 2), false);
	addVertex(*new Vertex(-w / 2, w / 2, -w / 2), false);
	addVertex(*new Vertex(-w / 2, -w / 2, w / 2), false);
	addVertex(*new Vertex(w / 2, w / 2, -w / 2), false);
	addVertex(*new Vertex(-w / 2, w / 2, w / 2), false);
	addVertex(*new Vertex(w / 2, -w / 2, w / 2), false);
	addVertex(*new Vertex(w / 2, w / 2, w / 2), false);
}

bool Cube::contains(Shape* shape)
{

}
