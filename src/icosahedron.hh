#ifndef _ICOSAHEDRON_HH_
#define _ICOSAHEDRON_HH_

#include <iostream>
#include "shape.hh"
#include <cmath>
#include <map>

class Icosahedron : public Shape
{
	public:

		Icosahedron(float x, float y, float z, float radius, int resolution);

		float getRadius();

		bool contains(float x, float y, float z);

		bool intersectsCube(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

	private:
		std::map<std::pair<int, int>, int>* refinementMap;
		float radius;

		// Creates the middle point between the two vertices if it hasn't already been created. Used for refinement.
		// Parameters:
		// int v1Idx - index of first vertex
		// int v2Idx - index of second vertex
		// Returns: index of added vertex, or if middle point was already calculated, the index of the already calculated vertex
		int createMiddlePoint(int v1Idx, int v2Idx);

		// Adds the given vertex to the icosahedron shape, normalizing it to the unit circle.
		// Parameters:
		// Vertex v - vertex to add, must be in relative coordinates
		// Returns: index of the added vertex
		int addVertex(Vertex& v);

};

#endif
