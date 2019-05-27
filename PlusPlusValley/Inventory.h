#pragma once
#include "Item.h"
#include "Tool.h"
#include <iostream>
#include <utility>
#include <map>

/**
* �κ��丮�� �����ϴ� Ŭ����
* ��� ���:
*	items<Item*, num>:			������ ��� <������, ����>
*	addItem(Item*, num):		num��ŭ �κ��丮���� ������ �߰�. num�� ���ٸ� 1�� �߰�.
*	removeItem(Item*, num):		num��ŭ �κ��丮���� ������ ����. num�� ���ٸ� 1�� ����.
*	clearItem(Item*):			�ش� �������� �κ��丮���� ���� ���� & ������ ��ü���� ����
*	printItem():				������ ��� ���
* @author KIM SUN JUNG
* @date 2019.05.26
*/
class Inventory
{
public:
	Inventory();
	~Inventory();

	std::map<Item*, int> items;
	void addItem(Item *item, int num = 1);
	void removeItem(Item *item, int num = 1);
	void clearItem(Item *item);
	void printItems();
	void setMoney(int money);
	int getMoney();

private:
	std::map<Item*, int>::iterator itemIter;
	int money;
};
