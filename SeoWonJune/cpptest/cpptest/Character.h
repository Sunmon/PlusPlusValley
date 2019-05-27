#pragma once
#include <iostream>
#include "Tile.h"

using namespace std;

enum status
{
	faceleft = 1, faceright, faceup, facedown,
};

class Character
{
private:
	Tile* nowtile;
	Tile* target;
	int hp;
	status statue = facedown;

public:
	int getx()
	{
		return nowtile->getx();
	}
	int gety()
	{
		return nowtile->gety();
	}
	void setTile(Tile* tile)
	{
		nowtile = tile;
	}

	int gethp()
	{
		return this->hp;
	}
	void where()
	{

		int wherex = this->getx();
		int wherey = this->gety();
		cout << "(" << wherex << "," << wherey << ")" << endl;
	}

	void move(int tomove)
	{
		if (tomove == 75)
		{
			Tile* totile = nowtile->getleft();
			if (totile != NULL)
				this->nowtile = totile;
			statue = faceleft;
		}
		if (tomove == 77)
		{
			Tile* totile = nowtile->getright();
			if (totile != NULL)
				this->nowtile = totile;
			statue = faceright;
		}
		if (tomove == 72)
		{
			Tile* totile = nowtile->getup();
			if (totile != NULL)
				this->nowtile = totile;
			statue = faceup;
		}
		if (tomove == 80)
		{
			Tile* totile = nowtile->getdown();
			if (totile != NULL)
				this->nowtile = totile;
			statue = facedown;
		}

		this->where();
	}


};

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
