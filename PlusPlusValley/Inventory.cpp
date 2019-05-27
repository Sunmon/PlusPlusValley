#include "Inventory.h"



Inventory::Inventory()
{
	Inventory::money = 0;
}


Inventory::~Inventory()
{
	//item 객체 모두 삭제
	for (auto& item : items)
		delete(item.first);

	items.clear();
}

//item을 num만큼 추가. 개수가 정해지지 않았다면 1개 추가.
void Inventory::addItem(Item *item, int num /*=1*/)
{
	itemIter = items.find(item);
	if (itemIter == items.end()) items.insert(std::make_pair(item, num));

	//TODO: MAX_NUM과 비교 필요
	else itemIter->second += num;
}

//item을 num만큼 제거한다. 개수가 정해지지 않았다면 1개 제거.
void Inventory::removeItem(Item *item, int num)
{
	itemIter = items.find(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//해당 아이템 전부 제거
void Inventory::clearItem(Item *item)
{
	itemIter = items.find(item);
	if (itemIter == items.end()) return;
	items.erase(itemIter);
	delete(item);
}

//아이템 목록 프린트
void Inventory::printItems()
{
	for (auto& item : items)
		std::cout << "type: " << item.first->getItemType() << " /name: " << item.first->getName() << " /number: " << item.second << std::endl;
}

void Inventory::setMoney(int money)
{
	this->money = money;
}

int Inventory::getMoney()
{
	return money;
}


