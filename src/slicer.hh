#ifndef _SLICER_HH_
#define _SLICER_HH_

#include "shape.hh"
#include "util.hh"
#include "ImageFunctions.h"
#include <iostream>
#include <fstream>
#include <vector>

class Slicer
{
	public:
		static void writeSlices(std::vector<Shape*>* shapes, int pixelWidth, int pixelHeight,
				int sliceThickness, int numSlices, int imageWidth, int imageHeight,
				std::string outputDir, std::string filename);

	private:
		static unsigned char*** create3DGrid(int numslices, int imageWidth, int imageHeight);

		static void addSphereToGrid(Icosahedron* sphere, unsigned char*** grid,
				int numSlices, int imageWidth, int imageHeight,
				int sliceThickness, int pixelWidth, int pixelHeight);

		static void writeSlice(unsigned char** slice, int sliceNum, int imageWidth, int imageHeight, std::string outputDir, std::string filename);

};

#endif
