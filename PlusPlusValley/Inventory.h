#pragma once
#include "Item.h"
#include "Tool.h"
#include <iostream>
#include <utility>
#include <map>

/**
* �κ��丮�� �����ϴ� �޼ҵ�
* ��� ���:
*	items<Item, num>: ������ ���
*	addItem(Item, num): num��ŭ �κ��丮���� ������ �߰�. num�� ���ٸ� 1�� �߰�.
*	removeItem(Item, num): num��ŭ �κ��丮���� ������ ����. num�� ���ٸ� 1�� ����.
*	clearItem(Item):	�ش� ������ ���� ����
* @author KIM SUN JUNG
* @date 2019.05.26
*/
class Inventory
{
public:
	Inventory();
	~Inventory();


	std::map<Item*, int> items;		//���� ������ ���. map<������, ����>
	void addItem(Item *item, int num = 1);
	void removeItem(Item *item, int num = 1);
	void clearItem(Item *item);
	void printItems();

private:
	std::map<Item*, int>::iterator itemIter;

};

