#pragma once
#include "Item.h"
#include "Inventory.h"
//#include "Player.h"


class Store
{
public:
	Store();
	~Store();
	Inventory* storeInven;
	void InitInventoty();
	Item* makeItem(ItemType itemType, const string& itemName, int cost);
	void showItemList();
	void sellItem();
	void buyItem();
	void buySeed();
	void buyCrop();
	void buyStone();
	void buyWood();
	void buyTool();


};

