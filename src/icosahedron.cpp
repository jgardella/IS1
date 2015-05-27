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
	addTFace(0, 11, 5);
	addTFace(0, 5, 1);
	addTFace(0, 1, 7);
	addTFace(0, 7, 10);
	addTFace(0, 10, 11);

	// 5 adjacent faces
	addTFace(1, 5, 9);
	addTFace(5, 11, 4);
	addTFace(11, 10, 2);
	addTFace(10, 7, 6);
	addTFace(7, 1, 8);

	// 5 faces around point 3
	addTFace(3, 9, 4);
	addTFace(3, 4, 2);
	addTFace(3, 2, 6);
	addTFace(3, 6, 8);
	addTFace(3, 8, 9);

	// 5 adjacent faces
	addTFace(4, 9, 5);
	addTFace(2, 4, 11);
	addTFace(6, 2, 10);
	addTFace(8, 6, 7);
	addTFace(9, 8, 1);
}
