#pragma once
#include "Tile.h"
#include "MapObject.h"
#include "Item.h"
#include "Tool.h"
class Act
{
public:
	bool interact(MapObject* mo, Tool* tool);	//object가 있으면 true, 파괴되면 false 리턴
	void interact(Tile* target, Tool* tool);
	bool reduceHP(MapObject* mo);	//object hp 줄임, object가 남아있으면 true 리턴

};

