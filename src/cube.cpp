#include "cube.hh"

Cube::Cube(float x, float y, float z, float w) : Shape(x, y, z)
{
	this->width = w;
	this->minX = x - w / 2;
	this->maxX = x + w / 2;
	this->minY = y - w / 2;
	this->maxY = y + w / 2;
	this->minZ = z - w / 2;
	this->maxZ = z + w / 2;

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

bool Cube::contains(Shape& shape)
{
	return shape.getX() >= this->minX && shape.getX() <= this->maxX &&
		   shape.getY() >= this->minY && shape.getY() <= this->maxY &&
		   shape.getZ() >= this->minZ && shape.getZ() <= this->maxZ;
}
