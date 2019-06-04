#pragma once
#include "Tile.h"
#include "MapObject.h"
#include "Item.h"
#include "Tool.h"
class Act
{
public:
	void interact(MapObject* mo, Tool* tool);
	void interact(Tile* target, Tool* tool);

};

