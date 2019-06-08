#include "Inventory.h"
#define MAX(a,b)	((a>b)? a: b)



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
void Inventory::addItem(Item* item, int num)
{
	/*itemIter = items.find(item);
	if (itemIter == items.end()) items.insert(std::make_pair(item, num));
	else itemIter->second = MAX(itemIter->second + num, item->getMAX_NUM());
	*/

	itemIter = findIter(item);
	//std::vector<pair<Item*, int> >::iterator it = find(items2.begin(), items2.end(), item);
	if (itemIter == items.end()) items.push_back(std::make_pair(item, num));
	else itemIter->second = MAX(itemIter->second + num, item->getMAX_NUM());
}

//item을 num만큼 제거한다. 개수가 정해지지 않았다면 1개 제거.
void Inventory::removeItem(Item* item, int num)
{
	//itemIter = items.find(item);
	itemIter = findIter(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//해당 아이템 전부 제거
void Inventory::clearItem(Item* item)
{
	//itemIter = items.find(item);
	itemIter = findIter(item);
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
Item* Inventory::findItem(string name) {


	for (auto& item : items)
	{
		if (name == item.first->getName()) return item.first;
	}
	return NULL;
}

//map<Item*, int>::iterator Inventory::findIter(string name)
//{
//	for (auto item = items.begin(); item != items.end(); item++)
//	{
//		if (name == item->first->getName()) return item;
//	}
//	return items.end();
//}
//

std::vector<pair<Item*, int>>::iterator Inventory::findIter(Item* item)
{
	for (itemIter = items.begin(); itemIter != items.end(); itemIter++)
	{
		if (itemIter->first == item) break;
	}
	return itemIter;
}

Item* Inventory::getfirstItem()
{
	itemIter = items.begin();
	return itemIter->first;
}





