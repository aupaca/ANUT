#include "graphics/gles/VertexArray.h"
#include "graphics/gles/Buffer.h"

namespace anut
{
namespace gl
{
VertexArray::VertexArray()
{
	
}

VertexArray::~VertexArray()
{
	
}

bool VertexArray::init()
{
	glGenVertexArrays(1, &__handle);
	return true;
}

void VertexArray::shutdown()
{
	if (initialized())
	{
		glDeleteVertexArrays(1, &__handle);
		__handle = 0;
	}
}

void VertexArray::addVertexBuffer(const anut::gl::Buffer& vb, unsigned attribIndex, int subAttribCount, GLenum subAttribType, bool normalized, int stride, int offset)
{
	if (vb.getBufferType() != GL_ARRAY_BUFFER)
	{
		// TODO: throw error
		return;
	}
	glBindVertexArray(__handle);
	glBindBuffer(GL_ARRAY_BUFFER, vb.getId());
	glEnableVertexAttribArray(attribIndex);
	glVertexAttribPointer(attribIndex, subAttribCount, subAttribType, normalized, stride, (void*) offset);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexArray::setIndexBuffer(const anut::gl::Buffer& eb)
{
	if (eb.getBufferType() != GL_ELEMENT_ARRAY_BUFFER)
	{
		// TODO: throw error
		return;
	}
	glBindVertexArray(__handle);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb.getId());
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void VertexArray::setVertexAttribFrequency(unsigned attribIndex, unsigned divisor)
{
	glBindVertexArray(__handle);
	glVertexAttribDivisor(attribIndex, divisor);
}

void VertexArray::draw(GLenum primitive, int vertexCount) const
{
	glBindVertexArray(__handle);
	glDrawArrays(primitive, 0, vertexCount);
}

void VertexArray::drawIndexed(GLenum primitive, int indexCount, GLenum indexType) const
{
	glBindVertexArray(__handle);
	glDrawElements(primitive, indexCount, indexType, (void*) 0);
}

void VertexArray::drawInstanced(GLenum primitive, int vertexCount, int instanceCount) const
{
	glBindVertexArray(__handle);
	glDrawArraysInstanced(primitive, 0, vertexCount, instanceCount);
}

void VertexArray::drawIndexedInstanced(GLenum primitive, int indexCount, GLenum indexType, int instanceCount) const
{
	glBindVertexArray(__handle);
	glDrawElementsInstanced(primitive, indexCount, indexType, (void*) 0, instanceCount);
}
} // gl namespace
} // anut namespace