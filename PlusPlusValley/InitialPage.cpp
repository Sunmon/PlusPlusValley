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
		cout << "Player �̸� : ";
		cin >> name;
		cout << "�� �̸����� �Ͻðڽ��ϱ�?(Ȯ��: 1, �ٽ� ����: 2)" << endl;
		cin >> button;

		if (button == 1) break;
		if (button == 2) continue;
	}

	Player* player = new Player(name);
	cout << "�̸� : " << player->getName() << "��(��) �÷��̾� ����!" << endl;



}

void InitialPage::showInfoPlayer()
{
	//system("cls");
	Player* player = new Player(name);
	cout << "=======�÷��̾� ����=======" << endl;
	cout << "�̸� : " << player->getName() << endl;
	cout << "ü��: " << player->gethp() << endl;
	cout << "��: " << endl << endl;
}

void InitialPage::menu()
{
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