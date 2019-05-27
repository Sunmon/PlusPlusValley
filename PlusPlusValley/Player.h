#pragma once
#include "Character.h"

class Player : public Character
{
public:
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
