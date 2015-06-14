#include "densityestimator.hh"
#include "vertex.hh"

#include <iostream>
#include <map>

int main(int argc, const char* argv [])
{
	if(argc < 3)
	{
		std::cout << "usage: ./test <csvfile> <volumeRatio>\n";
	}
	else
	{
		std::map<Vertex, float, CmpVertex>* densityMap = DensityEstimator::estimate(argv[1], std::atoi(argv[2]));
		for(auto iter : *densityMap)
		{
			Vertex v = iter.first;
			std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ") --> " << iter.second << '\n';
		}
	}
	return 0;
}
