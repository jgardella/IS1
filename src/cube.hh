#ifndef _CUBE_HH_
#define _CUBE_HH_

#include "shape.hh"

#include <iostream>

class Cube : public Shape
{
	public:

		Cube(float x, float y, float z, float w);

		bool contains(Shape& shape);

	private:
		float width;
		float minX, maxX;
		float minY, maxY;
		float minZ, maxZ;
};

#endif
