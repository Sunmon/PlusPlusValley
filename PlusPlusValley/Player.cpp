#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	// cout << "플레이어 생성!" << endl;
	
}

Player::~Player()
{
}


Player::Player(string name):Player()
{
	this->name = name;
}

Player::Player(Tile * totile):Player()
{
	this->setTile(totile);
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
void Player:: InitInventory()
{
	this->inven = new Inventory();
	Tool* ax = new Tool(TOOLTYPE::AX, "ax");
	Tool* sickle = new Tool(TOOLTYPE::SICKLE, "sickle");
	Tool* hammer = new Tool(TOOLTYPE::HAMMER, "hammer");


	//Item* ax = new Item(ItemType::TOOL, "ax");
	//Item* crop = new Item(ItemType::TOOL, "crop");
	//inven->addItem(crop);
	inven->addItem(ax, 1);
	inven->addItem(sickle);
	inven->setMoney(5000);

	this->onHand = hammer;
}

void Player::setInven(Inventory* inven)
{
	this->inven = inven;

}

void Player::setOnHand(Tool* item)
{
	this->onHand = item;
}

Tool* Player::getOnHand()
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
				MapObject* seed = new MapObject(harvest);
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


//임시로 만든 interact. 위에 저 ifelse 대신할거임. 
void Player::interact_temp()
{
	Tile* target = this->getTarget();
	/*if (target == NULL || target->getObject() == NULL)
	{
		cout << "아무것도 할 수 없다." << endl;
		return;
	}*/

	//손에 쥔 아이템에 맞는 행동을 한다
	this->action.interact(this->getTarget(), this->onHand);


}





