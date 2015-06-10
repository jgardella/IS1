#ifndef _DENSITYESTIMATOR_HH_
#define _DENSITYESTIMATOR_HH_

#include <map>
#include <vector>
#include <cfloat>
#include "shape.hh"
#include "csvparser.hh"

class DensityEstimator
{
	public:
		// Calculates the density of points in the given csv file, using the given volume size.
		// Parameters:
		// std::string csvfile - the csv file to estimate density for
		// int volumeSize - the volume size to use for the density estimation. for example, if the
		//                  overal size of the dataset is 1000 u^3, and the volumeSize is given as
		// 					10, then each volume will be 1u^3, and there will be 1000 volumes
		// Returns a mapping from the center point of each volume used to the density estimate
		// for that volume.
		static std::map<std::pair<int, int>, float>* estimate(std::string csvfile, int volumeSize);

	private:

		void calculateBoundingBox(std::vector<Shape>* shapes);

};

#endif
