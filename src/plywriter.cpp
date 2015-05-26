#include "plywriter.hh"

void PlyWriter::write(Shape& shape, std::string outputPath)
{
	std::ofstream plyfile(outputPath);
	if(plyfile.is_open())
	{
		writeHeader(shape, plyfile);
		writeVertices(shape, plyfile);
		writeFaces(shape, plyfile);
		plyfile.close();
	}
}

void PlyWriter::writeShapes(std::vector<Shape>* shapes, std::string outputPath)
{
	unsigned int i;
	std::ofstream plyfile(outputPath);
	if(plyfile.is_open())
	{
		writeShapesHeader(shapes, plyfile);
		for(i = 0; i < shapes->size(); i++)
		{
			writeVertices(shapes->at(i), plyfile);
		}
		for(i = 0; i < shapes->size(); i++)
		{
			writeFaces(shapes->at(i), plyfile);
		}
		plyfile.close();
	}
}

void PlyWriter::writeHeader(Shape& shape, std::ofstream& file)
{
	file << "ply\n";
	file << "format ascii 1.0\n";
	file << "element vertex " + std::to_string(shape.getVertices()->size()) + "\n";
	file << "property float x\n";
	file << "property float y\n";
	file << "property float z\n";
	file << "element face " + std::to_string(shape.getFaces()->size()) + "\n";
	file << "property list uchar int vertex_indices\n";
	file << "end_header\n";
}

void PlyWriter::writeShapesHeader(std::vector<Shape>* shapes, std::ofstream& file)
{
	unsigned int i;
	int numFaces = 0;
	int numVertices = 0;
	for(i = 0; i < shapes->size(); i++)
	{
		numFaces += shapes->at(i).getFaces()->size();
		numVertices += shapes->at(i).getVertices()->size();
	}

	file << "ply\n";
	file << "format ascii 1.0\n";
	file << "element vertex " + std::to_string(numVertices) + "\n";
	file << "property float x\n";
	file << "property float y\n";
	file << "property float z\n";
	file << "element face " + std::to_string(numFaces) + "\n";
	file << "property list uchar int vertex_indices\n";
	file << "end_header\n";
}

void PlyWriter::writeVertices(Shape& shape, std::ofstream& file)
{
	std::vector<Vertex>* vertices = shape.getVertices();
	for(unsigned int i = 0; i < vertices->size(); i++)
	{
		Vertex v = vertices->at(i);
		file << std::to_string(v.x) + " " + std::to_string(v.y) + " " + std::to_string(v.z) + "\n";
	}
}

void PlyWriter::writeFaces(Shape& shape, std::ofstream& file)
{
	std::vector<TFace>* faces = shape.getFaces();
	for(unsigned int i = 0; i < faces->size(); i++)
	{
		TFace f = faces->at(i);
		file << "3 " + std::to_string(f.v1Idx) + " " + std::to_string(f.v2Idx) + " " + std::to_string(f.v3Idx) + "\n";
	}
}
