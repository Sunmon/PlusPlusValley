#pragma once
#include "Item.h"
#include <iostream>
#include <utility>
#include <map>

/**
* 인벤토리를 관리하는 메소드
* 사용 방법:
*	items<Item, num>: 아이템 목록
*	addItem(Item, num): num만큼 인벤토리에서 아이템 추가
*	removeItem(Item, num): num만큼 인벤토리에서 아이템 제거
*	clearItem(Item):	해당 아이템 전부 삭제
* @author KIM SUN JUNG
* @date 2019.05.26
*/
class Inventory
{
public:
	Inventory();
	~Inventory();

	void addItem(Item item, int num);
	std::map<Item, int> items;		//가진 아이템 목록. map<아이템, 개수>
	void addItem(Item item, int num = 1);
	void removeItem(Item item, int num = 1);
	void clearItem(Item item);
	void printItems();

private:
	std::map<Item, int>::iterator itemIter;

};
