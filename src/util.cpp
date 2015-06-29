#include "util.hh"

void Util::calculateBoundingVolume(std::vector<Shape*>* shapes,
		float& minX, float& minY, float& minZ,
		float& maxX, float& maxY, float& maxZ)
{
	minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;
	maxX = FLT_MIN, maxY = FLT_MIN, maxZ = FLT_MIN;
	for(unsigned int i = 0; i < shapes->size(); i++)
	{
		Shape shape = *shapes->at(i);
		if(shape.getX() < minX)
			minX = shape.getX();
		if(shape.getY() < minY)
			minY = shape.getY();
		if(shape.getZ() < minZ)
			minZ = shape.getZ();

		if(shape.getX() > maxX)
			maxX = shape.getX();
		if(shape.getY() > maxY)
			maxY = shape.getY();
		if(shape.getZ() > maxZ)
			maxZ = shape.getZ();
	}
}

void Util::calculateSphereBoundingBox(Icosahedron& sphere,
		float& minX, float& minY, float& minZ,
		float& maxX, float& maxY, float& maxZ)
{
	minX = sphere.getX() - sphere.getRadius();
	minY = sphere.getY() - sphere.getRadius();
	minZ = sphere.getZ() - sphere.getRadius();

	maxX = sphere.getX() + sphere.getRadius();
	maxY = sphere.getY() + sphere.getRadius();
	maxZ = sphere.getZ() + sphere.getRadius();
}
