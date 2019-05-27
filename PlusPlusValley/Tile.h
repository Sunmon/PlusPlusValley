#pragma once
#include <map>
#include <vector>


using namespace std;

class Tile
{
private:
	int x;
	int y;
	bool canmove;
	bool isvalue;
	Tile* leftTile;
	Tile* rightTile;
	Tile* upTile;
	Tile* downTile;
public:
	Tile(int x, int y)
	{
		setXY(x, y);
	}
	void setXY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setleft(Tile* toTile)
	{
		this->leftTile = toTile;
	}
	void setright(Tile* toTile)
	{
		this->rightTile = toTile;
	}
	void setup(Tile* toTile)
	{
		this->upTile = toTile;
	}
	void setdown(Tile* toTile)
	{
		this->downTile = toTile;
	}
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}
	Tile* getleft()
	{
		return this->leftTile;
	}
	Tile* getright()
	{
		return this->rightTile;
	}
	Tile* getup()
	{
		return this->upTile;
	}
	Tile* getdown()
	{
		return this->downTile;
	}

	bool getcanmove()
	{
		return this->canmove;
	}

};




