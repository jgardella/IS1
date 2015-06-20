#ifndef _DENSITYVISUALIZER_HH_
#define _DENSITYVISUALIZER_HH_

#include <map>
#include <iostream>

#include "shape.hh"
#include "vertex.hh"

class DensityVisualizer
{
	public:
		static Shape* thresholdDensity(std::map<Vertex, float, CmpVertex>* densityMap, float threshold, float subvolumeWidth);

	private:
		static Shape* pointCloud;
		static float threshold;
		static std::map<Vertex, float, CmpVertex>* densityMap;

		static void addPointIfValid(std::pair<Vertex, float> i1, std::map<Vertex, float, CmpVertex>::iterator i2);


};

#endif
