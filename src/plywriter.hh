#ifndef PLYWRITER_HH_
#define _PLYWRITER_HH_

#include "shape.hh"
#include "vertex.hh"
#include "tface.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class PlyWriter
{
	public:

		// Writes the given shape in .ply format to the given file path.
		// Parameters:
		// Shape shape - the shape to write to disk
		// std::string outputPath - path to save shape to
		static void write(Shape& shape, std::string outputPath);

		// Writes the given list of shapes in .ply format to the given file path.
		// Parameters:
		// std::vector<Shape> shapes - list of shapes to write to disk
		// std::string outputPath - path to save shapes to
		static void writeShapes(std::vector<Shape*>* shapes, std::string outputPath);

	private:

		static void writeHeader(Shape& shape, std::ofstream& file);
		static void writeShapesHeader(std::vector<Shape*>* shapes, std::ofstream& file);

		static void writeVertices(Shape& shape, std::ofstream& file);
		static void writeFaces(Shape& shape, std::ofstream& file, int offset);
};

#endif
