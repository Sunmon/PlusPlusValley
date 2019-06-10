#include "Tool.h"


Tool::Tool():Item()
{
	Tool::itemType = ItemType::TOOL;
}

Tool::~Tool()
{
}

Tool::Tool(const std::string& name) :Item(itemType, name)
{
	Tool::itemType = TOOL;
	Tool::setMAX_NUM(1);
}

Tool::Tool(TOOLTYPE tt, const std::string& name):Tool(name)
{
	this->toolType = tt;
}

TOOLTYPE Tool::gettooltype()
{
	return toolType;
}

