#include "Player.h"

using namespace std;


Player::Player()
{
	cout << "�÷��̾� ����!" << endl;
}


Player::~Player()
{
}

Player::Player(string name)
{
	this->name = name;
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

void Player::playerInventory()
{
	Inventory* pInven;


}




