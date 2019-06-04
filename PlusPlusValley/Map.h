#pragma once
#include "Tile.h"
#include <time.h>

class  Map
{
private:
	const static int MAX_Y = 20, MAX_X = 30;

	Tile* map[MAX_X][MAX_Y];

	//tile간의 연결을 설정한다. 
	void setmap()
	{
		//초기화
		for (int j = 0; j < MAX_Y; j++)
			for (int i = 0; i < MAX_X; i++)
				map[i][j] = new Tile(i, j);

		//맵 간 링크
		for (int j = 0; j < MAX_Y; j++)
		{
			for (int i = 0; i < MAX_X; i++)
			{
				if (i > 0) map[i][j]->setleft(map[i - 1][j]);
				if (i < MAX_X - 1) map[i][j]->setright(map[i + 1][j]);
				if (j > 0) map[i][j]->setdown(map[i][j - 1]);
				if (j < MAX_Y - 1) map[i][j]->setup(map[i][j + 1]);
			}
		}

		initialmap();
	}

public:
	Map()
	{
		this->setmap();
	}
	Tile* gettile(int x, int y)
	{
		if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
			return map[x][y];
		else
			return NULL;
	}
	void	 saveObject()
	{
		
	}

	void initialmap()
	{
		MapObject* stoneObject = new MapObject(stone, "돌");
		MapObject* treeObject = new MapObject(tree, "나무");

		srand((unsigned int)time(0));

		for (int i = 0; i < (rand()%5 +1); i++)
		{
			map[(rand() % 20 + 1)][rand() % 30 + 1]->setObject(stoneObject);
			map[(rand() % 20 + 1)][rand() % 30 + 1]->setObject(treeObject);
		}
		
		/*map[3][4]->setObject(stoneObject);
		map[13][18]->setObject(treeObject);
		map[10][11]->setObject(&(*stoneObject));*/
	}
};