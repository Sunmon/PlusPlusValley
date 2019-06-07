#pragma once
#include "Tile.h"
#include <time.h>
#include <fstream>
#include "NPC.h"
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
		MapObject* stoneObject = new MapObject(stone, "��");
		MapObject* treeObject = new MapObject(tree, "����");
		NPC* npc = new NPC("����");

		srand((unsigned int)time(0));
		
		//npc�� ���� Ÿ�Ͽ� ��ġ��Ų��
		npc->setTile(map[3][4]);
		map[3][4]->setObject(new MapObject(ObjectType::npc, "����"));
		for (int i = 0; i < (rand() % 5 + 1); i++)
		{
			map[(rand() % MAX_X)][rand() % MAX_Y]->setObject(stoneObject);
			map[(rand() % MAX_X)][rand() % MAX_Y]->setObject(treeObject);
		}

		
	}

	void growth()
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			for (int i = 0; i < MAX_X; i++)
			{
				MapObject* tempobject = map[i][j]->getObject();
				if (tempobject->getObjectType() == harvest )
				{
					if (map[i][i]->getIsWet())
					{
						tempobject->growing();
					}
					
				}
				
			}
		}
		
	}

	void savemap()
	{
		ofstream ofs;
		ofs.open("./map.txt");
		if (!ofs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}
		for (int j = 0; j < MAX_Y; j++)
		{
			for (int i = 0; i < MAX_X; i++)
			{
				MapObject* tempobject = map[i][j]->getObject();
				if (tempobject == NULL)
				{
					ofs << i << " " << j << " " << "NULL" << " " << 0 << endl;
				}
				else
				{
					string str;
					switch (tempobject->getObjectType())
					{
					case tree:
						str = "tree";
						break;
					case stone:
						str = "stone";
						break;
					case harvest:
						str = "harvest";
						break;
					}
					ofs << i << " " << j << " " << str << " " << tempobject->getHealth() << endl;
				}
			}
		}
		ofs.close();
	}

	void loadmap()
	{
		ifstream ifs;
		ifs.open("./map.txt");
		if (!ifs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}

		int x, y;
		string type;
		int hp;
		while (ifs >> x >> y >> type >> hp)
		{
			if(type != "NULL")
			{
				MapObject* object = new MapObject();
				object->setHealth(hp);

				if (type == "tree")
				{
					object->setObjectType(tree);
				}
				if (type == "stone")
				{
					object->setObjectType(stone);
				}
				if (type == "harvest")
				{
					object->setObjectType(harvest);
				}
				
				map[x][y]->setObject(object);

				cout << "(" << x << ","<< y << ") " << ":" << type << " �ε�" << endl;
			}
		}

		ifs.close();
	}
};