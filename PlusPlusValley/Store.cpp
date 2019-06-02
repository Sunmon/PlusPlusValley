#include "Store.h"

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

	Item* stSeed = new Item(ItemType::SEED, "���⾾��");
	Item* wmSeed = new Item(ItemType::SEED, "���ھ���");
	Item* caSeed = new Item(ItemType::SEED, "���߾���");

	stSeed->setCost(100);
	wmSeed->setCost(150);
	caSeed->setCost(200);

	storeInven->addItem(stSeed, 99);
	storeInven->addItem(wmSeed);
	storeInven->addItem(caSeed);

}

void Store::showItemList() {

	storeInven->printItems();
}

void Store::sellItem( Player* player)
{

	//Inventory* playerInven = new Inventory();
	Inventory* playerInven = player->getInven();

	playerInven->printItems();

	cout << "---�Ǹ��� ��ǰ�� ���� ����";
	
	//�÷��̾ ���� ��ǰ ���� < �Ǹ��Ϸ��� ���� false


}

void Store::buyItem(Player* player)
{


	//Inventory* playerInven = new Inventory();
	Inventory* playerInven = player->getInven();

	int item;
	int num;
	string itemName;
	cout << "---���� �� ��ǰ�� ������ �����ϼ���---" << endl;
	cout << " 1. ����(SEED) 2. ��Ȯ�۹�(CROP) 3. ��(STONE) 4. ����(WOOD) 5. ����(TOOL)" << endl;
	cin >> item >> num;
	cout << "�������̸��� �Է��ϼ���(�̸�): ���⾾�� /���ھ��� /���߾���";
	cin >> itemName;

	while (true)
	{
		cout << "���� ���� �� : ";
		playerInven->getMoney();

		Item* tempItem = storeInven->findItem(itemName);
		if (playerInven->getMoney()*num < tempItem->getCost()*num) {
			cout << "���� �����մϴ�!!" << endl;
			continue;
		}

		Item* newItem = new Item(*tempItem);
		playerInven->addItem(newItem,num);
		
		//�÷��̾� ���� ������ - ���� ��
		int temp;
		temp = playerInven->getMoney();
		temp -= tempItem->getCost() * num;
		playerInven->setMoney(temp);
	}

	

}

