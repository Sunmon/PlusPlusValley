// testing git solution
// 테스트용 코드
#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "Controller.h"
#include "Character.h"
#include "NPC.h"
	 
using namespace std;

Controller* controller = Controller::getInstance();
Player* player;
Map* map;

void test_inventory();
void test_store();
void test_saveharvest();

int main()
{
	//controller->test_move();
	//test_store();
	test_saveharvest();
}

void test_inventory()
{
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

void test_store()
{
	Player* player = new Player();

	NPC* npc = new NPC();

	npc->store->showItemList();

	npc->goStore(player);

}

void test_saveharvest()
{
	Map* map = new Map();
	map->loadmap();
	map->growth();
	map->savemap();
}