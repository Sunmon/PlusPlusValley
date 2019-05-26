#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


//item�� num��ŭ �߰�. ������ �������� �ʾҴٸ� 1�� �߰�.
void Inventory::addItem(Item item, int num /*=1*/)
{
	//������ �������� ���ٸ� num��ŭ ���� �߰�. �ִٸ� num��ŭ ����
	itemIter = items.find(item);
	if (itemIter == items.end()) items.insert(std::make_pair(item, num));
	else itemIter->second += num;
}

//item�� num��ŭ �����Ѵ�. ������ �������� �ʾҴٸ� 1�� ����.
void Inventory::removeItem(Item item, int num)
{
	itemIter = items.find(item);
	if (itemIter->second <= num) clearItem(item);
	else itemIter->second -= num;
}

//�ش� ������ ���� ����
void Inventory::clearItem(Item item)
{
	itemIter = items.find(item);
	if (itemIter == items.end()) return;
	items.erase(itemIter);
}

//������ ��� ����Ʈ
void Inventory::printItems()
{
	for (auto& item : items)
		std::cout << "name: " << item.first.getName << " num:" << item.second << std::endl;
}



