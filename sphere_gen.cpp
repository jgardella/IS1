#include "icosahedron.hh"
#include <iostream>
#include <time.h>
#include <vector>
#include "plywriter.hh"

int main(int argc, const char* argv[])
{
	if(argc < 8)
	{
		std::cout << "usage: sphere_gen <numSpheres> <minX> <minY> <minZ> <maxX> <maxY> <maxZ> <resolution> <filename>\n";
	}
	else
	{
		std::srand(time(NULL));
		int i, x, y, z;
		int numSpheres = std::atoi(argv[1]);
		int minX = std::atoi(argv[2]);
		int minY = std::atoi(argv[3]);
		int minZ = std::atoi(argv[4]);
		int maxX = std::atoi(argv[5]);
		int maxY = std::atoi(argv[6]);
		int maxZ = std::atoi(argv[7]);
		int resolution = std::atoi(argv[8]);
		const char* filename = argv[9];
		std::vector<Shape>* spheres = new std::vector<Shape>();

		for(i = 0; i < numSpheres; i++)
		{
			x = std::rand() % (maxX - minX + 1) + minX;
			y = std::rand() % (maxY - minY + 1) + minY;
			z = std::rand() % (maxZ - minZ + 1) + minZ;

			spheres->push_back(*new Icosahedron(x, y, z, 1, resolution));
		}

		PlyWriter::writeShapes(spheres, filename);
	}
	return 0;
}
