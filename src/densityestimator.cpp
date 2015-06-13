#include "densityestimator.hh"

std::map<std::pair<int, int>, float>* DensityEstimator::estimate(std::string csvfile, int volumeRatio)
{
	float i, j, k;

	shapes = CSVParser::parseCSV(csvfile, 0, minR, maxR, radius);
	calculateBoundingVolume(shapes);

	subvolumeSize = ((maxX - minX) * (maxY - minY) * (maxZ - minZ)) / volumeRatio;
	subvolumeWidth = std::cbrt(subvolumeSize);

	std::map<Vertex, float>* densityMap = new std::map<Vector, float>();
	for(i = minX; i < maxX; i += subvolumeWidth)
	{
		for(j = minY; j < maxY; j += subvolumeWidth)
		{
			for(k = minZ; k < maxZ; k += subvolumeWidth)
			{
				calculateDensityForSubvolume(new Cube(i, j, k, subvolumeSize), densityMap);
			}
		}
	}

	return densityMap;
}

void DensityEstimator::calculateBoundingVolume(std::vector<Shape>* shapes)
{
	minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;
	maxX = FLT_MIN, maxY = FLT_MIN, maxZ = FLT_MIN;
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

void DensityEstimator::calculateDensityForSubvolume(Cube* subvolume, std::map<Vertex, float> densityMap)
{
	int s;

	// count bacteria in subvolume
	int numBacteria = 0;
	for(s = 0; s < shapes->size(); s++)
	{
		if(subvolume->contains(shapes->at(s)))
		{
			numBacteria++;
		}
	}

	// add calculated density to map
	densityMap->insert(std::pair<Vertex, float>(*(new Vertex(subvolume->getX(), subvolume->getY(), subvolume->getZ())),
												((float) numBacteria) /  subvolumeSize));
}
