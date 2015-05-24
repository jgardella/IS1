#ifndef _TFACE_HH_
#define _TFACE_HH_

class TFace
{

	public:

		// Defines a face with the given vertex indicies.
		// Parameters:
		// int v1Idx - index of vertex 1 in associated shape's vertex list
		// int v2Idx - index of vertex 2 in associated shape's vertex list
		// int v3Idx - index of vertex 3 in associated shape's vertex list
		TFace(int v1Idx, int v2Idx, int v3Idx);

		int v1Idx;
		int v2Idx;
		int v3Idx;

};

#endif
