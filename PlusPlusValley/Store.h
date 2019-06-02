#pragma once
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "NPC.h"

class Store
{
public:
	Store();
	~Store();
	Inventory* storeInven;
	void InitInventoty();
	void showItemList();
	void sellItem(Player* player);
	void buyItem(Player* player);
};

