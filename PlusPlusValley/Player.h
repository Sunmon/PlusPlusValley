#pragma once
#include "Character.h"

class Player : public Character
{
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
};
