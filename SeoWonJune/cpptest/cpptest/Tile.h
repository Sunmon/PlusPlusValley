#pragma once
#include <map>
#include <vector>


using namespace std;

class Tile
{
private:
	int x;
	int y;
	bool canmove;
	bool isvalue;
	Tile* leftTile;
	Tile* rightTile;
	Tile* upTile;
	Tile* downTile;
public:
	Tile(int x, int y)
	{
		setxy(x, y);
	}
	void setxy(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setleft(Tile* toTIle)
	{
		this->leftTile = toTIle;
	}
	void setright(Tile* toTIle)
	{
		this->rightTile = toTIle;
	}
	void setup(Tile* toTIle)
	{
		this->upTile = toTIle;
	}
	void setdown(Tile* toTIle)
	{
		this->downTile = toTIle;
	}
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}
	Tile* getleft()
	{
		return this->leftTile;
	}
	Tile* getright()
	{
		return this->rightTile;
	}
	Tile* getup()
	{
		return this->upTile;
	}
	Tile* getdown()
	{
		return this->downTile;
	}

	bool getcanmove()
	{
		return this->canmove;
	}

};

class  Map
{
private:
	Tile* map[30][20];
	void setmap()
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				map[i][j] = new Tile(i, j);
				setright(i, j);
				setleft(i, j);
				setup(i, j);
				setdown(i, j);


			}
		}
	}

	void setright(int i, int j)
	{
		if (i == 30)
		{
			map[i][j]->setright(NULL);
		}
		else
		{
			map[i][j]->setright(map[i + 1][j]);
		}
	}
	void setleft(int i, int j)
	{
		if (i == 0)
		{
			map[i][j]->setleft(NULL);
		}
		else
		{
			map[i][j]->setleft(map[i - 1][j]);
		}

	}
	void setup(int i, int j)
	{
		if (j == 20)
		{
			map[i][j]->setup(NULL);
		}
		else
		{
			map[i][j]->setup(map[i][j + 1]);
		}
	}
	void setdown(int i, int j)
	{
		if (j == 0)
		{
			map[i][j]->setdown(NULL);
		}
		else
		{
			map[i][j]->setdown(map[i][j - 1]);
		}
	}
public:
	Map()
	{
		this->setmap();
	}
	Tile* gettile(int x, int y)
	{
		if (x >= 0 && x < 30 && y >= 0 && y < 20)
			return map[x][y];
	}
};

