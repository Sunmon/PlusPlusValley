#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


//item을 num만큼 추가. 개수가 정해지지 않았다면 1개 추가.
void Inventory::addItem(Item item, int num /*=1*/)
{
	//기존에 아이템이 없다면 num만큼 새로 추가. 있다면 num만큼 증가
	itemIter = items.find(item);
	if (itemIter == items.end()) items.insert(std::make_pair(item, num));
	else itemIter->second += num;
}

//item을 num만큼 제거한다. 개수가 정해지지 않았다면 1개 제거.
void Inventory::removeItem(Item item, int num)
{
	itemIter = items.find(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//해당 아이템 전부 제거
void Inventory::clearItem(Item item)
{
	itemIter = items.find(item);
	if (itemIter == items.end()) return;
	items.erase(itemIter);
}

//아이템 목록 프린트
void Inventory::printItems()
{
	for (auto& item : items)
		std::cout << "name: " << item.first.getName << " num:" << item.second << std::endl;
}



