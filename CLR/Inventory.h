#pragma once
#include "Item.h"
#include "Tool.h"
#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
* �κ��丮�� �����ϴ� Ŭ����
* ��� ���:
*	items<Item*, num>:			������ ��� <������, ����>
*	addItem(Item*, num):		num��ŭ �κ��丮���� ������ �߰�. num�� ���ٸ� 1�� �߰�.
*	removeItem(Item*, num):		num��ŭ �κ��丮���� ������ ����. num�� ���ٸ� 1�� ����.
*	clearItem(Item*):			�ش� �������� �κ��丮���� ���� ���� & ������ ��ü���� ����
*	printItem():				������ ��� ���
*	findIter(name):				�̸����� �������� ã�� �� item pair�� iterator ����
* @author KIM SUN JUNG
* @date 2019.05.26
*/

class Inventory
{
private:
	int money;
public:
	Inventory();
	~Inventory();

	std::vector<pair<Item*, int> > items;


	void addItem(Item* item, int num = 1);
	//void addItem1(Panel p); //GUI��
	void removeItem(Item* item, int num = 1);
	void clearItem(Item* item);
	void printItems();
	void setMoney(int money);
	int getMoney();
	Item* getfirstItem();
	Item* findItem(string name);

	//std::map<Item*, int>::iterator findIter(string name);
	//std::map<Item*, int>::iterator itemIter;

	std::vector<pair<Item*, int>>::iterator findIter(Item* item);
	std::vector<pair<Item*, int>>::iterator itemIter;

	void saveinven()
	{
		ofstream ofs;
		ofs.open("./map.txt");
		if (!ofs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}
		ofs << money << endl;
		for (auto& item : items)
		{

			ofs << item.first->getItemType() << " " << item.first->getName() << " " << item.second << endl;

		}
			
		ofs.close();
	}




	void loadinven()
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
			if (type != "NULL")
			{
				
			}
		}

		ifs.close();
	}

};

