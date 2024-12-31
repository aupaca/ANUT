#include "graphics/gles/Buffer.h"

namespace anut
{
namespace gl 
{
Buffer::Buffer(GLenum bufferType)
{
	_type = bufferType;
}

Buffer::~Buffer()
{
	
}

bool Buffer::init()
{
	glGenBuffers(1, &__handle);
	return true;
}

void Buffer::shutdown()
{
	if (initialized())
	{
		glDeleteBuffers(1, &__handle);
		__handle = 0;
	}
}

void Buffer::alloc(GLsizeiptr size, GLenum usage, const void* initialData)
{
	glBindBuffer(_type, __handle);
	glBufferData(_type, size, initialData, usage);
}

void Buffer::copyData(const void* data, GLsizeiptr size, GLintptr offsetInBytes)
{
	glBindBuffer(_type, __handle);
	glBufferSubData(_type, offsetInBytes, size, data);
}
} // gl namespace
} // anut namespace

