#include "csvparser.hh"

std::vector<Shape>* CSVParser::parseCSV(std::string filename)
{
	std::ifstream file(filename);
	std::string line;
	int i;
	float x, y, z;
	std::vector<Shape>* shapeList = new std::vector<Shape>();
	// read line
	while(std::getline(file, line))
	{
		// split line on ',', we are only concerned with fifth, sixth, seventh columns
		std::istringstream s(line);
		std::string field;
		i = 0;
		while(std::getline(s, field, ','))
		{
			if(i == 4)
			{
				x = std::stof(field);
			}
			else if(i == 5)
			{
				y = std::stof(field);
			}
			else if(i == 6)
			{
				z = std::stof(field);
			}
			i++;
		}
		shapeList->push_back(*new Icosahedron(x, y, z, 0));
	}
	return shapeList;
}
