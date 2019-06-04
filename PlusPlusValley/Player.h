#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Act.h"

class Player : public Character
{
	//외부에서 생성자 통한 싱글톤 생성 막기 위해 private으로 생성자 정의
private:
	Inventory* inven;
	string name;
	Item* onHand;	//현재 손에 쥐고 있는 아이템
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