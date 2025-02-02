#if not defined(ANUT_RESOURCE_H)
#define ANUT_RESOURCE_H
#include <list>

namespace anut
{
namespace gl
{
class Resource 
{
public:
	static std::list<Resource*> allResources;
	
	Resource();
	virtual ~Resource();
	
	virtual bool init() = 0;
	virtual void shutdown() = 0;
	bool initialized() const;
	unsigned getId() const;
	
protected:
	unsigned __handle;
};

inline bool Resource::initialized() const
{
	return __handle != 0;
}

inline unsigned Resource::getId() const
{
	return __handle;
}
} // gl namespace
} // anut namespace

#endif
