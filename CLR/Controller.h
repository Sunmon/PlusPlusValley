#pragma once
#include <iomanip>
#include "MoveThread.h"
#include "Character.h"
#include "Player.h"
#include "Map.h"
#include "UseTime.h"
#include "InitialPage.h"

class Controller
{
private:
	Controller();
	~Controller();
	static Controller* instance;	//static 변수 -> 클래스 외부에서 선언 필요!
	Map *map;
	Tile *startTile;
	Player *player;
	MoveThread *movethread;
	UseTime *time;
public:
	static Controller* getInstance();
	void init();
	void test_move();	//이동 테스트
	void setName(string);
	string getPlayerName();
	int getPlayerX();
	int getPlayerY();
	void setPlayerPlace(int);
};
