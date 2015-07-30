#include "plywriter.hh"

void PlyWriter::write(Shape& shape, std::string outputPath, bool color)
{
	std::ofstream plyfile(outputPath);
	if(plyfile.is_open())
	{
		writeHeader(shape, plyfile, color);
		writeVertices(shape, plyfile, color);
		writeFaces(shape, plyfile, 0);
		plyfile.close();
	}
}

void PlyWriter::writeShapes(std::vector<Shape*>* shapes, std::string outputPath)
{
	unsigned int i;
	std::ofstream plyfile(outputPath);
	if(plyfile.is_open())
	{
		writeShapesHeader(shapes, plyfile);
		for(i = 0; i < shapes->size(); i++)
		{
			writeVertices(*shapes->at(i), plyfile, false);
		}
		int offset = 0;
		for(i = 0; i < shapes->size(); i++)
		{
			writeFaces(*shapes->at(i), plyfile, offset);
			offset += shapes->at(i)->getVertices()->size();
		}
		plyfile.close();
	}
}

void PlyWriter::writeHeader(Shape& shape, std::ofstream& file, bool color)
{
	file << "ply\n";
	file << "format ascii 1.0\n";
	file << "element vertex " + std::to_string(shape.getVertices()->size()) + "\n";
	file << "property float x\n";
	file << "property float y\n";
	file << "property float z\n";
	if(shape.getVertices()->size() > 0 && shape.getVertices()->at(0).hasNormals) // add normal component properties if shape contains normals
	{
		file << "property float nx\n";
		file << "property float ny\n";
		file << "property float nz\n";
	}
	if(color)
	{
		file << "property uchar red\n";
		file << "property uchar green\n";
		file << "property uchar blue\n";
	}
	file << "element face " + std::to_string(shape.getFaces()->size()) + "\n";
	file << "property list uchar int vertex_indices\n";
	file << "end_header\n";
}

void PlyWriter::writeShapesHeader(std::vector<Shape*>* shapes, std::ofstream& file)
{
	unsigned int i;
	int numFaces = 0;
	int numVertices = 0;
	for(i = 0; i < shapes->size(); i++)
	{
		numFaces += shapes->at(i)->getFaces()->size();
		numVertices += shapes->at(i)->getVertices()->size();
	}

	file << "ply\n";
	file << "format ascii 1.0\n";
	file << "element vertex " + std::to_string(numVertices) + "\n";
	file << "property float x\n";
	file << "property float y\n";
	file << "property float z\n";
	if(shapes->at(0)->getVertices()->size() > 0 && shapes->at(0)->getVertices()->at(0).hasNormals) // add normal component properties if shape contains normals
	{
		file << "property float nx\n";
		file << "property float ny\n";
		file << "property float nz\n";
	}
	file << "element face " + std::to_string(numFaces) + "\n";
	file << "property list uchar int vertex_indices\n";
	file << "end_header\n";
}

void PlyWriter::writeVertices(Shape& shape, std::ofstream& file, bool color)
{
	std::vector<Vertex>* vertices = shape.getVertices();
	for(unsigned int i = 0; i < vertices->size(); i++)
	{
		Vertex v = vertices->at(i);
		file << std::to_string(v.x) + " " + std::to_string(v.y) + " " + std::to_string(v.z);
		if(v.hasNormals) // write normal components if vertex has them
		{
			file << " " << std::to_string(v.nx) << " " << std::to_string(v.ny) << " " << std::to_string(v.nz);
		}
		if(color)
		{
			file << " " << std::to_string(shape.getR()) << " " << std::to_string(shape.getG()) << " " << std::to_string(shape.getB());
		}
		file << '\n';
	}
}

void PlyWriter::writeFaces(Shape& shape, std::ofstream& file, int offset)
{
	std::vector<TFace>* faces = shape.getFaces();
	for(unsigned int i = 0; i < faces->size(); i++)
	{
		TFace f = faces->at(i);
		file << "3 " + std::to_string(f.v1Idx + offset) + " " + std::to_string(f.v2Idx + offset) + " " + std::to_string(f.v3Idx + offset) + "\n";
	}
}
