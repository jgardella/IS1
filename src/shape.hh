#ifndef _SHAPE_HH_
#define _SHAPE_HH_

#include <vector>
#include "vertex.hh"
#include "tface.hh"

class Shape
{
	public:

		// Constructs a shape with the given center coordinates (x, y).
		// Parameters:
		// float x - x coordinate of shape center
		// float y - y coordinate of shape center
		// float z - z coordinate of shape center
		Shape(float x, float y, float z);

		// Constructs a shape with the given center coordinates (x, y).
		// Parameters:
		// float x - x coordinate of shape center
		// float y - y coordinate of shape center
		// float z - z coordinate of shape center
		Shape(float x, float y, float z, unsigned char r, unsigned char g, unsigned char b);

		// Adds the given vertex to the shape. If absolute is true, the vertices coordinates will be interpreted
		// as being in absolute space. If false, they will be interpreted as relative to the shape's (x, y) coordinates.
		// Parameters:
		// vertex v - vertex to add
		// bool absolute - if true, v's coordinates are considered absolute, otherwise they are relative to shape
		int addVertex(Vertex& v, bool absolute);

		// Adds a triangulare face composed of the given three vertices to the shape.
		// Parameters:
		// int v1Idx - index of vertex 1 in shape's vertex list
		// int v2Idx - index of vertex 2 in shape's vertex list
		// int v3Idx - index of vertex 3 in shape's vertex list
		void addTFace(int v1Idx, int v2Idx, int v3Idx);

		std::vector<Vertex>* getVertices();

		std::vector<TFace>* getFaces();

		void setFaces(std::vector<TFace>* faces);

		int getId();

		float getX();
		float getY();
		float getZ();

		unsigned char getR();
		unsigned char getG();
		unsigned char getB();

	protected:
		float x;
		float y;
		float z;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		int id;
		static int shapeId;
		std::vector<Vertex>* vertices;
		std::vector<TFace>* faces;

};

#endif
