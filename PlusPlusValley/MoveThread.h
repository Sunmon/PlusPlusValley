#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <process.h>
#include "Player.h"
#include <conio.h>


using namespace std;

class MoveThread
{
private:
	Player* player;
	void move()
	{
		int getkey = _getch();

		if (getkey == 72)
		{
			player->move(72);
		}
		if (getkey == 75)
		{
			player->move(75);
		}
		if (getkey == 77)
		{
			player->move(77);
		}
		if (getkey == 80)
		{
			player->move(80);
		}
		if (getkey == 32)
		{
			player->Interact();
		}
	}
	static unsigned int __stdcall move(void* arg)
	{
		while (true)
		{

			MoveThread* movethread = (MoveThread*)arg;
			movethread->move();

		}
	}

public:
	MoveThread(){}
	void test()
	{
		cout << "check" << endl;
	}
	
	MoveThread(Player* player)
	{
		this->player = player;
	}
	void start()
	{
		_beginthreadex(NULL, 0, move, this, 0, NULL);

	}

};
