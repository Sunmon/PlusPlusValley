#pragma once
#include <map>
#include <vector>
#include "MapObject.h"
#include "Harvest.h"


using namespace std;

class Tile
{
private:
	int x;
	int y;
	bool canmove;	//�÷��̾ ���� �ö� �� ������ true
	bool isvalue;	//��ġ�� ���¸� true
	bool isWet;
	bool fertilizer;
	Tile* leftTile;
	Tile* rightTile;
	Tile* upTile;
	Tile* downTile;
	MapObject* mapobject;
	Harvest* harv;

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
		isWet = false;
		fertilizer = false;
		mapobject = NULL;
		leftTile = NULL;
		rightTile = NULL;
		upTile = NULL;
		downTile = NULL;
		harv = NULL;
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
	/*bool getisWet() {
		return this->isWet;
	}*/

	bool getIsvalue()
	{
		return this->isvalue;
	}
	bool getcanmove()
	{
		return this->canmove;
	}
	bool setIsWet(bool isWet) {
		this->isWet = isWet;
	}
	bool setFertilizer(bool fert) {
		this->fertilizer = fert;
	}
	bool getIsWet() {

		string str;
		isWet ? str = "���� �����ֽ��ϴ�" : str = "���� �����ֽ��ϴ�.";
		cout << str << endl;
		return isWet;
	}
	bool getFertilizer() {

		string str;
		fertilizer ? str = "��Ḧ �̹� ����ϴ�" : str = "��Ḧ ���� �ʾҽ��ϴ�";
		cout << str << endl;
		return fertilizer;
	}
	void setObject(MapObject* object)
	{
		if (this->isvalue) return;

		this->mapobject = object;
		if (object->getObjectType() != harvest)
		{
			canmove = false;
		}

			
		isvalue = true;
	
	}

	void setObject(Harvest* har)
	{
		if (this->isvalue) return;

		this->mapobject = har;
		this->harv = har;
		isvalue = true;
	}
	MapObject* getObject()
	{
		return mapobject;
	}
	Harvest* getHarvest()
	{
		return harv;
	}

	//tile�� �ִ� object ����
	void removeObj()
	{
		delete(mapobject);
		this->canmove = true;
		this->mapobject = NULL;
		this->isvalue = false;
	}
	//NPC�� Ÿ�Ͽ� ���´�
	/*void setNPC() {
		if (this->isvalue) return;
		this->mapobject = object;
		if (object->getObjectType() != harvest)
		{
			canmove = false;
		}

		isvalue = true;
	}
	NPC* getNPC() {
		return this->npc;
	}*/
};





