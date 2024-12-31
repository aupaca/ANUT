#if not defined(ANUT_GLSL_COMPILER_H)
#define ANUT_GLSL_COMPILER_H
#include <GLES3/gl32.h>
#include <string>

namespace anut
{
namespace gl
{
class Shader;

class GlslCompiler
{
public:
	GlslCompiler();
	virtual ~GlslCompiler();
	
	bool compile(anut::gl::Shader& targetShader, const char* vertFilename, const char* fragFilename);
	const std::string& getStatus() const;
	
private:
	bool compile();
	bool compile(unsigned shaderId, const char* sourceFile);
	std::string getFileContent(const char* filename);
	bool link();
	void reset();
	void logErrors();
	std::string getShaderStatus(unsigned shaderId) const;
	std::string getLinkerStatus() const;
	
	const char* _vertexShaderFilename;
	const char* _fragmentShaderFilename;
	unsigned _program;
	unsigned _vertexShader;
	unsigned _fragmentShader;
	std::string _log;
	bool _hasFailed;
};

inline const std::string& GlslCompiler::getStatus() const
{
	return _log;
}
} // gl namespace
} // anut namespace

#endif
