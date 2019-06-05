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


