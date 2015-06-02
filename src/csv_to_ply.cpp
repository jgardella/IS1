#include "csvparser.hh"
#include "shape.hh"
#include "plywriter.hh"
#include <iostream>
#include <vector>

int main(int argc, const char* argv [])
{
	if(argc < 4)
	{
		std::cout << "usage: ./test <csvfile> <plyfile> <resolution> <minR> <maxR> <radius>\n";
	}
	else
	{
		std::vector<Shape>* shapeList = CSVParser::parseCSV(argv[1], std::atoi(argv[3]), std::atof(argv[4]), std::atof(argv[5]), std::atof(argv[6]));
		PlyWriter::writeShapes(shapeList, argv[2]);
	}
	return 0;
}
