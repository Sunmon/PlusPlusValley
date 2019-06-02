#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	cout << "플레이어 생성!" << endl;
	
}


Player::~Player()
{
}

Player::Player(string name)
{
	this->name = name;
	Inventory* Inven = new Inventory();
}

Player::Player(Tile * totile)
{
	this->setTile(totile);
}

void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return this->name;
}

void Player::act()
{
	cout << "act" << endl;
	where();
}
void Player:: InitInventory()
{
	this->inven = new Inventory();
	inven->setMoney(500);
}

void Player::setInven(Inventory* inven)
{
	this->inven = inven;
}

Inventory* Player::getInven()
{
	return this->inven;
}





