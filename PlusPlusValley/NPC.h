#pragma once
#include "Character.h"
#include "Inventory.h"

#include <string>
class NPC : public Character
{
private:
	string name;

public:
	NPC();
	NPC(string name);
	~NPC();

	void setName(string name);
	string getName();
	void npcInventory();


};
