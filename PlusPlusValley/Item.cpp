#include "Item.h"


Item::Item()
{

}

Item::Item(ItemType itemType, std::string name)
{
	Item::itemType = itemType;
	Item::name = name;
}

Item::~Item()
{
}