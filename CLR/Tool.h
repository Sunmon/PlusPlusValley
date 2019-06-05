#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
#include "Item.h"
#include <string>
class Tool :
	public Item
{
public:
	Tool();
	~Tool();
	Tool(const std::string& name);
};

