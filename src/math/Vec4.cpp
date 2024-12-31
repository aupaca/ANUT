#include "math/Vec4.h"
#include "math/neon.h"
#include <cmath>

namespace anut
{
Vec4::Vec4(const Vec4& other)
{
	anut::storeVec4(&v[0], &other.v[0]);
}

Vec4::Vec4(const float vec[4])
{
	anut::storeVec4(&v[0], &vec[0]);
}

Vec4::Vec4(float x1, float x2, float x3, float x4)
{
	x = x1;
	y = x2;
	z = x3;
	w = x4;
}

float Vec4::computeLength()
{
	return sqrtf(x + y + z + w);
}

} // anut namespace
