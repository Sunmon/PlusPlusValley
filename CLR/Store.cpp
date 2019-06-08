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

void Store::sellItem()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = this->getInven();

	playerInven->printItems();

	int num;
	string itemName;

	cout << "\n--------------------------�Ǹ��� ��ǰ�� �����ϼ���--------------------------" << endl;
	cin >> itemName;

	Item* selltemp = playerInven->findItem(itemName);

	if (selltemp == NULL) {
		system("cls");
		cout << "�κ��丮�� ��ǰ�� �����ϴ�!" << endl << endl;

		sellItem();
		return;
	}

	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> num;

	//�÷��̾� �κ��丮�� ��ǰ ���� < �Ǹ��Ϸ��� ��ǰ �����̸� false
	if (playerInven->findIter(selltemp)->second < num) {
		system("cls");
		cout << "�κ��丮�� ��ǰ�� �����մϴ�!" << endl << endl;
		sellItem();
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

void Store::buyItem()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = this->getInven();

	int num;

	cout << "--------------------------���� �� ��ǰ�� �����ϼ���--------------------------" << endl;
	cout << " 1. ����(SEED) 2. ��Ȯ�۹�(CROP) 3. ��(STONE) 4. ����(WOOD) 5. ����(TOOL)" << endl;
	cin >> num;
	system("cls");

	switch (num) {
	case 1:
		buySeed();
		break;
	case 2:
		buyCrop();
		break;
	case 3:
		buyStone();
		break;
	case 4:
		buyWood();
		break;
	case 5:
		buyTool();
		break;
	default:
		cout << "�߸��Է��ϼ̽��ϴ�!" << endl;
		break;
	}
	playerInven->printItems();
	cout << "���� ���� �� : ";
	cout << playerInven->getMoney();


}
void Store::buySeed() {

	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ���⾾�� /���ھ��� /���߾��� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buySeed();
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
		buyItem();
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

void Store::buyCrop()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ���� /���� /���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyCrop();
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
		buyItem();
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

void Store::buyStone()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = this->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): �� /�ڰ� /���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyStone();
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
		buyItem();
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

void Store::buyWood()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = this->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): �������� /�߰����� /ū���� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyWood();
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
		buyItem();
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

void Store::buyTool()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "�������̸��� �Է��ϼ���(�̸�): ȣ�� /��� /�������� /�� : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "������ �̸��� �߸� �Է��ϼ̽��ϴ�" << endl << endl;
		buyTool();
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
		buyItem();
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