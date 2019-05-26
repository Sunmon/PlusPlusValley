#include "Item.h"


Item::Item()
{
	Item::itemType = Item::ItemType::NONE;	//√ ±‚»≠
}

Item::Item(ItemType itemType, const std::string& name)
{
	Item::itemType = itemType;
	Item::name = name;
}

Item::~Item()
{
}

void Item::setName(const std::string& name)
{
	Item::name = name;
}

void Item::setMAX_NUM(int num)
{
	MAX_NUM = num;
}

void Item::setCost(int cost)
{
	Item::cost = cost;
}

void Item::setItemType(ItemType itemType)
{
	Item::itemType = itemType;
}

Item::ItemType Item::getItemType()
{
	return Item::itemType;
}


int Item::getMAX_NUM()
{
	return Item::MAX_NUM;
}

int Item::getCost()
{
	return Item::cost;
}

std::string& Item::getName()
{
	return Item::name;
}

