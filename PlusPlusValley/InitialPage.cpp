#include "InitialPage.h"
#include <iostream>

using namespace std;



InitialPage::InitialPage()
{
}


InitialPage::~InitialPage()
{
}

void InitialPage::makePlayer()
{
	int button;

	while (true)
	{
		cout << "Player 이름 : ";
		cin >> name;
		cout << "이 이름으로 하시겠습니까?(확인: 1, 다시 설정: 2)" << endl;
		cin >> button;

		if (button == 1) break;
		if (button == 2) continue;
	}

	Player* player = new Player(name);
	cout << "이름 : " << player->getName() << "으(로) 플레이어 생성!" << endl;



}

void InitialPage::showInfoPlayer()
{
	//system("cls");
	Player* player = new Player(name);
	cout << "=======플레이어 정보=======" << endl;
	cout << "이름 : " << player->getName() << endl;
	cout << "체력: " << player->gethp() << endl;
	cout << "돈: " << endl << endl;
}

void InitialPage::menu()
{
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
			showInfoPlayer();
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		}


	}
}

int main(void) {

	InitialPage IP;
	IP.makePlayer();
	IP.showInfoPlayer();
	IP.menu();
}