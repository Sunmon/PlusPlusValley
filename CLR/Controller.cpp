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

/*
	(map->map[12][139])->setObject(new MapObject(tree),12,139);
	(map->map[101][218])->setObject(new MapObject(tree),101,218);
	(map->map[453][200])->setObject(new MapObject(tree),453,200);
	m = new MapObject[10]{ *(map->map[12][139]->getObject()), *(map->map[101][218]->getObject()), *(map->map[453][200]->getObject()), };*/
}


void Controller::test_move()
{
	movethread->start();
	while (1)
	{
		while (time->gettime() < 10 * 60)
		{
			Sleep(1000);
			time->nexttime();
			cout << setw(2) << setfill('0') << time->gethour() << ':' << setw(2) << setfill('0') << time->getminute() << endl;
		}
		Sleep(5000);
		Nextday();
		time->settime(9 * 60);
	}
}

void Controller::Nextday()
{
	map->growth();
	startTile = map->gettile(15, 10);
	player->setTile(startTile);
	map->savemap();
	map->loadmap();
	
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


