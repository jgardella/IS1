#include "densityvisualizer.hh"

Shape* DensityVisualizer::pointCloud;
float DensityVisualizer::threshold;
std::pair<Vertex, float>*** DensityVisualizer::densityMap;

Shape* DensityVisualizer::thresholdDensity(std::pair<Vertex, float>*** densityMap, int xSize, int ySize, int zSize, float threshold)
{
	int i, j, k;
	pointCloud = new Shape(0, 0, 0);
	DensityVisualizer::threshold = threshold;
	DensityVisualizer::densityMap = densityMap;

	for(i = 0; i < xSize; i++)
	{
		for(j = 0; j < ySize; j++)
		{
			for(k = 0; k < zSize; k++)
			{
				addPointIfValid(i, j, k, xSize, ySize, zSize);
			}
		}
	}

	return pointCloud;
}

void DensityVisualizer::addPointIfValid(int i, int j, int k, int xSize, int ySize, int zSize)
{
	int val;
	if(i > 0)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i - 1][j][k].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i - 1][j][k].first, -val, 0, 0)), true);
		}
	}

	if(i < xSize - 1)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i + 1][j][k].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i + 1][j][k].first, val, 0, 0)), true);
		}
	}

	if(j > 0)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j - 1][k].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j - 1][k].first, 0, -val, 0)), true);
		}
	}

	if(j < ySize - 1)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j + 1][k].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j + 1][k].first, 0, val, 0)), true);
		}
	}

	if(k > 0)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j][k - 1].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j][k - 1].first, 0, 0, -val)), true);
		}
	}

	if(k < zSize - 1)
	{
		val = areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j][k + 1].second);
		if(val != 0)
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j][k + 1].first, 0, 0, val)), true);
		}
	}
}

int DensityVisualizer::areDensitiesValid(float d1, float d2)
{
	if(d1 < threshold && d2 > threshold)
		return -1;
	if(d1 > threshold && d2 < threshold)
		return 1;
	return 0;
}
