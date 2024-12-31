#include "graphics/gles/Texture.h"
#include "vendor/stb_image.h"
#include <cstdint>

namespace anut
{
namespace gl
{
void Texture::setPixelStorageMode(GLenum storageParam, int value)
{
	glPixelStorei(storageParam, value);
}

Texture::Texture(GLenum type)
{
	_type = type;
}

Texture::~Texture()
{
	
}

bool Texture::init()
{
	glGenTextures(1, &__handle);
	return true;
}

void Texture::shutdown()
{
	if (initialized())
	{
		glDeleteTextures(1, &__handle);
		__handle = 0;
	}
}

bool Texture::loadFromImage(const char* filename, GLint textureFormat, GLenum imageFormat)
{
	stbi_set_flip_vertically_on_load(true);
	int width, height, colorChannels;
	uint8_t* data = stbi_load(filename, &width, &height, &colorChannels, 0);
	if (data == nullptr)
	{
		return false;
	}
	glBindTexture(_type, __handle);
	glTexImage2D(_type, 0, textureFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);
	return true;
}

bool Texture::load(int mipmapLevel, const uint8_t* data, int width, int height, GLint textureFormat, GLenum imageFormat, GLenum dataType)
{
	glBindTexture(_type, __handle);
	glTexImage2D(_type, mipmapLevel, textureFormat, width, height, 0, imageFormat, dataType, data);
	return true;
}

void Texture::setParameter(GLenum textureParam, int value)
{
	glBindTexture(_type, __handle);
	glTexParameteri(_type, textureParam, value);
}

void Texture::generateMipmap()
{
	glBindTexture(_type, __handle);
	glGenerateMipmap(_type);
}

void Texture::bindToUnit(GLenum textureUnit)
{
	glActiveTexture(textureUnit);
	glBindTexture(_type, __handle);
	// If a function that binds a texture is called after this function 
	// then that texture will replace the texture attached to the unit
	// causing a bug.
	// Maybe i can solve it like this:
	// glActiveTexture(textureUnit + 1);
}
} // gl namespace
} // anut namespace

