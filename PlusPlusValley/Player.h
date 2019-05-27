#pragma once
#include <string>
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
	string name;
public:
	Player() {};
	Player(Tile* totile)
	{
		this->setTile(totile);
	}
	void act()
	{
		cout << "act" << endl;
		where();
	}
	void setName(string name) {
		this->name = name;

	}
	string getName() {
		return this->name;
	}
	void showPlayerInfo() {
		cout << "이름 : " << getName() << endl;
		cout << "체력 : " << gethp() << endl;

	}
	void Inventory() {
		Inventory inven = new Inventory;
	}
};
