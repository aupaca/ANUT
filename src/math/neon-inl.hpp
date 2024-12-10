#include <arm_neon.h>

// TODO: implement dotVec4 with arm neon

namespace anut
{
inline void storeVec4(float* dest, const float* source)
{
	float32x4_t q = vld1q_f32(source);
	vst1q_f32(dest, q);
}

inline void storeVec2(float* dest, const float* source)
{
	float32x2_t d = vld1_f32(source);
	vst1_f32(dest, d);
}

inline void addVec4(float* dest, const float* a, const float* b)
{
	float32x4_t q1 = vld1q_f32(a);
	float32x4_t q2 = vld1q_f32(b);
	q1 = vaddq_f32(q1, q2);
	vst1q_f32(dest, q1);
}

inline void addVec2(float* dest, const float* a, const float* b)
{
	float32x2_t d1 = vld1_f32(a);
	float32x2_t d2 = vld1_f32(b);
	d1 = vadd_f32(d1, d2);
	vst1_f32(dest, d1);
}

inline void subVec4(float* dest, const float* a, const float* b)
{
	float32x4_t q1 = vld1q_f32(a);
	float32x4_t q2 = vld1q_f32(b);
	q1 = vsubq_f32(q1, q2);
	vst1q_f32(dest, q1);
}

inline void mulVec4(float* dest, const float* a, const float* b)
{
	float32x4_t q1 = vld1q_f32(a);
	float32x4_t q2 = vld1q_f32(b);
	q1 = vmulq_f32(q1, q2);
	vst1q_f32(dest, q1);
}

inline void scaleVec4(float* dest, const float* v, float s)
{
	float32x4_t q = vld1q_f32(v);
	q = vmulq_n_f32(q, s);
	vst1q_f32(dest, q);
}

inline void dotVec4(float* scalarDest, const float* a, const float* b)
{
	float r = 0.f;
	for (int i = 0; i < 4; i++)
	{
		r += a[i] * b[i];
	}
	*scalarDest = r;
}

} // namespace anut


