#pragma once
#include "Item.h"
#include "Tool.h"
#include <iostream>
#include <utility>
#include <map>

/**
* 인벤토리를 관리하는 클래스
* 사용 방법:
*	items<Item*, num>:			아이템 목록 <아이템, 개수>
*	addItem(Item*, num):		num만큼 인벤토리에서 아이템 추가. num이 없다면 1개 추가.
*	removeItem(Item*, num):		num만큼 인벤토리에서 아이템 제거. num이 없다면 1개 제거.
*	clearItem(Item*):			해당 아이템을 인벤토리에서 전부 삭제 & 아이템 객체까지 삭제
*	printItem():				아이템 목록 출력
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
	Item* getfirstItem();

private:
	std::map<Item*, int>::iterator itemIter;
	int money;
};

