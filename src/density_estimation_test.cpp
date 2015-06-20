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
		std::map<Vertex, float, CmpVertex>* densityMap = DensityEstimator::estimate(argv[1], std::atof(argv[2]), std::atof(argv[3]));
		for(auto iter : *densityMap)
		{
			Vertex v = iter.first;
			if(iter.second > 0)
			{
				std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ") --> " << iter.second << '\n';
			}
		}
		Shape* pointCloud = DensityVisualizer::thresholdDensity(densityMap, .000025, std::atof(argv[2]));
		PlyWriter::write(*pointCloud, "ply/pointCloud.ply");
	}
	return 0;
}
