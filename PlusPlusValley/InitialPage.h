#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_INFO,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

class InitialPage {
private:
	string name;

public:
	InitialPage() {}
	void ShowInfoPlayer() {
		Player player;
		player.ShowInfo();
	}
	void MakePlayer() {

		Player player;
		cout << "Player �̸� : " << endl;
		getline(cin, name);
		player.setName(name);



		//Player ch = new Player(name);
	}
	void Menu() {
		while (true) {
			cout << "1. �÷��̾� ����" << endl;
			cout << "2. ����" << endl;
			cout << "3. �κ��丮" << endl;
			cout << "4. ����" << endl;
			cout << "�޴����� : " << endl;
			int iMenu;
			cin >> iMenu;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;

			}
			if (iMenu = MM_EXIT)
				break;

			switch (iMenu)
			{
			case MM_INFO:
				ShowInfoPlayer();
				break;
			case MM_STORE:
				break;
			case MM_INVENTORY:
				break;
			}
		}
	}
};


//Player �����ص� �� �� �𸣰ھ �ּ�ó���ؼ� �ø��ϴ�

//class Player : public Character
//{
//private:
//	string name;
//public:
//	Player() {}
//	void setName(string name) {
//		this->name = name;
//	}
//	string getName() {
//		return this->name;
//	}
//	Player(string name) {
//		this->name = name;
//	}
//	Player(int tox, int toy)
//	{
//		this->setx(tox);
//		this->sety(toy);
//	}
//	void ShowInfo() { //Player�� ���� ȣ��
//		cout << "�̸�" << getName() << endl;
//		cout << "ü��" << gethp() << endl << endl;
//	}
//	void act()
//	{
//		cout << "act" << endl;
//		where();
//	}
//	void ShowInventory() {
//		//Inventory inven = new Inventoty();
//	}
//};