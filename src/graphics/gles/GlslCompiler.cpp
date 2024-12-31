#include "graphics/gles/GlslCompiler.h"
#include "graphics/gles/Shader.h"
#include <sstream>
#include <fstream>

namespace anut
{
namespace gl 
{
GlslCompiler::GlslCompiler()
{
	_program = 0;
	_vertexShader = 0;
	_fragmentShader = 0;
	_vertexShaderFilename = _fragmentShaderFilename = nullptr;
	_hasFailed = false;
}

GlslCompiler::~GlslCompiler()
{
	reset();
}

bool GlslCompiler::compile(anut::gl::Shader& targetShader, const char* vertFilename, const char* fragFilename)
{
	if (!targetShader.initialized())
	{
		_log = "Shader not initialized.\n";
		return false;
	}
	
	reset();
	_vertexShaderFilename = vertFilename;
	_fragmentShaderFilename = fragFilename;
	_program = targetShader.getId();
	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	if (!compile())
	{
		logErrors();
		_hasFailed = true;
		return false;
	}
	return true;
}

bool GlslCompiler::compile()
{
	return compile(_vertexShader, _vertexShaderFilename) 
	    && compile(_fragmentShader, _fragmentShaderFilename)
	    && link();
}

bool GlslCompiler::compile(unsigned shaderId, const char* sourceFile)
{
	std::string content = getFileContent(sourceFile);
	const char* code = content.c_str();
	glShaderSource(shaderId, 1, &code, nullptr);
	glCompileShader(shaderId);
	int status;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
	return status == GL_TRUE;
}

std::string GlslCompiler::getFileContent(const char* filename)
{
	std::ifstream f{filename};
	if (!f.is_open())
	{
		return "";
	}
	std::string line, content;
	while (std::getline(f, line))
	{
		content += line + '\n';
	}
	f.close();
	return content;
}

bool GlslCompiler::link()
{
	glAttachShader(_program, _vertexShader);
	glAttachShader(_program, _fragmentShader);
	glLinkProgram(_program);
	int status;
	glGetProgramiv(_program, GL_LINK_STATUS, &status);
	return status == GL_TRUE;
}

void GlslCompiler::logErrors()
{
	std::stringstream status;
	status << "[!] " << _vertexShaderFilename << ":\n"
	       << getShaderStatus(_vertexShader) << "\n\n";
	
	status << "[!] " << _fragmentShaderFilename << ":\n"
	       << getShaderStatus(_fragmentShader) << "\n\n";
	
	status << "[!] linker:\n" << getLinkerStatus() << "\n";
	_log = status.str();
}

std::string GlslCompiler::getShaderStatus(unsigned shaderId) const
{
	int len;
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &len);
	if (len == 0)
	{
		return std::string("No errors or warnings detected");
	}
	std::string message;
	message.resize(len - 1);
	glGetShaderInfoLog(shaderId, len, nullptr, &message[0]);
	return message;
}

std::string GlslCompiler::getLinkerStatus() const
{
	int len;
	glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &len);
	if (len == 0)
	{
		return std::string("No errors or warnings detected");
	}
	std::string message;
	message.resize(len - 1);
	glGetProgramInfoLog(_program, len, nullptr, &message[0]);
	return message;
}

void GlslCompiler::reset()
{
	if (_vertexShader != 0)
	{
		glDeleteShader(_vertexShader);
	}
	if (_fragmentShader != 0)
	{
		glDeleteShader(_fragmentShader);
	}
	
	_program = 0; 
	_vertexShader = 0;
	_fragmentShader = 0;
	_vertexShaderFilename = _fragmentShaderFilename = nullptr;
	_hasFailed = false;
}
} // gl namespace
} // anut namespace
