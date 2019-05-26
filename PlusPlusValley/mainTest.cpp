// testing git solution
// 테스트용 코드
#include <iostream>
#include "Inventory.h"
#include "character.h"
using namespace std;

void test_inventory();


int main()
{

	test_inventory();
	
	
	return 0;


}


void test_inventory()
{
	//test for inventory
	Inventory* inven = new Inventory();

	//add item to inventory
	Item* seed = new Item(Item::SEED, "Seed");
	Item* wood = new Item(Item::ItemType::WOOD, "Wood");
	Item* stone = new Item(Item::ItemType::STONE, "Stone");
	inven->addItem(seed, 10);
	inven->addItem(wood);
	inven->addItem(stone, 2);
	inven->addItem(stone);
	inven->addItem(new Item(Item::CROP, "Crop"));

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