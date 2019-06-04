#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Act.h"

class Player : public Character
{
private:
	Inventory* inven;
	string name;
	Tool* onHand;	//���� �տ� ��� �ִ� ����
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
	void interact();
	void InitInventory();
	void setInven(Inventory* inven);
	void setOnHand(Tool* item);
	Tool* getOnHand();
	Act action;
};