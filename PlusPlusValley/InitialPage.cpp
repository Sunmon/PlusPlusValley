#include "InitialPage.h"

enum MAIN_MENU {
	MM_NONE,
	MM_INFO,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

InitialPage::InitialPage()
{
}


InitialPage::~InitialPage()
{
}

void InitialPage::makePlayer()
{
	Player* player;
	cout << "Player �̸� : " << endl;
	getline(cin, name);
	player.setName(name);

}

void InitialPage::showInfoPlayer()
{
	Player* player;
	show

}

void InitialPage::Menu()
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
			ShowInfoPlayer();
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
			case MM_INFO;
				back;
		}
	}
}

int main() {
	InitialPage IP = new InitialPage;
	IP.makePlayer();
	IP.showInfoPlayer();
}
