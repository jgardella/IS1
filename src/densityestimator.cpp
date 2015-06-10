#include "densityestimator.hh"

static std::map<std::pair<int, int>, float>* estimate(std::string csvfile, int volumeSize)
{
	std::vector<Shape>* shapes = CSVParser::parseCSV(csvfile, 0, minR, maxR, radius);


}

static void calculateBoundingVolume(std::vector<Shape>* shapes)
{
	float minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;
	float maxX = FLT_MIN, maxY = FLT_MIN, maxZ = FLT_MIN;
	for(unsigned int i = 0; i < shapes->size(); i++)
	{
		Shape shape = shapes->at(i);
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
