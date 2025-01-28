#include "graphics/gles/Shader.h"

namespace anut
{
namespace gl
{
Shader::Shader()
{
	__handle = 0;
}

Shader::~Shader()
{
	
}

bool Shader::init()
{
	__handle = glCreateProgram();
	return true;
}

void Shader::shutdown()
{
	if (initialized())
	{
		glDeleteShader(__handle);
		__handle = 0;
		_uniformCache.clear();
	}
}

int Shader::getUniformLocation(const char* uniformName)
{
	auto nameAndLocation = _uniformCache.find(uniformName);
	if (nameAndLocation != _uniformCache.end())
	{
		return nameAndLocation->second;
	}
	
	int location = glGetUniformLocation(__handle, uniformName);
	if (location != -1)
	{
		_uniformCache[uniformName] = location;
	}
	return location;
}
} // gl namespace
} // anut namespace

