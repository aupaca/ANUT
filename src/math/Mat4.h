#if not defined(ANUT_MAT4_H)
#define ANUT_MAT4_H

namespace anut
{
class Vec4;

struct Mat4
{
	union
	{
		float v[16];
		float m[4][4];
		
		struct
		{
			float col0[4];
			float col1[4];
			float col2[4];
			float col3[4];
		};
	};
	
	Mat4();
	Mat4(float column1[4], float column2[4], float column3[4], float column4[4]);
};

} // namespace anut

#include "math/Mat4-inl.hpp"

#endif
