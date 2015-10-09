#pragma once
#include "common/defines.h"
#include <string>

class EXPORT_API LibraryUtils
{
public:
	explicit LibraryUtils(const std::string &name);
	~LibraryUtils();

	bool Load();
	
	bool CallEntryFunction(const std::string &functionName);

	bool Unload();

	bool IsLoaded();

	/// Return the path to the plugin file on disk
	std::string GetFileName();
	/// Return the display name for the plugin
	std::string GetDisplayName();

	// Make this object be noncopyable as it holds a pointer
	LibraryUtils(const LibraryUtils &)  = delete;
	const LibraryUtils &operator =(const LibraryUtils &) = delete;

private:
	class Impl;
	Impl *mImpl;
};