#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
private:
	Inventory* inven;
	string name;
public:
	Player();
	~Player();

	Player(string name);
	Player(Tile* totile);
	void setName(string name);
	string getName();
	void act();
	void InitInventory();
	void setInven(Inventory* inven);
	Inventory* getInven();








};