#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
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

