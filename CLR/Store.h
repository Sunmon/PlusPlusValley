#pragma once
#include "Item.h"
#include "Inventory.h"
/** store관련 클래스
* 사용 방법: <GUI용>
*	아이템 아이콘과 Item*를 링크시켜 사용하세요
*	sellItem(Item*, num) 플레이어의 인벤토리에 있는 item을 상점에 판다. num만큼.
*	buyItem(Item*, num)	상점에 있는 아이템을 플레이어의 인벤토리로 사온다.
*
*
*
*
*
*/


class Store
{
public:

	Store();
	~Store();
	Inventory* storeInven;
	Inventory* playerInven;
	void initInventory();
	Item* makeItem(ItemType itemType, const string& itemName, int cost);
	void showItemList();
	void sellItem();
	void buyItem();
	void buySeed();
	void buyCrop();
	void buyStone();
	void buyWood();
	void buyTool();

	void sellItem(Item* item, int num);
	void buyItem(Item* item, int num);


};

