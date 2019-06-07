#include "Controller.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


Controller::Controller()
{
	init();
}

Controller::~Controller()
{
}



void Controller::init()
{
	map = new Map();
	startTile = map->gettile(15, 10);
	player = new Player(startTile);
	movethread = new MoveThread(player);
	time = new UseTime(9 * 60);

}

void Controller::test_move()
{
	movethread->start();
	while (1)
	{
		Sleep(1000);
		time->nexttime();
		cout << setw(2) << setfill('0') << time->gethour() << ':' << setw(2) << setfill('0') << time->getminute() << endl;
	}
}

void Controller::setName(string name)
{
	player->setName(name);

}

string Controller::getPlayerName()
{
	return player->getName();
}

int Controller::getPlayerX() {
	return player->getX();
}

int Controller::getPlayerY()
{
	return player->gety();
}

void Controller::setPlayerPlace(int a)
{
	player->move(a);
}

