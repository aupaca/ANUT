#include "graphics/gles/Framebuffer.h"
#include "graphics/gles/Renderbuffer.h"
#include "graphics/gles/Texture.h"

namespace anut
{
namespace gl
{
unsigned Framebuffer::_currentFramebufferId = 0;

void Framebuffer::setRenderTarget(const anut::gl::Framebuffer& fbo)
{
	_currentFramebufferId = fbo.getId();
	glBindFramebuffer(fbo.getType(), fbo.getId());
}

void Framebuffer::setRenderTarget()
{
	_currentFramebufferId = 0;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Framebuffer::Framebuffer(GLenum fbType)
{
	_type = fbType;
}

Framebuffer::~Framebuffer()
{
	
}

bool Framebuffer::init()
{
	glGenFramebuffers(1, &__handle);
	return true;
}

void Framebuffer::shutdown()
{
	if (initialized())
	{
		glDeleteFramebuffers(1, &__handle);
		__handle = 0;
	}
}

void Framebuffer::attach(GLenum attachmentType, const anut::gl::Texture& texTarget)
{
	glBindFramebuffer(_type, __handle);
	glFramebufferTexture2D(_type, attachmentType, texTarget.getType(), texTarget.getId(), 0);
	glBindFramebuffer(_type, _currentFramebufferId);
}

void Framebuffer::attach(GLenum attachmentType, const anut::gl::Renderbuffer& target)
{
	glBindFramebuffer(_type, __handle);
	glFramebufferRenderbuffer(_type, attachmentType, GL_RENDERBUFFER, target.getId());
	glBindFramebuffer(_type, _currentFramebufferId);
}

bool Framebuffer::isComplete() const
{
	glBindFramebuffer(_type, __handle);
	GLenum status = glCheckFramebufferStatus(_type);
	glBindFramebuffer(_type, _currentFramebufferId);
	return status == GL_FRAMEBUFFER_COMPLETE;
}

} // gl namespace
} // anut namespace
