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
	static Controller* instance;	//static ���� -> Ŭ���� �ܺο��� ���� �ʿ�!
	Map *map;
	Tile *startTile;
	Player *player;
	MoveThread *movethread;
	UseTime *time;
public:
	static Controller* getInstance();
	void init();
	void test_move();	//�̵� �׽�Ʈ
	void setName(string);
	string getPlayerName();
	int getPlayerX();
	int getPlayerY();
	void setPlayerPlace(int);
};
