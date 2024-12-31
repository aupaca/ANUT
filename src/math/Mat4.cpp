#include "math/Mat4.h"
#include "math/neon.h"

namespace anut
{
	Mat4::Mat4()
	{
		
	}
	
	Mat4::Mat4(float column1[4], float column2[4], float column3[4], float column4[4])
	{
		anut::storeVec4((float*) &m[0], &column1[0]);
		anut::storeVec4((float*) &m[1], &column2[0]);
		anut::storeVec4((float*) &m[2], &column3[0]);
		anut::storeVec4((float*) &m[3], &column4[0]);
	}
}
