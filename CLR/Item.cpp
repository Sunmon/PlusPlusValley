#include "Item.h"
//using namespace System::Windows::Forms;

Item::Item() : Item(ItemType::NONE, "")
{
	this->MAX_NUM = 10;
	//this->itemType = ItemType::NONE;	//�ʱ�ȭ
}

Item::Item(ItemType itemType, const std::string& name)
{
	this->itemType = itemType;
	this->name = name;
}

Item::~Item()
{
}

void Item::setName(const std::string& name)
{
	this->name = name;
}
//GUI��
//void Item::setItem(Panel p)
//{
//
//}

void Item::setMAX_NUM(int num)
{
	this->MAX_NUM = num;
}

void Item::setCost(int cost)
{
	this->cost = cost;
}

void Item::setItemType(ItemType itemType)
{
	this->itemType = itemType;
}

ItemType Item::getItemType()
{
	return itemType;
}


int Item::getMAX_NUM()
{
	return MAX_NUM;
}

int Item::getCost()
{
	return cost;
}

std::string& Item::getName()
{
	return this->name;
}