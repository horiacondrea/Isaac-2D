#include "LibraryUtils.h"
#include <cassert>

#if _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class LibraryUtils::Impl
{
public:
	std::string mFileName;
	std::string mDisplayName;
#if _WIN32
	// Plugin loading routines for Windows
	HINSTANCE handle;

	typedef FARPROC PluginFunc;

	bool Load()
	{
		handle = LoadLibrary(mFileName.c_str());
		return (handle != NULL);
	}

	bool Unload()
	{
		if (!handle)
			return true;
		return FreeLibrary(handle) != 0;
	}

	PluginFunc GetFunction(const std::string &name)
	{
		PluginFunc fptr = GetProcAddress(handle, name.c_str());
		if (! fptr)
			return NULL;
		return fptr;
	}
#else
	// Plugin loading routines for Mac & Linux
	void *handle;

	typedef void(*PluginFunc)();

	bool Load()
	{
		handle = dlopen(mFileName.c_str(), RTLD_LOCAL | RTLD_LAZY);
		return (handle != NULL);
	}

	bool Unload()
	{
		if (!handle)
			return true;
		return dlclose(handle) == 0;
	}

	PluginFunc GetFunction(const std::string &name)
	{
		dlerror();
		PluginFunc fptr = (PluginFunc) dlsym(handle, name.c_str());
		if (dlerror())
			return NULL;
		return fptr;
	}
#endif
};



LibraryUtils::LibraryUtils(const std::string &name)
{
	mImpl = new Impl;
	mImpl->mDisplayName = name;

#if _WIN32
	mImpl->mFileName = name + ".dll";
#elif __APPLE__
	mImpl->mFileName = "lib" + name + ".dylib";
#else
	mImpl->mFileName = "lib" + name + ".so";
#endif
}

LibraryUtils::~LibraryUtils()
{
	delete mImpl;
}

bool LibraryUtils::Load()
{
	if (! mImpl->Load())
		return false;

	return true;
}

bool LibraryUtils::CallEntryFunction(const std::string &functionName)
{
	assert (IsLoaded());
	
	Impl::PluginFunc init_func = mImpl->GetFunction(functionName);
	if (!init_func)
		return false;
		
	(*init_func)();
	return true;
}

bool LibraryUtils::Unload()
{
	return mImpl->Unload();
}

bool LibraryUtils::IsLoaded()
{
	return (mImpl->handle != NULL);
}

std::string LibraryUtils::GetFileName()
{
	return mImpl->mFileName;
}

std::string LibraryUtils::GetDisplayName()
{
	return mImpl->mDisplayName;
}