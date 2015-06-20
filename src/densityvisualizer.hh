#ifndef _DENSITYVISUALIZER_HH_
#define _DENSITYVISUALIZER_HH_

#include <map>
#include <iostream>

#include "shape.hh"
#include "vertex.hh"

class DensityVisualizer
{
	public:
		static Shape* thresholdDensity(std::pair<Vertex, float>*** densityMap, int xSize, int ySize, int zSize, float threshold);

	private:
		static Shape* pointCloud;
		static float threshold;
		static std::pair<Vertex, float>*** densityMap;

		static void addPointIfValid(int i, int j, int k, int xSize, int ySize, int zSize);

		static bool areDensitiesValid(float d1, float d2);


};

#endif
