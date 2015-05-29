#ifndef _CSVPARSER_HH_
#define _CSVPARSER_HH_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "shape.hh"
#include "icosahedron.hh"

class CSVParser
{
	public:
		static std::vector<Shape>* parseCSV(std::string filename);
};

#endif
