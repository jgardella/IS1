#include "slicer.hh"

void Slicer::writeSlices(std::vector<Shape*>* shapes, int pixelWidth, int pixelHeight,
		int sliceThickness, int numSlices, int imageWidth, int imageHeight,
		std::string outputDir, std::string filename)
{
	std::cout << "writeSlices entered.\n";
	unsigned int i;
	int j, k, l;

	unsigned char*** grid = create3DGrid(numSlices, imageWidth, imageHeight);
	std::cout << "Created 3D grid.\n";

	std::cout << "Setting occupied parts of grid.\n";
	// set occupied parts of grid based on shape list
	for(i = 0; (unsigned int) i < shapes->size(); i++)
	{
		Icosahedron* s = (Icosahedron*) shapes->at(i); // assume all spheres
		addSphereToGrid(s, grid, numSlices, imageWidth, imageHeight, sliceThickness, pixelWidth, pixelHeight);
	}

	std::cout << "Writing slices to disk.\n";
	// write slice images to disk
	for(j = 0; j < numSlices; j++)
	{
		std::cout << "Writing slice " << j << " to disk.\n";
		writeSlice(grid[j], j, imageWidth, imageHeight, outputDir, filename);
	}
	std::cout << "Finished writing slices.\n";

	for(j = 0; j < numSlices; j++)
	{
		for(k = 0; k < pixelWidth; k++)
		{
			delete[] grid[j][k];
		}

		delete[] grid[j];
	}
	delete[] grid;
}

unsigned char*** Slicer::create3DGrid(int numSlices, int imageWidth, int imageHeight)
{
	unsigned char*** grid = new unsigned char**[numSlices];

	int i, j, k;

	// initialize grid
	for(i = 0; i < numSlices; i++)
	{
		grid[i] = new unsigned char*[imageWidth];

		for(j = 0; j < imageWidth; j++)
		{
			grid[i][j] = new unsigned char[imageHeight];

			for(k = 0; k < imageHeight; k++)
			{
				grid[i][j][k] = 0;
			}
		}
	}

	return grid;
}

void Slicer::addSphereToGrid(Icosahedron* sphere, unsigned char*** grid,
		int numSlices, int imageWidth, int imageHeight,
		int sliceThickness, int pixelWidth, int pixelHeight)
{
	float x, y, z;

	float sphereMinX, sphereMinY, sphereMinZ;
	float sphereMaxX, sphereMaxY, sphereMaxZ;

	Util::calculateSphereBoundingBox(*sphere, sphereMinX, sphereMinY, sphereMinZ,
			sphereMaxX, sphereMaxY, sphereMaxZ);

	for(x = sphereMinX; x <= sphereMaxX; x += pixelWidth)
	{
		for(y = sphereMinY; y <= sphereMaxY; y += pixelHeight)
		{
			for(z = sphereMinZ; z <= sphereMaxZ; z += sliceThickness)
			{
				if(sphere->contains(x, y, z))
				{
					// if sphere contains the given point, set it as occupied in the grid
					grid[(int) z / sliceThickness][(int) x / pixelWidth][(int) y / pixelHeight] = 255;
				}
			}
		}
	}

}

void Slicer::writeSlice(unsigned char** slice, int sliceNum, int imageWidth, int imageHeight, std::string outputDir, std::string filename)
{
	int i, j;
	char* fname = (char*) (outputDir + "/" + filename + std::to_string(sliceNum)).c_str();

	// convert slice to 1d array
	unsigned char* image = new unsigned char[imageWidth * imageHeight * 3];

	for(i = 0; i < imageHeight; i++)
	{
		for(j = 0; j < imageWidth; j++)
		{
			image[3 * (j * imageWidth + i)] = slice[i][j];
			image[3 * (j * imageWidth + i) + 1] = slice[i][j];
			image[3 * (j * imageWidth + i) + 2] = slice[i][j];
		}
	}

	write_pgm_Uimage(image, fname, imageWidth, imageHeight);
}