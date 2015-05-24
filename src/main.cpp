#include "shape.hh"
#include "plywriter.hh"

int main()
{
	Shape* shape = new Shape(0, 0, 0);
	shape->addVertex(*new Vertex(1, 1, 1), true);
	shape->addVertex(*new Vertex(1, -1, -1), true);
	shape->addVertex(*new Vertex(-1, 1, -1), true);
	shape->addVertex(*new Vertex(-1, -1, 1), true);
	shape->addTFace(0, 1, 2);
	shape->addTFace(0, 1, 3);
	shape->addTFace(1, 2, 3);
	shape->addTFace(0, 2, 3);
	PlyWriter::write(*shape, "ply/tetrahedron.ply");
}
