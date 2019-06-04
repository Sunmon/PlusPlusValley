#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	// cout << "�÷��̾� ����!" << endl;
	
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
		cout << "�ƹ��͵� �� �� ����." << endl;
	}
	else
	{
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
}


//�ӽ÷� ���� interact. ���� �� ifelse ����Ұ���. 
void Player::interact_temp()
{
	Tile* target = this->getTarget();
	/*if (target == NULL || target->getObject() == NULL)
	{
		cout << "�ƹ��͵� �� �� ����." << endl;
		return;
	}*/

	//�տ� �� �����ۿ� �´� �ൿ�� �Ѵ�
	this->action.interact(this->getTarget(), this->onHand);


}





