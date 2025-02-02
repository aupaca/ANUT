#if not defined(ANUT_BUFFER_H)
#define ANUT_BUFFER_H
#include "graphics/gles/Resource.h"
#include <GLES3/gl32.h>

namespace anut
{
namespace gl
{
class Buffer : public anut::gl::Resource
{
public:
	Buffer(GLenum bufferType);
	virtual ~Buffer();
	
	bool init() override;
	void shutdown() override;
	void alloc(GLsizeiptr size, GLenum usage, const void* initialData = nullptr);
	void copyData(const void* data, GLsizeiptr size, GLintptr offsetInBytes = 0);
	GLenum getBufferType() const;
	
private:
	GLenum _type;
};

inline GLenum Buffer::getBufferType() const
{
	return _type;
}

} // gl namespace
} // anut namespace

#endif
