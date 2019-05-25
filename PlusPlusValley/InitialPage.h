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
		cout << "Player 이름 : " << endl;
		getline(cin, name);
		player.setName(name);



		//Player ch = new Player(name);
	}
	void Menu() {
		while (true) {
			cout << "1. 플레이어 정보" << endl;
			cout << "2. 상점" << endl;
			cout << "3. 인벤토리" << endl;
			cout << "4. 종료" << endl;
			cout << "메뉴선택 : " << endl;
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


//Player 수정해도 될 지 모르겠어서 주석처리해서 올립니다

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
//	void ShowInfo() { //Player의 정보 호출
//		cout << "이름" << getName() << endl;
//		cout << "체력" << gethp() << endl << endl;
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