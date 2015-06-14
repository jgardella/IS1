#ifndef _DENSITYESTIMATOR_HH_
#define _DENSITYESTIMATOR_HH_

#include <map>
#include <vector>
#include <cfloat>
#include "shape.hh"
#include "csvparser.hh"
#include "cube.hh"
#include "vertex.hh"

class DensityEstimator
{
	public:
		// Calculates the density of points in the given csv file, using the given volume size.
		// Parameters:
		// std::string csvfile - the csv file to estimate density for
		// int volumeRatio - the volume size to use for the density estimation. for example, if the
		//                  overal size of the dataset is 1000 u^3, and the volumeRatio is given as
		// 					10, then each volume will be 100u^3, and there will be 100 volumes
		// Returns a mapping from the center point of each volume used to the density estimate
		// for that volume.
		static std::map<Vertex, float, CmpVertex>* estimate(std::string csvfile, int volumeRatio, int overlap);

	private:
		static float minX, maxX;
		static float minY, maxY;
		static float minZ, maxZ;
		static float subvolumeSize;
		static float subvolumeWidth;

		static std::vector<Shape>* shapes;

		static void calculateBoundingVolume(std::vector<Shape>* shapes);

		static void calculateDensityForSubvolume(Cube* subvolume, std::map<Vertex, float, CmpVertex>* densityMap);
};

#endif
