#include "Player.h"
#include <assert.h>
#include "Harvest.h"
using namespace std;


Player::Player()
{
	store = new Store();
	InitInventory();
	// cout << "플레이어 생성!" << endl;

}

Player::~Player()
{
}


Player::Player(string name) :Player()
{
	this->name = name;
}

Player::Player(Tile* totile) : Player()
{
	this->setTile(totile);
}

//Player* Player::getInstance()
//{
//	if (inst == nullptr) {
//		inst == new Player();
//	}
//	return inst; 
//}

void Player::test()
{
	cout << "singleton test" << endl;
}

void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return this->name;
}

void Player::act()
{
	cout << "act" << endl;
	where();
}
void Player::InitInventory()
{
	this->inven = new Inventory();
	Tool* ax = new Tool(TOOLTYPE::AX, "ax");
	Tool* sickle = new Tool(TOOLTYPE::SICKLE, "sickle");
	Tool* hammer = new Tool(TOOLTYPE::HAMMER, "hammer");


	//Item* ax = new Item(ItemType::TOOL, "ax");
	//Item* crop = new Item(ItemType::TOOL, "crop");
	inven->addItem(ax, 1);
	inven->addItem(sickle);
	inven->setMoney(5000);

	Item* strawSeed = new Item(ItemType::SEED, "strawSeed");
	inven->addItem(strawSeed, 3);
	this->onHand = hammer;
	//this->onHand = strawSeed;
}

void Player::setInven(Inventory* inven)
{
	this->inven = inven;

}



void Player::setOnHand(Item* item)
{
	this->onHand = item;
}

Item* Player::getOnHand()
{
	return this->onHand;
}

Inventory* Player::getInven()
{
	return this->inven;
}

void Player::Interact()
{

	Item* firstitem = inven->getfirstItem();

	Tile* target = this->getTarget();

	if (target == NULL || target->getObject() == NULL)
	{
		cout << "아무것도 할 수 없다." << endl;
	}
	else
	{
		if (firstitem->getItemType() == TOOL)
		{
			if (firstitem->getName() == "ax")
			{
				if (target->getObject()->getObjectType() == tree)
				{
					cout << "나무를 베었다" << endl;
				}
				else
				{
					cout << "도끼를 휘둘렀다" << endl;
				}
			}
			else if (firstitem->getName() == "crop")
			{
				if (target->getObject()->getObjectType() == stone)
				{
					cout << "돌을 부셨다." << endl;
				}
				else
				{
					cout << "곡갱이를 휘둘렀다" << endl;
				}
			}
		}
		else if (firstitem->getItemType() == SEED)
		{
			if (target->getIsvalue() == false)
			{
				Harvest* seed = new Harvest(harvest, "씨앗");
				target->setObject(seed);
			}
			else
			{
				cout << "씨를 뿌릴 수 없습니다." << endl;
			}
		}
		else
		{
			cout << "아무일도 일어나지 않았다." << endl;
		}
	}

}




//플레이어가 가지고 있는 도구와 바라보고 있는 타일에 따라 상호작용함
void Player::interact()
{
	//플레이어가 가진 도구와 타일 얻음
	Tile* target = this->getTarget();
	if (onHand == nullptr || target == nullptr) return;

	//타겟이 npc이면 gostore 실행
	//손에 무기를 들고 있어도 실행 
	if (target->getObject() != nullptr)
	{
		if (target->getObject()->getObjectType() == npc) {

			goStore();
			return;
		}
	}

	/*if (target->getNPC() !=NULL) {
		target->getNPC()->goStore(this);
	}*/

	//if (target->getObject()->getObjectType() == npc) {
	//	target->getNPC.goStore(this);
	//}

	//MapObject* & mo = target->getObject();

	//툴이 도구라면 오브젝트 피 줄이기 & 파괴
	//툴이 씨앗이라면 씨 뿌리기 & 씨앗 개수 줄이기
	switch (onHand->getItemType())
	{
	case TOOL: doAction(onHand, target); break;
	case SEED: seeding(onHand, target); break;

	default: break;
	}
}


void Player::doAction(Item* tool, Tile* target)
{

	if (target->getObject() == nullptr) return;
	std::string str[4] = { "나무를 베었다", "돌을 부쉈다", "작물을 수확했다", "씨를 뿌렸다" };

	cout << "toolType: " << static_cast<Tool*>(tool)->toolType << " objectType: " << target->getObject()->getObjectType() << endl;
	if (static_cast<Tool*>(tool)->toolType != target->getObject()->getObjectType()) return;

	reduce_MO_HP(target->getObject());

	if (target->getObject()->getHealth() <= 0)
	{
		//TODO: 아이템들 옮기기
		for (auto& it : target->getObject()->getItemArray())
		{

			cout << it->getName() << endl;
			inven->addItem(it);
			//cout << target->getObject()->getItemArray()[i]->getName() << endl;
			//inven->addItem(target->getObject()->getItemArray()[i]);

		}
		/*
				for (int i = 0; i < 3; i++)
				{
					if (target->getObject()->getItemArray()[i] == NULL) continue;
					cout << target->getObject()->getItemArray()[i]->getName() << endl;
					inven->addItem(target->getObject()->getItemArray()[i]);
				}*/
		target->removeObj();
	}
}

void Player::goStore() {


	cout << "어서오세요 상점입니다~!" << endl;
	int flag = 1;
	while (flag)
	{
		int input;
		cout << "\n\n1. 물건 구매  2. 물건 판매  3. 뒤로가기" << endl;
		cin >> input;
		cout << input << endl;
		switch (input)
		{
		case 1:
			store->buyItem();
			break;
		case 2:
			store->sellItem();
			break;
		default:
			flag = 0;
			break;
		}
	}
}

void Player::reduce_MO_HP(MapObject* mo)
{
	int hp = mo->getHealth();
	if (hp > 0)
	{
		mo->setHealth(--hp);
		cout << "object hp: " << mo->getHealth() << endl;
	}
}


//주머니에서 씨앗 개수 감소 & 타일에 씨 뿌리기 
void Player::seeding(Item* seed, Tile* target)
{
	//씨앗 개수 감소
	inven->removeItem(seed);
	if (inven->findIter(seed) == inven->items.end())
	{
		cout << "씨앗이 없습니다" << endl;  return;
	}
	//if (inven->findItem(seed) == NULL) return;
	cout << "씨앗을 뿌렸습니다. 남은 씨앗: " << seed->getName() << " " << inven->findIter(seed)->second << endl;

	//타일에 씨 뿌리기
	if (target->getObject() != nullptr) return;
	string name = seed->getName();
	size_t pos = name.find("씨앗");
	if (pos != string::npos)name.erase(pos, 2);
	MapObject* mo = new MapObject(ObjectType::harvest, name);
	target->setObject(mo);
}
