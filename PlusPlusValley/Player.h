#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Act.h"

class Player : public Character
{
	//외부에서 생성자 통한 싱글톤 생성 막기 위해 private으로 생성자 정의
private:
	Player();
	~Player();
	Player(string name);
	Player(Tile* totile);

	static Player* inst;

	Inventory* inven;
	string name;
	Tool* onHand;	//현재 손에 쥐고 있는 도구
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