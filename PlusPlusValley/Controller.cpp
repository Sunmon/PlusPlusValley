#include "Controller.h"
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

	//MoveThread move(&player);
	//UseTime time(9 * 60);
	movethread->start();
	while (1)
	{
		Sleep(1000);
		time->nexttime();
		cout << setw(2) << setfill('0') << time->gethour() << ':' << setw(2) << setfill('0') << time->getminute() << endl;
	}
}


