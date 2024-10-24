#include "graphics/gles/GpuResource.h"

namespace anut
{
namespace gl 
{
std::list<GpuResource*> GpuResource::allResources{};

GpuResource::GpuResource()
{
	allResources.push_back(this);
	__handle = 0;
}

GpuResource::~GpuResource()
{
	allResources.remove(this);
}
} // gl namespace	
} // anut namespace
