#include "slicer.hh"

void Slicer::writeSlices(std::vector<Shape*>* shapes, int pixelWidth, int pixelHeight,
		int sliceThickness, int numSlices, int imageWidth, int imageHeight,
		std::string outputDir, std::string filename)
{
	unsigned int i;

	unsigned char*** grid = create3DGrid(numSlices, imageWidth, imageHeight);

	// set occupied parts of grid based on shape list
	for(i = 0; i < shapes->size(); i++)
	{
		Icosahedron* s = (Icosahedron*) shapes->at(i); // assume all spheres
		addSphereToGrid(s, grid, numSlices, imageWidth, imageHeight, sliceThickness, pixelWidth, pixelHeight);
	}

	// write slice images to disk
	for(i = 0; i < numSlices; i++)
	{

	}
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
				}
			}
		}
	}

}
