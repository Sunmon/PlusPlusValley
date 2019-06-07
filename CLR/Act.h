#pragma once
#include "Tile.h"
#include "MapObject.h"
#include "Item.h"
#include "Tool.h"
#include "Harvest.h"
class Act
{
public:
	MapObject* reduceHP(MapObject* mo);	//object hp 줄임, object가 남아있으면 true 리턴
	MapObject* interact(MapObject* mo, Item* item);	//object가 있으면 true, 파괴되면 false 리턴
	void interact(Tile* target, Item* item);

};

