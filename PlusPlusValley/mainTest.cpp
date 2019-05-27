// testing git solution
// �׽�Ʈ�� �ڵ�
#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "Controller.h"
using namespace std;

Controller controller;
void test_inventory();

int main()
{

	controller.test_move();
	
	return 0;


}

void test_inventory()
{
	//FIXME: map�� ���� �ڵ����� ���ĵ�. ������ �ʿ��ϴٸ� vector�� ��� ��.
	//test for inventory
	Inventory* inven = new Inventory();

	//add item to inventory
	Item* seed = new Item(ItemType::SEED, "Seed");
	Item* wood = new Item(ItemType::WOOD, "Wood");
	Item* stone = new Item(ItemType::STONE, "Stone");
	inven->addItem(seed, 10);
	inven->addItem(wood);
	inven->addItem(stone, 2);
	inven->addItem(stone);
	inven->addItem(new Item(ItemType::CROP, "Crop"));

	Item* tool = new Tool("Hammer");
	inven->addItem(tool);
	inven->printItems();

	cout << endl;
	inven->addItem(stone, 3);
	inven->removeItem(wood);
	inven->clearItem(seed);
	inven->printItems();
	cout << inven->items.size() << endl;

	delete(inven);


}