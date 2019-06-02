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
	//TODO: 인벤토리 아이템 채우기

	Item* stSeed = new Item(ItemType::SEED, "딸기씨앗");
	Item* wmSeed = new Item(ItemType::SEED, "수박씨앗");
	Item* caSeed = new Item(ItemType::SEED, "배추씨앗");

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

	cout << "---판매할 상품과 개수 선택";
	
	//플레이어가 가진 상품 개수 < 판매하려는 개수 false


}

void Store::buyItem(Player* player)
{


	//Inventory* playerInven = new Inventory();
	Inventory* playerInven = player->getInven();

	int item;
	int num;
	string itemName;
	cout << "---구입 할 상품과 개수를 선택하세요---" << endl;
	cout << " 1. 씨앗(SEED) 2. 수확작물(CROP) 3. 돌(STONE) 4. 나무(WOOD) 5. 도구(TOOL)" << endl;
	cin >> item >> num;
	cout << "아이템이름을 입력하세요(이름): 딸기씨앗 /수박씨앗 /배추씨앗";
	cin >> itemName;

	while (true)
	{
		cout << "현재 가진 돈 : ";
		playerInven->getMoney();

		Item* tempItem = storeInven->findItem(itemName);
		if (playerInven->getMoney()*num < tempItem->getCost()*num) {
			cout << "돈이 부족합니다!!" << endl;
			continue;
		}

		Item* newItem = new Item(*tempItem);
		playerInven->addItem(newItem,num);
		
		//플레이어 현재 소지금 - 물건 값
		int temp;
		temp = playerInven->getMoney();
		temp -= tempItem->getCost() * num;
		playerInven->setMoney(temp);
	}

	

}

