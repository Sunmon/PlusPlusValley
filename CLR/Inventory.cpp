#include "Inventory.h"
#define MAX(a,b)	((a>b)? a: b)



Inventory::Inventory()
{
	Inventory::money = 0;
}


Inventory::~Inventory()
{
	//item ��ü ��� ����
	for (auto& item : items)
		delete(item.first);

	items.clear();
}

//item�� num��ŭ �߰�. ������ �������� �ʾҴٸ� 1�� �߰�.
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

//item�� num��ŭ �����Ѵ�. ������ �������� �ʾҴٸ� 1�� ����.
void Inventory::removeItem(Item* item, int num)
{
	//itemIter = items.find(item);
	itemIter = findIter(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//�ش� ������ ���� ����
void Inventory::clearItem(Item* item)
{
	//itemIter = items.find(item);
	itemIter = findIter(item);
	if (itemIter == items.end()) return;
	items.erase(itemIter);
	delete(item);
}

//������ ��� ����Ʈ
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





