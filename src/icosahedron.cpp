#include "icosahedron.hh"

Icosahedron::Icosahedron(float x, float y, float z) : Shape(x, y, z)
{
	// add vertices
	float t = (1.0 + std::sqrt(5.0)) / 2.0;

	addVertex(*new Vertex(-1,  t,  0), false);
	addVertex(*new Vertex( 1,  t,  0), false);
	addVertex(*new Vertex(-1, -t,  0), false);
	addVertex(*new Vertex( 1, -t,  0), false);

	addVertex(*new Vertex( 0, -1,  t), false);
	addVertex(*new Vertex( 0,  1,  t), false);
	addVertex(*new Vertex( 0, -1, -t), false);
	addVertex(*new Vertex( 0,  1, -t), false);

	addVertex(*new Vertex( t,  0, -1), false);
	addVertex(*new Vertex( t,  0,  1), false);
	addVertex(*new Vertex(-t,  0, -1), false);
	addVertex(*new Vertex(-t,  0,  1), false);

	// add faces
	// 5 faces around point 0
	addTFace(0 + (getId() * 12), 11 + (getId() * 12), 5 + (getId() * 12));
	addTFace(0 + (getId() * 12), 5 + (getId() * 12), 1 + (getId() * 12));
	addTFace(0 + (getId() * 12), 1 + (getId() * 12), 7 + (getId() * 12));
	addTFace(0 + (getId() * 12), 7 + (getId() * 12), 10 + (getId() * 12));
	addTFace(0 + (getId() * 12), 10 + (getId() * 12), 11 + (getId() * 12));

	// 5 adjacent faces
	addTFace(1 + (getId() * 12), 5 + (getId() * 12), 9 + (getId() * 12));
	addTFace(5 + (getId() * 12), 11 + (getId() * 12), 4 + (getId() * 12));
	addTFace(11 + (getId() * 12), 10 + (getId() * 12), 2 + (getId() * 12));
	addTFace(10 + (getId() * 12), 7 + (getId() * 12), 6 + (getId() * 12));
	addTFace(7 + (getId() * 12), 1 + (getId() * 12), 8 + (getId() * 12));

	// 5 faces around point 3
	addTFace(3 + (getId() * 12), 9 + (getId() * 12), 4 + (getId() * 12));
	addTFace(3 + (getId() * 12), 4 + (getId() * 12), 2 + (getId() * 12));
	addTFace(3 + (getId() * 12), 2 + (getId() * 12), 6 + (getId() * 12));
	addTFace(3 + (getId() * 12), 6 + (getId() * 12), 8 + (getId() * 12));
	addTFace(3 + (getId() * 12), 8 + (getId() * 12), 9 + (getId() * 12));

	// 5 adjacent faces
	addTFace(4 + (getId() * 12), 9 + (getId() * 12), 5 + (getId() * 12));
	addTFace(2 + (getId() * 12), 4 + (getId() * 12), 11 + (getId() * 12));
	addTFace(6 + (getId() * 12), 2 + (getId() * 12), 10 + (getId() * 12));
	addTFace(8 + (getId() * 12), 6 + (getId() * 12), 7 + (getId() * 12));
	addTFace(9 + (getId() * 12), 8 + (getId() * 12), 1 + (getId() * 12));
}
