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

	//std::map<Item*, int> items;
	std::vector<pair<Item*, int> > items;


	void addItem(Item* item, int num = 1);
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
		ofs.open("./inven.txt");
		if (!ofs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}


		for (auto& item : items)
		{
			if (item.first->getItemType() == TOOL)
			{

				ofs << item.first->getItemType() << " " << item.first->getName() << " "
					<< ((Tool*)item.first)->gettooltype() << " " << item.second << endl;
			}
			else
			{
				ofs << item.first->getItemType() << " " << item.first->getName() << " "
					<< 0 << " " << item.second << endl;
			}
		}

		ofs.close();
		ofs.open("./money.txt");
		if (!ofs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}
		ofs << money << endl;
		ofs.close();
	}
	void loadinven()
	{
		ifstream ifs;
		ifs.open("./inven.txt");
		if (!ifs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}

		int type;
		string name;
		int tool;
		int num;



		while (ifs >> type >> name >> tool >> num)
		{
			if (tool != 0)
			{
				Tool* inventool = new Tool((TOOLTYPE)tool, name);
				addItem(inventool, num);

			}
			else
			{
				Item* invenitem = new Item((ItemType)type, name);
				addItem(invenitem, num);
			}
		}

		ifs.close();

		ifs.open("./money.txt");
		if (!ifs)
		{
			cout << "������ �� �� �����ϴ�." << endl;
			exit(0);
		}

		ifs >> money;
		ifs.close();
	}

};

