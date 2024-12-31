#if not defined(ANUT_VERTEX_H)
#define ANUT_VERTEX_H
#include "math/vec4.h"

namespace anut
{
struct Vertex
{
	anut::Vec4 pos;
	anut::Vec4 normal;
	//anut::Vec4 texCoord;
};

} // anut namespace

#endif
