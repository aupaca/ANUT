#if not defined(ANUT_VERTEX_ARRAY_H)
#define ANUT_VERTEX_ARRAY_H
#include "graphics/gles/GpuResource.h"
#include <GLES3/gl32.h>

namespace anut
{
namespace gl
{
class Buffer;
	
class VertexArray : public anut::gl::GpuResource
{
public:
	VertexArray();
	virtual ~VertexArray();
	
	bool init() override;
	void shutdown() override;
	void addVertexBuffer(const anut::gl::Buffer& vb, unsigned attribIndex, int subAttribCount, GLenum subAttribType, bool normalized, int stride, int offset);
	void setIndexBuffer(const anut::gl::Buffer& eb);
	void setVertexAttribFrequency(unsigned attribIndex, unsigned divisor);
	void draw(GLenum primitive, int vertexCount) const;
	void drawIndexed(GLenum primitive, int indexCount, GLenum indexType) const;
	void drawInstanced(GLenum primitive, int vertexCount, int instanceCount) const;
	void drawIndexedInstanced(GLenum primitive, int indexCount, GLenum indexType, int instanceCount) const;
};
} // gl namespace
} // anut namespace

#endif

