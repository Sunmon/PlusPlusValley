#include "Inventory.h"



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
void Inventory::addItem(Item *item, int num /*=1*/)
{
	itemIter = items.find(item);
	if (itemIter == items.end()) items.insert(std::make_pair(item, num));

	//TODO: MAX_NUM�� �� �ʿ�
	else itemIter->second += num;
}

//item�� num��ŭ �����Ѵ�. ������ �������� �ʾҴٸ� 1�� ����.
void Inventory::removeItem(Item *item, int num)
{
	itemIter = items.find(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//�ش� ������ ���� ����
void Inventory::clearItem(Item *item)
{
	itemIter = items.find(item);
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


