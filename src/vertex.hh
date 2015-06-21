#ifndef _VERTEX_HH_
#define _VERTEX_HH_

class Vertex
{
	public:

		Vertex();

		// Defines a vertex with the given coordinates.
		// Parameters:
		// float x - x coordinate of vertex
		// float y - y coordinate of vertex
		// float z - z coordinate of vertex
		Vertex(float x, float y, float z);

		// Defines a vertex with the given coordinates and normal.
		// Parameters:
		// float x - x coordinate of vertex
		// float y - y coordinate of vertex
		// float z - z coordinate of vertex
		// float nx - x component of normal
		// float ny - y component of normal
		// float nz - z component of normal
		Vertex(float x, float y, float z, float nx, float ny, float nz);

		// Defines a new vertex that is the midpoint of the given vertices.
		// Parameters:
		// Vertex& v1 - the first vertex
		// Vertex& v2 - the second vertex
		Vertex(Vertex& v1, Vertex& v2);

		bool hasNormals;
		float x;
		float y;
		float z;

		float nx;
		float ny;
		float nz;

};

struct CmpVertex
{
	bool operator()(Vertex const& lhs, Vertex const& rhs) const
	{
		if(lhs.x < rhs.x)
			return false;
		else if(lhs.x > rhs.x)
			return true;
		if(lhs.y < rhs.y)
			return false;
		else if(lhs.y > rhs.y)
			return true;
		if(lhs.z < rhs.z)
			return false;
		else if(lhs.z > rhs.z)
			return true;
		return true;
	}
};

#endif
