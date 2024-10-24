#if not defined(ANUT_VEC4_H)
#define ANUT_VEC4_H

namespace anut
{
	class Mat4;
	class Vec4;
	
//	Vec4 normalize(const);
	
	struct Vec4
	{
		union
		{
			float v[4];
			
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			
			struct 
			{
				float r;
				float g;
				float b;
				float a;
			};
		};
		
		Vec4() = default;
		Vec4(const Vec4& other);
		Vec4(const float vec[4]);
		Vec4(float x1, float x2, float x3, float x4 = 0.f);
		
		float computeLength();
		
		Vec4& operator=(const Vec4& other);
		Vec4& operator=(const float vec[4]);
		Vec4& operator+=(const Vec4& other);
		Vec4& operator*=(const Vec4& other);
		Vec4& operator*=(const Mat4& mat);
		Vec4& operator*=(float s);
		Vec4& operator/=(float s);
	};
} // namespace anut

#include "math/Vec4-inl.hpp"

#endif
