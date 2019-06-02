#pragma once
#include "Item.h"
#include "Inventory.h"
#include "Player.h"


class Store
{
public:
	Store();
	~Store();
	Inventory* storeInven;
	void InitInventoty();
	Item* makeItem(ItemType itemType, const string& itemName, int cost);
	void showItemList();
	void sellItem(Player* player);
	void buyItem(Player* player);
	void buySeed(Player* player);
	void buyCrop(Player* player);
	void buyStone(Player* player);
	void buyWood(Player* player);
	void buyTool(Player* player);

	
};

