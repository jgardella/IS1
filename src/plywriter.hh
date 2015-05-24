#ifndef PLYWRITER_HH_
#define _PLYWRITER_HH_

#include "shape.hh"
#include "vertex.hh"
#include "tface.hh"
#include <iostream>
#include <fstream>
#include <string>

class PlyWriter
{
	public:

		// Writes the given shape in .ply format to the given file path.
		// Parameters:
		// Shape shape - the shape to write to disk
		// std::string outputPath - path to save shape to
		static void write(Shape& shape, std::string outputPath);

	private:

		static void writeHeader(Shape& shape, std::ofstream& file);
		static void writeVertices(Shape& shape, std::ofstream& file);
		static void writeFaces(Shape& shape, std::ofstream& file);
};

#endif
