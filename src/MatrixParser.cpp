#include "MatrixParser.hh"

int*** MatrixParser::parseMatrixCSV(std::string csvName, int xSize, int ySize, int zSize)
{
	int i, j, k;
	int*** grid = new int**[xSize];

	for(i = 0; i < xSize; i++)
	{
		grid[i] = new int*[ySize];

		for(j = 0; j < ySize; j++)
		{
			grid[i][j] = new int[zSize];

			for(k = 0; k < zSize; k++)
			{
				grid[i][j][k] = 0;
			}
		}
	}

	std::ifstream file(csvName);
	std::string line;
	i = 0;
	while(std::getline(file, line))
	{
		std::istringstream s(line);
		std::string num;
		int cellVal;
		j = 0;
		k = 0;
		while(std::getline(s, num, ','))
		{
			cellVal = std::atoi(num.c_str());
			grid[i][j][k] = cellVal;

			// increment
			if(j < ySize - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				k++;
			}

		}
		i++;
	}

	return grid;
}
