#if not defined(ANUT_NEON_H)
#define ANUT_NEON_H

namespace anut
{
void storeVec4(float* dest, const float* source);
void storeVec2(float* dest, const float* source);
void addVec4(float* dest, const float* a, const float* b);
void addVec2(float* dest, const float* a, const float* b);
void subVec4(float* dest, const float* a, const float* b);
void mulVec4(float* dest, const float* a, const float* b);
void scaleVec4(float* dest, const float* v, float s);
void dotVec4(float* scalarDest, const float* a, const float* b);
} // namespace anut

#include "math/neon-inl.hpp"

#endif
