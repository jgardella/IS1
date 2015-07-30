#include "slicer.hh"
#include "csvparser.hh"
#include <iostream>
#include <vector>

int main(int argc, const char* argv [])
{
	if(argc < 10)
	{
		std::cout << "usage: ./test <csvfile> <pixelWidth> <pixelHeight> <sliceThickness> <numSlices> <imageWidth> <imageHeight> <outputDir> <fileName>\n";
	}
	else
	{
		std::string csvFile = argv[1];
		int pixelWidth = std::atoi(argv[2]);
		int pixelHeight = std::atoi(argv[3]);
		int sliceThickness = std::atoi(argv[4]);
		int numSlices = std::atoi(argv[5]);
		int imageWidth = std::atoi(argv[6]);
		int imageHeight = std::atoi(argv[7]);
		std::string outputDir = argv[8];
		std::string filename = argv[9];

		std::vector<Shape*>* shapeList = CSVParser::parseCSV(argv[1], 3, -1, -1, -1);
		Slicer::writeSlices(shapeList, pixelWidth, pixelHeight,
				sliceThickness, numSlices, imageWidth, imageHeight,
				outputDir, filename);
	}
}
