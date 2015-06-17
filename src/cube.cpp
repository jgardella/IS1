#include "cube.hh"

Cube::Cube(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = w;

	this->minX = x - w / 2;
	this->maxX = x + w / 2;
	this->minY = y - w / 2;
	this->maxY = y + w / 2;
	this->minZ = z - w / 2;
	this->maxZ = z + w / 2;
}

bool Cube::contains(Shape& shape)
{
	return shape.getX() >= this->minX && shape.getX() <= this->maxX &&
		   shape.getY() >= this->minY && shape.getY() <= this->maxY &&
		   shape.getZ() >= this->minZ && shape.getZ() <= this->maxZ;
}

float Cube::getX()
{
	return x;
}

float Cube::getY()
{
	return y;
}

float Cube::getZ()
{
	return z;
}

float Cube::getVolume()
{
	return width * width;
}
