#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <process.h>
#include "character.h"
#include <conio.h>


using namespace std;

class MoveThread
{
private:
	mainchara* chara;
	void move()
	{
		int getkey = _getch();
		if (getkey == 72)
		{
			chara->move(72);
		}
		if (getkey == 75)
		{
			chara->move(75);
		}
		if (getkey == 77)
		{
			chara->move(77);
		}
		if (getkey == 80)
		{
			chara->move(80);
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
	void test()
	{
		cout << "check" << endl;
	}
	MoveThread(mainchara* chara)
	{
		this->chara = chara;
	}
	void start()
	{
		_beginthreadex(NULL, 0, move, this, 0, NULL);

	}

};
