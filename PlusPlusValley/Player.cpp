#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	cout << "�÷��̾� ����!" << endl;
	
}
<<<<<<< HEAD
 
=======


Player::~Player()
{
}

Player::Player(string name)
{
	this->name = name;
	Inventory* Inven = new Inventory();
}

Player::Player(Tile * totile)
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
>>>>>>> 22166ae2bc17a0dd7ae0f60436fbbd1f74e002a6
}
void Player:: InitInventory()
{
	this->inven = new Inventory();
	Item* ax = new Item(ItemType::TOOL, "ax");
	Item* crop = new Item(ItemType::TOOL, "crop");
<<<<<<< HEAD
	pInven->addItem(ax, 1);
	pInven->addItem(crop);
=======
>>>>>>> 22166ae2bc17a0dd7ae0f60436fbbd1f74e002a6
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
				cout << "������ ������" << endl;
			}
			else
			{
				cout << "������ �ֵѷ���" << endl;
			}
		}
		else if (firstitem->getName() == "crop")
		{
			if (target->getObject()->getObjectType() == stone)
			{
				cout << "���� �μ̴�." << endl;
			}
			else
			{
				cout << "��̸� �ֵѷ���" << endl;
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
			cout << "���� �Ѹ� �� �����ϴ�." << endl;
		}
	}
	else
	{
		cout << "�ƹ��ϵ� �Ͼ�� �ʾҴ�." << endl;
	}
	
}





