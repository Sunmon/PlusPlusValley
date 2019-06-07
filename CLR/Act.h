#pragma once
#include "Tile.h"
#include "MapObject.h"
#include "Item.h"
#include "Tool.h"
#include "Harvest.h"
class Act
{
public:
	MapObject* reduceHP(MapObject* mo);	//object hp ����, object�� ���������� true ����
	MapObject* interact(MapObject* mo, Item* item);	//object�� ������ true, �ı��Ǹ� false ����
	void interact(Tile* target, Item* item);

};

