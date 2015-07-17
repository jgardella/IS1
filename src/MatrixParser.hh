#ifndef _MATRIXPARSER_HH_
#define _MATRIXPARSER_HH_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


class MatrixParser
{
	public:

		static int*** parseMatrixCSV(std::string csvName, int xSize, int ySize, int zSize);

};

#endif
