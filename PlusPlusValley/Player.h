#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Act.h"

class Player : public Character
{
	//�ܺο��� ������ ���� �̱��� ���� ���� ���� private���� ������ ����
private:
	Inventory* inven;
	string name;
	Item* onHand;	//���� �տ� ��� �ִ� ������
public:
	Player();
	~Player();
	Player(string name);
	Player(Tile* totile);

	void test();



	Act action;
	void setName(string name);
	string getName();
	void act();
	Inventory* getInven();
	void Interact();
	void interact();
	void InitInventory();
	void setInven(Inventory* inven);
	void setOnHand(Item* item);
	Item* getOnHand();
};