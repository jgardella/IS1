#include "icosahedron.hh"
#include "plywriter.hh"

int main()
{
	Icosahedron* sphere = new Icosahedron(0, 0, 0);
	PlyWriter::write(*sphere, "ply/icosahedron.ply");
}
