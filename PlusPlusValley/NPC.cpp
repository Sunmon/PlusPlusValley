#include "NPC.h"
using namespace std;


NPC::NPC()
{
}

NPC::NPC(string name)
{
	this->name = name;
}


NPC::~NPC()
{
}

void NPC::setName(string name)
{
	this->name = name;
}

string NPC::getName()
{
	return this->name;
}

void NPC::npcInventory()
{
	Inventory* nInven;
}
