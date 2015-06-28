#ifndef _DENSITYESTIMATOR_HH_
#define _DENSITYESTIMATOR_HH_

#include <map>
#include <vector>
#include <cfloat>
#include <utility>
#include "shape.hh"
#include "csvparser.hh"
#include "cube.hh"
#include "vertex.hh"
#include "util.hh"

class DensityEstimator
{
	public:
		// Calculates the density of points in the given csv file, using the given volume size.
		// Parameters:
		// std::string csvfile - the csv file to estimate density for
		// float subvolmeWidth - width of the subvolumes (in meters)
		// float resolution - spacing between the subvolume centers (in meters)
		// Returns a mapping from the center point of each volume used to the density estimate
		// for that volume.
		static std::pair<Vertex, float>*** estimate(std::string csvfile, float subvolumeWidth, float resolution, int& xSize, int& ySize, int& zSize);

	private:
		static float minX, maxX;
		static float minY, maxY;
		static float minZ, maxZ;

		static std::vector<Shape>* shapes;

		static void calculateDensityForSubvolume(Cube* subvolume, std::pair<Vertex, float>*** densityMap, int xIdx, int yIdx, int zIdx);
};

#endif
