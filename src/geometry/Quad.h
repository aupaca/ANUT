#if not defined(ANUT_QUAD_H)
#define ANUT_QUAD_H
#include "geometry/Mesh.h"
#include <vector>

namespace anut
{
class Quad : public anut::Mesh
{
public:
	static constexpr int VERTEX_COUNT = 8;
	static constexpr int FACE_COUNT = 6;
	static constexpr int INDEX_PER_FACE = 6;
	static constexpr int INDEX_COUNT = FACE_COUNT * INDEX_PER_FACE;
	
	Quad(float w, float h, float d);
	
	void resize(float w, float h, float d);
	
	float getWidth();
	float getHeight();
	float getDepth();
	
private:
	static anut::Mesh _cubeMesh;
	
	void loadCubeMesh();
	
	float _width;
	float _height;
	float _depth;
};

inline float Quad::getWidth()
{
	return _width;
}

inline float Quad::getHeight()
{
	return _height;
}

inline float Quad::getDepth()
{
	return _depth;
}

} // anut namespace

#endif

