#pragma once
#include <iomanip>
#include "MoveThread.h"
#include "Character.h"
#include "Player.h"
#include "Map.h"
#include "UseTime.h"
#include "InitialPage.h"
#include "NPC.h"
class Controller
{
private:
	Controller();
	~Controller();
	static Controller* instance;	//static 변수 -> 클래스 외부에서 선언 필요!
	Tile *startTile;
	Player *player;
	MoveThread *movethread;
	UseTime *time;
	MapObject* m;
	//NPC* npc;

public:
	Map *map;
	static Controller* getInstance();
	void init();
	void test_move();	//이동 테스트
	void Nextday();
	Player* getPlayer();
	MapObject getMapObject(int);
	void setMapObject(MapObject, int);
};
