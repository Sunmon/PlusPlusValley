#include "NPC.h"
using namespace std;


NPC::NPC()
{
	store = new Store();

}

NPC::NPC(string name):NPC()
{
	this->name = name;
}


NPC::~NPC()
{
}

void NPC::setName(string name)
{
	this->name = name;
}

string NPC::getName()
{
	return this->name;
}

void NPC::goStore(Player* player)
{
	cout << "������� �����Դϴ�~!" << endl;

	int input;
	cout << "1. ���� ����  2. ���� �Ǹ�  3. �ڷΰ���" << endl;
	cin >> input;

	switch (input)
	{
	case 1:
		store->buyItem(player);
		break;
	case 2:
		store->sellItem(player);
		break;
	default:
		break;
	}



}

