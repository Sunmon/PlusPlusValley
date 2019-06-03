#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
	Inventory* inven;
	string name;
public:
	Player();
	~Player();

	Player(string name);
	Player(Tile* totile);
	void setName(string name);
	string getName();
	void act();
	Inventory* getInven();
	void Interact();
	void InitInventory();
	void setInven(Inventory* inven);




};