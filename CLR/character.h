#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
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

	Character() {
	}
	

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
		const int LEFT = 37, RIGHT = 39, UP = 40, DOWN = 38;
		switch (tomove)
		{
		case LEFT: totile = nowtile->getleft(); statue = faceleft;break;
		case RIGHT: totile = nowtile->getright(); statue = faceright; break;
		case UP: totile = nowtile->getup(); statue = faceup; break;
		case DOWN: totile = nowtile->getdown(); statue = facedown; break;
		default: break;
		}
		if (totile != NULL) this->nowtile = totile;
		this->where();
	}

	



};
