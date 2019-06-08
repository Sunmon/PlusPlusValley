#pragma once
#include "Item.h"
#include "Inventory.h"
/** store���� Ŭ����
* ��� ���: <GUI��>
*	������ �����ܰ� Item*�� ��ũ���� ����ϼ���
*	sellItem(Item*, num) �÷��̾��� �κ��丮�� �ִ� item�� ������ �Ǵ�. num��ŭ.
*	buyItem(Item*, num)	������ �ִ� �������� �÷��̾��� �κ��丮�� ��´�.
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

