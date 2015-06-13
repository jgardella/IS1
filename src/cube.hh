#ifndef _CUBE_HH_
#define _CUBE_HH_

#include "shape.hh"

class Cube : public Shape
{
	public:

		Cube(float x, float y, float z, float w);

		bool contains(Shape* shape);

	private:
		float width;
		int minX, maxX;
		int minY, maxY;
		int minZ, maxZ;
};

#endif
