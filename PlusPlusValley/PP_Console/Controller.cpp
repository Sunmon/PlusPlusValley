#include "Controller.h"
Controller* Controller::instance = nullptr;

Controller::Controller()
{
}
Controller::~Controller()
{
}

Controller* Controller::getInstance()
{
	if (instance == nullptr) instance = new Controller();
	return instance;
}

void Controller::init()
{
	map = new Map();
	startTile = map->gettile(15, 10);
	//TODO: initPage 이용하도록
	//player->setTile(startTile);
	
	player = new Player(startTile);
	//InitialPage itp = new InitialPage();
	//itp.makePlayer(player);

	//player->setTile(startTile);
	//new InitialPage()->makePlayer(player);
	movethread = new MoveThread(player);
	time = new UseTime(9 * 60);
	//npc = new NPC();
	//npc->setTile(map->map[3][4]);
}

void Controller::Nextday()
{
	map->growth();
	map->savemap();
	map->loadmap();

}

void Controller::test_move()
{
	movethread->start();
	while (1)
	{
	while (time->gettime() < 10*60)
	{
		Sleep(1000);
		time->nexttime();
		cout << setw(2) << setfill('0') << time->gethour() << ':' << setw(2) << setfill('0') << time->getminute() << endl;
	}
	Sleep(5000);
	Nextday();
	time->settime(9*60);
	}
}



Player* Controller::getPlayer()
{
	return player;
}


