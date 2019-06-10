#include "Controller.h"
Controller* Controller::instance = nullptr;

Controller::Controller()
{
	init();
	
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
	player = new Player(startTile);
	movethread = new MoveThread(player);
	time = new UseTime(9 * 60);
	//npc = new NPC();
	//npc->setTile(map->map[3][4]);



	//FIXME:GUI쪽에서 추가
	m[0].setPlace(12, 139);
	m[1].setPlace(101,218);
	m[2].setPlace(453,200);
	m[0].setSize(22, 41);
	m[1].setSize(22, 41);
	m[2].setSize(22, 41);
	m[0].setBool(true);
	m[1].setBool(true);
	m[2].setBool(true);
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

void Controller::Nextday()
{
	
	map->savemap();
	
}

Player* Controller::getPlayer()
{
	return player;
}



//FIXME: GUI쪽에서 추가
MapObject Controller::getMapObject(int i)
{
	return m[i];
}

void Controller::setMapObject(MapObject mm, int i)
{
	m[i] = mm;
}


