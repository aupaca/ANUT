#include "graphics/gles/Resource.h"

namespace anut
{
namespace gl 
{
std::list<Resource*> Resource::allResources{};

Resource::Resource()
{
	allResources.push_back(this);
	__handle = 0;
}

Resource::~Resource()
{
	allResources.remove(this);
}
} // gl namespace	
} // anut namespace
