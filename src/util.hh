#ifndef _UTIL_HH_
#define _UTIL_HH_

#include <vector>
#include <cfloat>
#include "shape.hh"
#include "icosahedron.hh"

class Util
{
	public:
		static void calculateBoundingVolume(std::vector<Shape>* shapes,
				float& minX, float& minY, float& minZ,
				float& maxX, float& maxY, float& maxZ);

		static void calculateSphereBoundingBox(Icosahedron& sphere,
			float& minX, float& minY, float& minZ,
			float& maxX, float& maxY, float& maxZ);
};

#endif
