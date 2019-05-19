#pragma once
#include <iostream>

using namespace std;

class character
{
private:
	int x;
	int y;
	int hp;


public:
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}
	void setx(int tox)
	{
		x = tox;
	}
	void sety(int toy)
	{
		y = toy;
	}
	int gethp()
	{
		return this->hp;
	}
	void where()
	{
		int wherex = this->getx();
		int wherey = this->gety();
		cout << "(" << wherex << "," << wherey << ")" << endl;
	}

	void move(int tomove)
	{
		if (tomove == 75)
		{
			this->setx(this->getx() - 1);
		}
		if (tomove == 77)
		{
			this->setx(this->getx() + 1);
		}
		if (tomove == 72)
		{
			this->sety(this->gety() + 1);
		}
		if (tomove == 80)
		{
			this->sety(this->gety() - 1);
		}

		this->where();
	}


};

class mainchara : public character
{
public:
	mainchara(int tox, int toy)
	{
		this->setx(tox);
		this->sety(toy);
	}
	void act()
	{
		cout << "act" << endl;
		where();
	}
};
