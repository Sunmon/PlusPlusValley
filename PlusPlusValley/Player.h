#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
	string name;
	Inventory* pInven;
public:
	Player();
	~Player();

	Player(string name);
	Player(Tile* totile);
	void setName(string name);
	string getName();
	void act();
	void playerInventory();
	Inventory* getInven();
	void Interact();
};