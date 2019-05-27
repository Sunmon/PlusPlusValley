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
	int getX()
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
		int wherex = this->getX();
		int wherey = this->gety();
		cout << "(" << wherex << "," << wherey << ")" << endl;
	}

	
	void move(int tomove)
	{
		Tile* totile = NULL;
		const int LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80;
		switch (tomove)
		{
		case LEFT: totile = nowtile->getleft(); statue = faceleft;break;
		case RIGHT: totile = nowtile->getright(); statue = faceright; break;
		case UP: totile = nowtile->getup(); statue = faceup; break;
		case DOWN: totile = nowtile->getdown(); statue = facedown; break;
		default: break;
		}
		if(totile!=NULL) this->nowtile = totile;
		this->where();
	}


};

