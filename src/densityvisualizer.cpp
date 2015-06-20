#include "densityvisualizer.hh"

Shape* DensityVisualizer::pointCloud;
float DensityVisualizer::threshold;
std::map<Vertex, float, CmpVertex>* DensityVisualizer::densityMap;

Shape* DensityVisualizer::thresholdDensity(std::map<Vertex, float, CmpVertex>* densityMap, float threshold, float subvolumeWidth)
{
	pointCloud = new Shape(0, 0, 0);
	DensityVisualizer::threshold = threshold;
	DensityVisualizer::densityMap = densityMap;

	for(auto iter : *densityMap)
	{
		Vertex vertex = iter.first;

		std::map<Vertex, float, CmpVertex>::iterator it = densityMap->find(Vertex(vertex.x, vertex.y, vertex.z + subvolumeWidth));
		addPointIfValid(iter, it);

		it = densityMap->find(Vertex(vertex.x, vertex.y, vertex.z - subvolumeWidth));
		addPointIfValid(iter, it);

		it = densityMap->find(Vertex(vertex.x, vertex.y + subvolumeWidth, vertex.z));
		addPointIfValid(iter, it);

		it = densityMap->find(Vertex(vertex.x, vertex.y - subvolumeWidth, vertex.z));
		addPointIfValid(iter, it);

		it = densityMap->find(Vertex(vertex.x + subvolumeWidth, vertex.y, vertex.z));
		addPointIfValid(iter, it);

		it = densityMap->find(Vertex(vertex.x - subvolumeWidth, vertex.y, vertex.z));
		addPointIfValid(iter, it);
	}

	return pointCloud;
}

void DensityVisualizer::addPointIfValid(std::pair<Vertex, float> i1, std::map<Vertex, float, CmpVertex>::iterator i2)
{
	if(i2 != densityMap->end())
	{
		std::cout << "Valid\n";
		if((i1.second < threshold && i2->second > threshold) || (i1.second > threshold && i2->second < threshold))
		{
			std::cout << "On threshold\n";
			pointCloud->addVertex(*(new Vertex(i1.first, (Vertex&)i2->first)), true);
		}
	}
}
