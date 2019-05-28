#pragma once
#include "Character.h"
#include "Player.h"
#include <iostream>
#include <string>

enum MAIN_MENU {
	MM_NONE,
	MM_INFO,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

class InitialPage : public Character
{
private:
	string name;

public:
	InitialPage();
	~InitialPage();

	void makePlayer();
	void showInfoPlayer();
	void menu();
};