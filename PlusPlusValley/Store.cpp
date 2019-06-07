#include "Store.h"
#include <string>

using namespace std;

Store::Store()
{
	InitInventoty();

}


Store::~Store()
{
}

void Store::InitInventoty()
{
	storeInven = new Inventory();
	//TODO: �κ��丮 ������ ä���

	storeInven->addItem(makeItem(ItemType::SEED, "���⾾��", 50));
	storeInven->addItem(makeItem(ItemType::SEED, "���ھ���", 80));
	storeInven->addItem(makeItem(ItemType::SEED, "���߾���", 150));

	storeInven->addItem(makeItem(ItemType::CROP, "����", 100));
	storeInven->addItem(makeItem(ItemType::CROP, "����", 160));
	storeInven->addItem(makeItem(ItemType::CROP, "����", 300));

	storeInven->addItem(makeItem(ItemType::STONE, "��", 100));
	storeInven->addItem(makeItem(ItemType::STONE, "�ڰ�", 200));
	storeInven->addItem(makeItem(ItemType::STONE, "����", 500));

	storeInven->addItem(makeItem(ItemType::WOOD, "��������", 50));
	storeInven->addItem(makeItem(ItemType::WOOD, "�߰�����", 80));
	storeInven->addItem(makeItem(ItemType::WOOD, "ū����", 120));

	storeInven->addItem(makeItem(ItemType::TOOL, "ȣ��", 50));
	storeInven->addItem(makeItem(ItemType::TOOL, "���", 10));
	storeInven->addItem(makeItem(ItemType::TOOL, "��������", 20));
	storeInven->addItem(makeItem(ItemType::TOOL, "��", 50));

}

Item* Store::makeItem(ItemType itemType, const string& itemName, int cost) {

	Item* item = new Item(itemType, itemName);
	item->setCost(cost);

	return item;
}


void Store::showItemList() {

	storeInven->printItems();
}

void Store::sellItem(Player* player)
{
	//Inventory* playerInven = new Inventory();
	Inventory* playerInven = player->getInven();

	playerInven->printItems();

	int num;
	string itemName;

	cout << "\n--------------------------�Ǹ��� ��ǰ�� �����ϼ���--------------------------" << endl;
	cin >> itemName;

	Item* selltemp = playerInven->findItem(itemName);

	if (selltemp == NULL) {
		system("cls");
		cout << "�κ��丮�� ��ǰ�� �����ϴ�!" << endl << endl;

		sellItem(player);
		return;
	}

	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> num;

	//�÷��̾� �κ��丮�� ��ǰ ���� < �Ǹ��Ϸ��� ��ǰ �����̸� false
	if (playerInven->findIter(selltemp)->second < num) {
		system("cls");
		cout << "�κ��丮�� ��ǰ�� �����մϴ�!" << endl << endl;
		sellItem(player);
		return;
	}



	//�Ǹ��� ��ǰ�� ���ݸ�ŭ �÷��̾��� �� ����
	int saletemp = playerInven->getMoney();
	saletemp += (selltemp->getCost()) * num;
	playerInven->setMoney(saletemp);

	cout << "\n������ ����:" << selltemp->getCost() * num << endl << endl;

	playerInven->removeItem(selltemp, num);



	playerInven->printItems();
	cout << "\n���� ���� �� : ";
	cout << playerInven->getMoney();
}

void Store::buyItem(Player* player)
{
	//Inventory* playerInven = new Inventory();
	Inventory* playerInven = player->getInven();

	int num;

	cout << "--------------------------���� �� ��ǰ�� �����ϼ���--------------------------" << endl;
	cout << " 1. ����(SEED) 2. ��Ȯ�۹�(CROP) 3. ��(STONE) 4. ����(WOOD) 5. ����(TOOL)" << endl;
	cin >> num;
	system("cls");

	switch (num) {
	case 1:
		buySeed(player);
		break;
	case 2:
		buyCrop(player);
		break;
	case 3:
		buyStone(player);
		break;
	case 4:
		buyWood(player);
		break;
	case 5:
		buyTool(player);
		break;
	default:
		cout << "�߸��Է��ϼ̽��ϴ�!" << endl;
		break;
	}
	playerInven->printItems();
	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();


}
void Store::buySeed(Player* player) {

	Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ���⾾�� /���ھ��� /���߾��� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buySeed(player);
		return;
	}

	cout << "������ ������ �Է��ϼ���(����)";
	cin >> itemNum;

	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n������ ����:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "���� �����մϴ�!!" << endl;
		buyItem(player);
		return;
	}


	//buy �ٸ� ���
	//playerInven->itemIter = playerInven->findIter(itemName);
	//if (playerInven->itemIter != playerInven->items.end())
	//{
	//	playerInven->itemIter->second += itemNum;
	//}
	//else
	//{
	//	playerInven->addItem(new Item(*tempItem), itemNum);
	//}


	Item* newItem = playerInven->findItem(itemName);
	if (newItem != NULL)
	{
		playerInven->findIter(newItem)->second += itemNum;

	}
	else {

		newItem = new Item(*tempItem);
		playerInven->addItem(newItem, itemNum);
	}

	cout << "������ �����߽��ϴ�!" << endl << endl;

	//�÷��̾� ���� ������ - ���� ��
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}

void Store::buyCrop(Player* player)
{
	Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ���� /���� /���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyCrop(player);
		return;
	}

	cout << "������ ������ �Է��ϼ���(����)";
	cin >> itemNum;

	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n������ ����:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "���� �����մϴ�!!" << endl;
		buyItem(player);
		return;
	}


	Item* newItem = playerInven->findItem(itemName);
	if (newItem != NULL)
	{
		playerInven->findIter(newItem)->second += itemNum;

	}
	else {

		newItem = new Item(*tempItem);
		playerInven->addItem(newItem, itemNum);
	}

	cout << "��Ȯ�۹��� �����߽��ϴ�!" << endl << endl;

	//�÷��̾� ���� ������ - ���� ��
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}

void Store::buyStone(Player* player)
{
	Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): �� /�ڰ� /���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyStone(player);
		return;
	}

	cout << "������ ������ �Է��ϼ���(����)";
	cin >> itemNum;

	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n������ ����:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "���� �����մϴ�!!" << endl;
		buyItem(player);
		return;
	}

	Item* newItem = playerInven->findItem(itemName);
	if (newItem != NULL)
	{
		playerInven->findIter(newItem)->second += itemNum;

	}
	else {

		newItem = new Item(*tempItem);
		playerInven->addItem(newItem, itemNum);
	}

	cout << "���� �����߽��ϴ�!" << endl << endl;

	//�÷��̾� ���� ������ - ���� ��
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}

void Store::buyWood(Player* player)
{
	Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): �������� /�߰����� /ū���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyWood(player);
		return;
	}

	cout << "������ ������ �Է��ϼ���(����)";
	cin >> itemNum;

	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n������ ����:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "���� �����մϴ�!!" << endl;
		buyItem(player);
		return;
	}

	Item* newItem = playerInven->findItem(itemName);
	if (newItem != NULL)
	{
		playerInven->findIter(newItem)->second += itemNum;

	}
	else {

		newItem = new Item(*tempItem);
		playerInven->addItem(newItem, itemNum);
	}

	cout << "������ �����߽��ϴ�!" << endl << endl;

	//�÷��̾� ���� ������ - ���� ��
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}

void Store::buyTool(Player* player)
{
	Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ȣ�� /��� /�������� /�� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyTool(player);
		return;
	}

	cout << "������ ������ �Է��ϼ���(����)";
	cin >> itemNum;

	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n������ ����:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "���� �����մϴ�!!" << endl;
		buyItem(player);
		return;
	}

	Item* newItem = playerInven->findItem(itemName);
	if (newItem != NULL)
	{
		playerInven->findIter(newItem)->second += itemNum;

	}
	else {

		newItem = new Item(*tempItem);
		playerInven->addItem(newItem, itemNum);
	}

	cout << "������ �����߽��ϴ�!" << endl << endl;

	//�÷��̾� ���� ������ - ���� ��
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}




