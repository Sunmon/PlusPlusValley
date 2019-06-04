#pragma once
#include <map>
#include <vector>
#include "MapObject.h"

using namespace std;

class Tile
{
private:
	int x;
	int y;
	bool canmove;	//�÷��̾ ���� �ö� �� ������ true
	bool isvalue;	//��ġ�� ���¸� true
	Tile* leftTile;
	Tile* rightTile;
	Tile* upTile;
	Tile* downTile;
	MapObject* mapobject;
public:
	Tile(){}
	Tile(int x, int y)
	{
		setXY(x, y);
		init();
	}

	void init()
	{
		canmove = true;
		isvalue = false;
		mapobject = NULL;
		leftTile = NULL;
		rightTile = NULL;
		upTile = NULL;
		downTile = NULL;
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

	bool getIsvalue()
	{
		return this->isvalue;
	}
	bool getcanmove()
	{
		return this->canmove;
	}
	void setObject(MapObject* object)
	{
		if (this->isvalue == true)
		{
			cout << "��ġ�� �Ұ����մϴ�." << endl;
		}
		else
		{
			this->mapobject = object;
			if (object->getObjectType() != harvest)
			{
				canmove = false;
				
			}
			
			isvalue = true;
		}
	}

	MapObject* getObject()
	{
		return mapobject;
	}

	//tile�� �ִ� object ����
	void removeObj()
	{
		delete(mapobject);
		this->canmove = true;
		this->mapobject = NULL;
		this->isvalue = false;
	}
};





