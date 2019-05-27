// testing git solution
// 테스트용 코드
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
	//FIXME: map을 쓰면 자동으로 정렬됨. 순서가 필요하다면 vector를 써야 함.
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