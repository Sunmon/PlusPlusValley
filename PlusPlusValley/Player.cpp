#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	cout << "플레이어 생성!" << endl;
	
}
 
}
void Player:: InitInventory()
{
	this->inven = new Inventory();
	Item* ax = new Item(ItemType::TOOL, "ax");
	Item* crop = new Item(ItemType::TOOL, "crop");
	pInven->addItem(ax, 1);
	pInven->addItem(crop);
	inven->addItem(ax, 1);
	inven->addItem(crop);
	inven->setMoney(5000);
}

void Player::setInven(Inventory* inven)
{
	this->inven = inven;

}

Inventory* Player::getInven()
{
	return this->inven;
}

void Player::Interact()
{

	Item* firstitem = inven->getfirstItem();
	Tile* target = this->getTarget();
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





