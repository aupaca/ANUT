#if not defined(ANUT_RENDERBUFFER_H)
#define ANUT_RENDERBUFFER_H
#include "graphics/gles/GpuResource.h"
#include <GLES3/gl32.h>

namespace anut
{
namespace gl
{
class Renderbuffer : public anut::gl::GpuResource
{
public:
	Renderbuffer();
	
	bool init() override;
	void shutdown() override;
	void load(GLenum format, int width, int height);
};

} // gl namespace 
} // anut namespace

#endif
