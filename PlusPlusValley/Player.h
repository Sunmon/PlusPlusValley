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
		cout << "�̸� : " << getName() << endl;
		cout << "ü�� : " << gethp() << endl;

	}
	void Inventory() {
		Inventory inven = new Inventory;
	}
};
