#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Store.h"

class Player : public Character
{
private:
	Inventory* inven;
	string name;
	Item* onHand;	//���� �տ� ��� �ִ� ������
	Store* store;
public:
	Player();
	~Player();
	Player(string name);
	Player(Tile* totile);

	void test();



	void setName(string name);
	string getName();
	void act();
	Inventory* getInven();
	void Interact();
	void interact();
	void reduce_MO_HP(MapObject* mo);
	void seeding(Item* seed, Tile* target);
	void InitInventory();
	void setInven(Inventory* inven);
	void setOnHand(Item* item);
	Item* getOnHand();
	void doAction(Item* tool, Tile* target);
	void goStore();
	void sprinkle(Item* tool, Tile* target);
};