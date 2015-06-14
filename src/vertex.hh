#ifndef _VERTEX_HH_
#define _VERTEX_HH_

class Vertex
{
	public:

		// Defines a vertex with the given coordinates.
		// Parameters:
		// float x - x coordinate of vertex
		// float y - y coordinate of vertex
		// flaot z - z coordinate of vertex
		Vertex(float x, float y, float z);

		float x;
		float y;
		float z;

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
