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
	if(i > 0)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i - 1][j][k].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i - 1][j][k].first)), true);
		}
	}

	if(i < xSize - 1)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i + 1][j][k].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i + 1][j][k].first)), true);
		}
	}

	if(j > 0)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j - 1][k].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j - 1][k].first)), true);
		}
	}

	if(j < ySize - 1)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j + 1][k].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j + 1][k].first)), true);
		}
	}

	if(k > 0)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j][k - 1].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j][k - 1].first)), true);
		}
	}

	if(k < zSize - 1)
	{
		if(areDensitiesValid(densityMap[i][j][k].second, densityMap[i][j][k + 1].second))
		{
			pointCloud->addVertex(*(new Vertex(densityMap[i][j][k].first, densityMap[i][j][k + 1].first)), true);
		}
	}
}

bool DensityVisualizer::areDensitiesValid(float d1, float d2)
{
	return (d1 < threshold && d2 > threshold) || (d1 > threshold && d2 < threshold);
}
