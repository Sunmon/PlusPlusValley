#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
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
