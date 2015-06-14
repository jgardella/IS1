#ifndef _CUBE_HH_
#define _CUBE_HH_

#include "shape.hh"

class Cube
{
	public:

		Cube(float x, float y, float z, float w);

		bool contains(Shape& shape);

		float getX();
		float getY();
		float getZ();

	private:
		float width;
		float minX, maxX;
		float minY, maxY;
		float minZ, maxZ;
		float x, y, z;
};

#endif
