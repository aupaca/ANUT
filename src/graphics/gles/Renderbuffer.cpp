#include "graphics/gles/Renderbuffer.h"

namespace anut
{
namespace gl
{
Renderbuffer::Renderbuffer()
{
	
}

bool Renderbuffer::init()
{
	glGenRenderbuffers(1, &__handle);
	return true;
}

void Renderbuffer::shutdown()
{
	if (initialized())
	{
		glDeleteRenderbuffers(1, &__handle);
		__handle = 0;
	}
}

void Renderbuffer::load(GLenum format, int width, int height)
{
	glBindRenderbuffer(GL_RENDERBUFFER, __handle);
	glRenderbufferStorage(GL_RENDERBUFFER, format, width, height);
}
} // gl namespace
} // anut namespace
