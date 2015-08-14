#include "MatrixParser.hh"
#include "shape.hh"
#include "plywriter.hh"

int main(int argc, const char* argv [])
{
    if(argc < 9)
    {
        std::cout << "usage: skel_csvtoply <csvfile> <plyfile> <xDim> <yDim> <zDim> <r> <g> <b>\n";
    }
    else
    {
        std::string csvfile = argv[1];
        std::string plyfile = argv[2];
        int xDim = std::atoi(argv[3]);
        int yDim = std::atoi(argv[4]);
        int zDim = std::atoi(argv[5]);
        int r = std::atoi(argv[6]);
        int g = std::atoi(argv[7]);
        int b = std::atoi(argv[8]);

        if(argc == 9)
        {
            int i, j, k;
            bool*** grid = MatrixParser::parseMatrixCSV(csvfile, xDim, yDim, zDim);
            Shape* shape = new Shape(0, 0, 0, r, g, b);
            for(i = 0; i < xDim; i++)
            {
                for(j = 0; j < yDim; j++)
                {
                    for(k = 0; k < zDim; k++)
                    {
                        if(grid[i][j][k] != 0)
                        {
                            shape->addVertex(*new Vertex(i, j, k), true);
                        }
                    }
                }
            }

            PlyWriter::write(*shape, plyfile, true);
        }
        else if(argc >= 13)
        {
            float origX = std::atof(argv[9]);
            float origY = std::atof(argv[10]);
            float origZ = std::atof(argv[11]);
            float scalingFactor = std::atof(argv[12]);

            int i, j, k;
            bool*** grid = MatrixParser::parseMatrixCSV(csvfile, xDim, yDim, zDim);
            Shape* shape = new Shape(origX, origY, origZ, r, g, b);
            for(i = 0; i < xDim; i++)
            {
                for(j = 0; j < yDim; j++)
                {
                    for(k = 0; k < zDim; k++)
                    {
                        if(grid[i][j][k] != 0)
                        {
                            shape->addVertex(*new Vertex(i * scalingFactor, j * scalingFactor, k * scalingFactor), false);
                        }
                    }
                }
            }

            PlyWriter::write(*shape, plyfile, true);
        }
        else
        {
            std::cout << "usage: skel_csvtoply <csvfile> <plyfile> <xDim> <yDim> <zDim> <r> <g> <b> <origX> <origY> <origZ> <scalingFactor>\n";
        }
    }
}
