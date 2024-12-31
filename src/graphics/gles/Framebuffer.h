#if not defined(ANUT_FRAMEBUFFER_H)
#define ANUT_FRAMEBUFFER_H
#include "graphics/gles/GpuResource.h"
#include <GLES3/gl32.h>

namespace anut
{
namespace gl
{
class Texture;
class Renderbuffer;

class Framebuffer : public anut::gl::GpuResource
{
public:
	static void setRenderTarget(const anut::gl::Framebuffer& target);
	static void setRenderTarget();
	
	Framebuffer(GLenum fbType);
	virtual ~Framebuffer();
	
	bool init() override;
	void shutdown() override;
	void attach(GLenum attachmentType, const anut::gl::Texture& target);
	void attach(GLenum attachmentType, const anut::gl::Renderbuffer& target);
	bool isComplete() const;
	GLenum getType() const;
	
private:
	static unsigned _currentFramebufferId;
	GLenum _type;
};

inline GLenum Framebuffer::getType() const
{
	return _type;
}

} // gl namespace
} // anut namespace

#endif
