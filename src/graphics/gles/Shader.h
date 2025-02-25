#if not defined(ANUT_SHADER_H)
#define ANUT_SHADER_H
#include "graphics/gles/Resource.h"
#include <GLES3/gl32.h>
#include <unordered_map>
#include <string>

namespace anut
{
namespace gl
{
class Shader : public anut::gl::Resource
{
public:
	Shader();
	~Shader();
	
	bool init() override;
	void shutdown() override;
	int getUniformLocation(const char* uniformName);
//	unsigned getUniformBlockIndex(const char* blockName);
	void use();
	
private:
	std::unordered_map<std::string, int> _uniformCache;
//	std::unordered_map<std::string, unsigned> _uniformBlockCache;
};

inline void Shader::use()
{
	glUseProgram(__handle);
}
} // gl namespace
} // anut namespace

#endif
