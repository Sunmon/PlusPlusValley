#pragma once
#include "Tile.h"
#include "MapObject.h"
#include "Item.h"
#include "Tool.h"
class Act
{
public:
	bool interact(MapObject* mo, Tool* tool);	//object�� ������ true, �ı��Ǹ� false ����
	void interact(Tile* target, Tool* tool);
	bool reduceHP(MapObject* mo);	//object hp ����, object�� ���������� true ����

};

