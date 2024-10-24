#if not defined(ANUT_SHADER_H)
#define ANUT_SHADER_H
#include "graphics/gles/GpuResource.h"
#include <GLES3/gl32.h>
#include <unordered_map>
#include <string>

namespace anut
{
namespace gl
{
class Shader : public anut::gl::GpuResource
{
public:
	Shader();
	~Shader();
	
	bool init() override;
	void shutdown() override;
	int getUniformLocation(const std::string& uniformName);
	void use();
	
private:
	std::unordered_map<std::string, int> _uniformCache;
};

inline void Shader::use()
{
	glUseProgram(__handle);
}
} // gl namespace
} // anut namespace

#endif
