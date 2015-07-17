#include "MatrixParser.hh"

int main()
{
	int*** grid = MatrixParser::parseMatrixCSV("skeleton.csv", 682, 601, 400);
}
