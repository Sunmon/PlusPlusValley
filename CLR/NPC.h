#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Store.h"
#include "Player.h"
#include <string>
using namespace std;


class NPC : public Character
{
private:
	string name;
	

public:
	Store* store;

	NPC();
	NPC(string name);
	~NPC();

	void setName(string name);
	string getName();
	void goStore(Player* player);



};
