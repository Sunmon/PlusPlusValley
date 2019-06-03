#include "Player.h"

using namespace std;


Player::Player()
{
	InitInventory();
	cout << "�÷��̾� ����!" << endl;
	
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





