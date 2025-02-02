#if not defined(ANUT_TEXTURE_H)
#define ANUT_TEXTURE_H
#include "graphics/gles/Resource.h"
#include <GLES3/gl32.h>

namespace anut
{
namespace gl 
{
class Texture : public anut::gl::Resource
{
public:
	static void setPixelStorageMode(GLenum storageParam, int value);
	
	Texture(GLenum type);
	~Texture();
	
	bool init() override;
	void shutdown() override;
	bool loadFromImage(const char* filename, GLint textureFormat, GLenum imageFormat);
	bool load(int mipmapLevel, const void* data, int width, int height, GLint textureFormat, GLenum imageFormat, GLenum dataType);
	void setParameter(GLenum textureParam, int value);
	void generateMipmap();
	// Call this function after the above functions to avoid a bug
	void bindToUnit(GLenum textureUnit); 
	GLenum getType() const;
	
private:
	GLenum _type;
};

inline GLenum Texture::getType() const
{
	return _type;
}
} // gl namespace
} // anut namespace

#endif
