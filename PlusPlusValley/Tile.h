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
	void setleft(Tile* toTIle)
	{
		this->leftTile = toTIle;
	}
	void setright(Tile* toTIle)
	{
		this->rightTile = toTIle;
	}
	void setup(Tile* toTIle)
	{
		this->upTile = toTIle;
	}
	void setdown(Tile* toTIle)
	{
		this->downTile = toTIle;
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




