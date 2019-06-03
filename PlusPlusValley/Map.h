#pragma once
#include "Tile.h"

class  Map
{
private:
	const static int MAX_Y = 20, MAX_X = 30;

	Tile* map[MAX_X][MAX_Y];

	//tile���� ������ �����Ѵ�. 
	void setmap()
	{
		//�ʱ�ȭ
		for (int j = 0; j < MAX_Y; j++)
			for (int i = 0; i < MAX_X; i++)
				map[i][j] = new Tile(i, j);

		//�� �� ��ũ
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


	}

	//Ȥ�� x y ���� Ʋ������� ���� �ּ�ó���ؼ� ���Ӵϴ�\
	//Tile* map[30][20];	
	/*void setmap()
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
	}*/
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
	void saveObject()
	{

	}
};