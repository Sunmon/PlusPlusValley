#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif

#include <iomanip>
#include "MoveThread.h"
#include "Character.h"
#include "Player.h"
#include "Map.h"
#include "UseTime.h"
class Controller
{
private:
	Map *map;
	Tile *startTile;
	Player *player;
	MoveThread *movethread;
	UseTime *time;
public:
	Controller();
	~Controller();
	void init();
	void test_move();	//이동 테스트
	void setName(string);
	string getPlayerName();
	int getPlayerX();
	int getPlayerY();
	void setPlayerPlace(int);
};

