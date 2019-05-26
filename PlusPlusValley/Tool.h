#pragma once
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

