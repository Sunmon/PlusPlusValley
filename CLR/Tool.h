#pragma once
#include "Item.h"
#include <string>

//tool Á¾·ù
enum TOOLTYPE { AX, HAMMER, SICKLE, HAND, SPRINKLE, FERTILIZE};

class Tool :
	public Item
{
protected:
	TOOLTYPE toolType;
public:
	Tool();
	~Tool();
	Tool(const std::string& name);
	Tool(TOOLTYPE tt, const std::string& name);
	TOOLTYPE gettooltype();
};

