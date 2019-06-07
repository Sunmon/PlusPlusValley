#pragma once
#include "Item.h"
#include <string>

//tool Á¾·ù
enum TOOLTYPE { AX, HAMMER, SICKLE, HAND};

class Tool :
	public Item
{
public:
	TOOLTYPE toolType;
	Tool();
	~Tool();
	Tool(const std::string& name);
	Tool(TOOLTYPE tt, const std::string& name);
};

