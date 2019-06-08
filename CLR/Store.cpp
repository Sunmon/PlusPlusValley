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
	//TODO: 인벤토리 아이템 채우기

	storeInven->addItem(makeItem(ItemType::SEED, "딸기씨앗", 50));
	storeInven->addItem(makeItem(ItemType::SEED, "수박씨앗", 80));
	storeInven->addItem(makeItem(ItemType::SEED, "배추씨앗", 150));

	storeInven->addItem(makeItem(ItemType::CROP, "딸기", 100));
	storeInven->addItem(makeItem(ItemType::CROP, "수박", 160));
	storeInven->addItem(makeItem(ItemType::CROP, "배추", 300));

	storeInven->addItem(makeItem(ItemType::STONE, "모래", 100));
	storeInven->addItem(makeItem(ItemType::STONE, "자갈", 200));
	storeInven->addItem(makeItem(ItemType::STONE, "바위", 500));

	storeInven->addItem(makeItem(ItemType::WOOD, "작은나무", 50));
	storeInven->addItem(makeItem(ItemType::WOOD, "중간나무", 80));
	storeInven->addItem(makeItem(ItemType::WOOD, "큰나무", 120));

	storeInven->addItem(makeItem(ItemType::TOOL, "호미", 50));
	storeInven->addItem(makeItem(ItemType::TOOL, "비료", 10));
	storeInven->addItem(makeItem(ItemType::TOOL, "물주전자", 20));
	storeInven->addItem(makeItem(ItemType::TOOL, "낫", 50));

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

	cout << "\n--------------------------판매할 상품을 선택하세요--------------------------" << endl;
	cin >> itemName;

	Item* selltemp = playerInven->findItem(itemName);

	if (selltemp == NULL) {
		system("cls");
		cout << "인벤토리에 상품이 없습니다!" << endl << endl;

		sellItem();
		return;
	}

	cout << "판매할 개수를 입력하세요 : ";
	cin >> num;

	//플레이어 인벤토리의 상품 개수 < 판매하려는 상품 개수이면 false
	if (playerInven->findIter(selltemp)->second < num) {
		system("cls");
		cout << "인벤토리에 상품이 부족합니다!" << endl << endl;
		sellItem();
		return;
	}



	//판매한 상품의 가격만큼 플레이어의 돈 증가
	int saletemp = playerInven->getMoney();
	saletemp += (selltemp->getCost()) * num;
	playerInven->setMoney(saletemp);

	cout << "\n아이템 가격:" << selltemp->getCost() * num << endl << endl;

	playerInven->removeItem(selltemp, num);



	playerInven->printItems();
	cout << "\n현재 가진 돈 : ";
	cout << playerInven->getMoney();
}

void Store::buyItem()
{
	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = this->getInven();

	int num;

	cout << "--------------------------구입 할 상품을 선택하세요--------------------------" << endl;
	cout << " 1. 씨앗(SEED) 2. 수확작물(CROP) 3. 돌(STONE) 4. 나무(WOOD) 5. 도구(TOOL)" << endl;
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
		cout << "잘못입력하셨습니다!" << endl;
		break;
	}
	playerInven->printItems();
	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();


}
void Store::buySeed() {

	Inventory* playerInven = new Inventory();
	//Inventory* playerInven = player->getInven();

	int itemNum;
	string itemName;

	cout << "아이템이름을 입력하세요(이름): 딸기씨앗 /수박씨앗 /배추씨앗 : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "아이템 이름을 잘못 입력하셨습니다" << endl << endl;
		buySeed();
		return;
	}

	cout << "아이템 개수를 입력하세요(숫자)";
	cin >> itemNum;

	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n아이템 가격:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "돈이 부족합니다!!" << endl;
		buyItem();
		return;
	}


	//buy 다른 방법
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

	cout << "씨앗을 구매했습니다!" << endl << endl;

	//플레이어 현재 소지금 - 물건 값
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

	cout << "아이템이름을 입력하세요(이름): 딸기 /수박 /배추 : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "아이템 이름을 잘못 입력하셨습니다" << endl << endl;
		buyCrop();
		return;
	}

	cout << "아이템 개수를 입력하세요(숫자)";
	cin >> itemNum;

	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n아이템 가격:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "돈이 부족합니다!!" << endl;
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

	cout << "수확작물을 구매했습니다!" << endl << endl;

	//플레이어 현재 소지금 - 물건 값
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

	cout << "아이템이름을 입력하세요(이름): 모래 /자갈 /바위 : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "아이템 이름을 잘못 입력하셨습니다" << endl << endl;
		buyStone();
		return;
	}

	cout << "아이템 개수를 입력하세요(숫자)";
	cin >> itemNum;

	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n아이템 가격:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "돈이 부족합니다!!" << endl;
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

	cout << "돌을 구매했습니다!" << endl << endl;

	//플레이어 현재 소지금 - 물건 값
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

	cout << "아이템이름을 입력하세요(이름): 작은나무 /중간나무 /큰나무 : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "아이템 이름을 잘못 입력하셨습니다" << endl << endl;
		buyWood();
		return;
	}

	cout << "아이템 개수를 입력하세요(숫자)";
	cin >> itemNum;

	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n아이템 가격:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "돈이 부족합니다!!" << endl;
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

	cout << "나무를 구매했습니다!" << endl << endl;

	//플레이어 현재 소지금 - 물건 값
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

	cout << "아이템이름을 입력하세요(이름): 호미 /비료 /물주전자 /낫 : ";
	cin >> itemName;

	Item* tempItem = storeInven->findItem(itemName);

	if (tempItem == NULL) {
		cout << "아이템 이름을 잘못 입력하셨습니다" << endl << endl;
		buyTool();
		return;
	}

	cout << "아이템 개수를 입력하세요(숫자)";
	cin >> itemNum;

	cout << "현재 가진 돈 : ";
	cout << playerInven->getMoney();
	cout << endl << endl;;



	cout << "\n아이템 가격:" << tempItem->getCost() * itemNum << endl << endl;

	if (playerInven->getMoney() < tempItem->getCost() * itemNum) {
		cout << "돈이 부족합니다!!" << endl;
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

	cout << "도구를 구매했습니다!" << endl << endl;

	//플레이어 현재 소지금 - 물건 값
	int temp;
	temp = playerInven->getMoney();
	temp -= tempItem->getCost() * itemNum;
	playerInven->setMoney(temp);

	cout << endl << endl;
}