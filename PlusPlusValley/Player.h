#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Act.h"

class Player : public Character
{
	//�ܺο��� ������ ���� �̱��� ���� ���� ���� private���� ������ ����
private:
	Player();
	~Player();
	Player(string name);
	Player(Tile* totile);

	static Player* inst;

	Inventory* inven;
	string name;
	Tool* onHand;	//���� �տ� ��� �ִ� ����
public:
	static Player* getInstance();
	void test();



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