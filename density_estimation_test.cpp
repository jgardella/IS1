#include "densityestimator.hh"
#include "densityvisualizer.hh"
#include "plywriter.hh"
#include "vertex.hh"

#include <iostream>
#include <map>

int main(int argc, const char* argv [])
{
	if(argc < 4)
	{
		std::cout << "usage: ./test <csvfile> <volumeRatio> <overlap>\n";
	}
	else
	{
		int i, j, k;
		int xSize;
		int ySize;
		int zSize;
		std::pair<Vertex, float>*** densityMap = DensityEstimator::estimate(argv[1], std::atof(argv[2]), std::atof(argv[3]), xSize, ySize, zSize);
		for(i = 0; i < xSize; i++)
		{
			for(j = 0; j < ySize; j++)
			{
				for(k = 0; k < zSize; k++)
				{
					Vertex v = densityMap[i][j][k].first;
					float d = densityMap[i][j][k].second;
					if(d != 0)
					{
						std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ") --> " << d << '\n';
					}
				}
			}
		}
		Shape* pointCloud = DensityVisualizer::thresholdDensity(densityMap, xSize, ySize, zSize, .000025);
		PlyWriter::write(*pointCloud, "ply/pointCloud.ply");
	}
	return 0;
}
