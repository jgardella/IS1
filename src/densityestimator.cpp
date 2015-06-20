#include "densityestimator.hh"

float DensityEstimator::minX;
float DensityEstimator::maxX;
float DensityEstimator::minY;
float DensityEstimator::maxY;
float DensityEstimator::minZ;
float DensityEstimator::maxZ;
std::vector<Shape>* DensityEstimator::shapes;

std::pair<Vertex, float>*** DensityEstimator::estimate(std::string csvfile, float subvolumeWidth, float resolution, int& xSize, int& ySize, int& zSize)
{
	float i, j, k;
	int xIdx, yIdx, zIdx;

	// parse shapes and calcualte bounding box
	shapes = CSVParser::parseCSV(csvfile, 0, 35, 60, 48);
	calculateBoundingVolume(shapes);

	// create 3d array for holding density estimations
	int xRange = (int)((maxX + subvolumeWidth - minX) / resolution) + 1;
	int yRange = (int)((maxY + subvolumeWidth - minY) / resolution) + 1;
	int zRange = (int)((maxZ + subvolumeWidth - minZ) / resolution) + 1;
	std::pair<Vertex, float>*** densityMap = new std::pair<Vertex, float>**[xRange];
	for(xIdx = 0; xIdx < xRange; xIdx++)
	{
		densityMap[xIdx] = new std::pair<Vertex, float>*[yRange];
		for(yIdx = 0; yIdx < yRange; yIdx++)
		{
			densityMap[xIdx][yIdx] = new std::pair<Vertex, float>[zRange];
		}
	}

	// iterate through subvolumes and calculate density for each
	for(i = minX, xIdx = 0; i < maxX + subvolumeWidth; i += resolution, xIdx++)
	{
		for(j = minY, yIdx = 0; j < maxY + subvolumeWidth; j += resolution, yIdx++)
		{
			for(k = minZ, zIdx = 0; k < maxZ + subvolumeWidth; k += resolution, zIdx++)
			{
				calculateDensityForSubvolume(new Cube(i, j, k, subvolumeWidth), densityMap, xIdx, yIdx, zIdx);
			}
		}
	}

	xSize = xRange;
	ySize = yRange;
	zSize = zRange;
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

void DensityEstimator::calculateDensityForSubvolume(Cube* subvolume, std::pair<Vertex, float>*** densityMap, int xIdx, int yIdx, int zIdx)
{
	unsigned int s;

	// count bacteria in subvolume
	int numBacteria = 0;
	for(s = 0; s < shapes->size(); s++)
	{
		Shape shape = shapes->at(s);
		if(subvolume->contains(shape))
		{
			numBacteria++;
		}
	}

	// add calculated density to map
	densityMap[xIdx][yIdx][zIdx] = std::pair<Vertex, float>(*(new Vertex(subvolume->getX(), subvolume->getY(), subvolume->getZ())),
												((float) numBacteria) /  subvolume->getVolume());
}
