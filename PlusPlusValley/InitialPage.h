#pragma once
#include <iostream>
#include <string>
#include "Character.h"
#include "Player.h"

class InitialPage
{
private:
	string name;
public:
	InitialPage();
	~InitialPage();

	void makePlayer();
	void showInfoPlayer();
	void Menu();

};

