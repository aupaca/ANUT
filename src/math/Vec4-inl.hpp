#include "math/neon.h"
#include "math/Mat4.h"

namespace anut
{
// members
inline Vec4& Vec4::operator=(const Vec4& other)
{
	anut::storeVec4(&v[0], &other.v[0]);
	return *this;
}

inline Vec4& Vec4::operator=(const float vec[4])
{
	anut::storeVec4(&v[0], &vec[0]);
	return *this;
}

inline Vec4& Vec4::operator+=(const Vec4& other)
{
	anut::addVec4(&v[0], &v[0], &other.v[0]);
	return *this;
}

inline Vec4& Vec4::operator*=(const Vec4& other)
{
	anut::mulVec4(&v[0], &v[0], &other.v[0]);
	return *this;
}

inline Vec4& Vec4::operator*=(const Mat4& mat)
{
	for (int i = 0; i < 4; i++)
	{
		anut::dotVec4(&v[i], &v[0], (float*) &mat.m[i]);
	}
	return *this;
}

inline Vec4& Vec4::operator*=(float s)
{
	anut::scaleVec4(&v[0], &v[0], s);
	return *this;
}

inline Vec4& Vec4::operator/=(float s)
{
	anut::scaleVec4(&v[0], &v[0], 1.f/s);
	return *this;
}

// not members
inline Vec4 operator+(const Vec4& a, const Vec4& b)
{
	Vec4 result;
	anut::addVec4(&result.v[0], &a.v[0], &b.v[0]);
	return result;
}

inline Vec4 operator-(const Vec4& a, const Vec4& b)
{
	Vec4 result;
	anut::subVec4(&result.v[0], &a.v[0], &b.v[0]);
	return result;
}

inline Vec4 operator*(const Vec4& a, const Vec4& b)
{
	Vec4 result;
	anut::mulVec4(&result.v[0], &a.v[0], &b.v[0]);
	return result;
}

inline Vec4 operator*(const Vec4& vec, float s)
{
	Vec4 result;
	anut::scaleVec4(&result.v[0], &vec.v[0], s);
	return result;
}

inline Vec4 operator*(float s, const Vec4& vec)
{
	Vec4 result;
	anut::scaleVec4(&result.v[0], &vec.v[0], s);
	return result;
}

} // anut namespace

