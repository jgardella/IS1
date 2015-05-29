#include "csvparser.hh"
#include "shape.hh"
#include "plywriter.hh"
#include <iostream>
#include <vector>

int main(int argc, const char* argv [])
{
	if(argc < 3)
	{
		std::cout << "usage: ./test <csvfile> <plyfile>\n";
	}
	else
	{
		std::vector<Shape>* shapeList = CSVParser::parseCSV(argv[1]);
		PlyWriter::writeShapes(shapeList, argv[2]);
	}
	return 0;
}
