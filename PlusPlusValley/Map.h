#pragma once
#include "Tile.h"

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
				if (i == 0)
				{
					map[i][j]->setleft(NULL);
				}
				else
				{
					map[i][j]->setleft(map[i - 1][j]);
				}
				if (i == 30)
				{
					map[i][j]->setright(NULL);
				}
				else
				{
					map[i][j]->setright(map[i + 1][j]);
				}
				map[i][j]->setup(map[i][j + 1]);
				if (j == 20)
				{
					map[i][j]->setup(NULL);
				}
				else
				{
					map[i][j]->setdown(map[i][j + 1]);
				}
				if (j == 0)
				{
					map[i][j]->setdown(NULL);
				}
				else
				{
					map[i][j]->setdown(map[i][j - 1]);
				}

			}
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
		else
			return NULL;
	}
};