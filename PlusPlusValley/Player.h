#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
	Inventory* inven;
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
	void InitInventory();
	void setInven(Inventory* inven);




};