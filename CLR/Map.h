#pragma once
#include "Tile.h"
#include "Harvest.h"
#include <time.h>
#include <fstream>
//#include "NPC.h"
class  Map
{
private:

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
	//const static int MAX_Y = 300, MAX_X = 500;
	const static int MAX_Y = 30, MAX_X = 50;

	Tile* map[MAX_X][MAX_Y];

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
		
		//npc를 맵 오브젝트로 설정
		srand((unsigned int)time(NULL));
		MapObject* npcObject = new MapObject(npc, "상인");
		map[(rand() % MAX_X)][rand() % MAX_Y]->setObject(npcObject);

		//map object를 맵에 랜덤으로 설정
		MapObject* stoneObject = new MapObject(stone, "돌");
		MapObject* treeObject = new MapObject(tree, "나무");

		setObjToMap(*stoneObject);
		setObjToMap(*treeObject);

		//맵 가운데에 농사 가능한 곳 두기
		for (int i = MAX_X / 2 - MAX_X / 4; i < MAX_X / 2 + MAX_X / 4; i++)
		{
			for (int j = MAX_Y / 2 - MAX_Y / 4; j < MAX_Y / 2 + MAX_Y / 4; j++)
			{
				map[i][j]->setCanSeed(true);
			}
		}

	}

	//오브젝트 깊은 복사
	void setObjToMap(MapObject& mo)
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < (rand() % 5 + 5); i++) {
			int x = (rand() % MAX_X);
			int y = (rand() % MAX_Y);

			MapObject* m = new MapObject((ObjectType)mo.getObjectType(), mo.name);
			map[x][y]->setObject(m);
		}
	}




	void growth()
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			for (int i = 0; i < MAX_X; i++)
			{
				Harvest* tempobject = map[i][j]->getHarvest();
				if (tempobject != NULL)
				
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
			cout << "파일을 열 수 없습니다." << endl;
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
			cout << "파일을 열 수 없습니다." << endl;
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

				cout << "(" << x << ","<< y << ") " << ":" << type << " 로드" << endl;
			}
		}

		ifs.close();
	}
};