#include "Player.h"
#include <assert.h>
#include "Harvest.h"
using namespace std;


Player::Player()
{
	InitInventory();
	store = new Store();
	store->playerInven = this->getInven();
	// cout << "�÷��̾� ����!" << endl;

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
}
void Player::InitInventory()
{
	this->inven = new Inventory();
	Tool* ax = new Tool(TOOLTYPE::AX, "ax");
	Tool* sickle = new Tool(TOOLTYPE::SICKLE, "sickle");
	Tool* hammer = new Tool(TOOLTYPE::HAMMER, "hammer");
	Tool* sprinkle = new Tool(TOOLTYPE::SPRINKLE, "sprinkle");

	inven->addItem(ax, 1);
	inven->addItem(sickle);
	inven->setMoney(5000);

	Item* strawSeed = new Item(ItemType::SEED, "strawSeed");
	inven->addItem(strawSeed, 3);
	this->onHand = ax;
	//this->onHand = hammer;
	//this->onHand = strawSeed;
	//this->onHand = sprinkle;
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
//
//void Player::Interact()
//{
//
//	Item* firstitem = inven->getfirstItem();
//
//	Tile* target = this->getTarget();
//
//	if (target == NULL || target->getObject() == NULL)
//	{
//		cout << "�ƹ��͵� �� �� ����." << endl;
//	}
//	else
//	{
//		if (firstitem->getItemType() == TOOL)
//		{
//			if (firstitem->getName() == "ax")
//			{
//				if (target->getObject()->getObjectType() == tree)
//				{
//					cout << "������ ������" << endl;
//				}
//				else
//				{
//					cout << "������ �ֵѷ���" << endl;
//				}
//			}
//			else if (firstitem->getName() == "crop")
//			{
//				if (target->getObject()->getObjectType() == stone)
//				{
//					cout << "���� �μ̴�." << endl;
//				}
//				else
//				{
//					cout << "��̸� �ֵѷ���" << endl;
//				}
//			}
//		}
//		else if (firstitem->getItemType() == SEED)
//		{
//			if (target->getIsvalue() == false)
//			{
//				Harvest* seed = new Harvest(harvest, "����");
//				target->setObject(seed);
//			}
//			else
//			{
//				cout << "���� �Ѹ� �� �����ϴ�." << endl;
//			}
//		}
//		else
//		{
//			cout << "�ƹ��ϵ� �Ͼ�� �ʾҴ�." << endl;
//		}
//	}
//
//}

//�÷��̾ ������ �ִ� ������ �ٶ󺸰� �ִ� Ÿ�Ͽ� ���� ��ȣ�ۿ���
void Player::interact()
{
	//�÷��̾ ���� ������ Ÿ�� ����
	Tile* target = this->getTarget();
	if (onHand == nullptr || target == nullptr) return;

	//Ÿ���� npc�̸� gostore ����
	//�տ� ���⸦ ��� �־ ���� 
	if (target->getObject() != nullptr)
	{
		if (target->getObject()->getObjectType() == npc) {

			goStore();
			return;
		}
	}

	//���� ������� ������Ʈ �� ���̱� & �ı�
	//���� �����̶�� �� �Ѹ��� & ���� ���� ���̱�
	switch (onHand->getItemType())
	{
	case TOOL: doAction(onHand, target); break;
	case SEED: seeding(onHand, target); break;

	default: break;
	}
}


void Player::doAction(Item* tool, Tile* target)
{

	if (static_cast<Tool*>(tool)->toolType == SPRINKLE) { water(tool, target); return; }
	if (static_cast<Tool*>(tool)->toolType == FERTILIZE) { fertilize(tool, target); return; }

	if (target->getObject() == nullptr) return;
	std::string str[5] = { "������ ������", "���� �ν���", "�۹��� ��Ȯ�ߴ�", "���� �ѷȴ�", "��Ḧ �ѷȴ�" };

	if (static_cast<Tool*>(tool)->toolType != target->getObject()->getObjectType()) return;


	cout << "toolType: " << static_cast<Tool*>(tool)->toolType << " objectType: " << target->getObject()->getObjectType() << endl;

	reduce_MO_HP(target->getObject());

	if (target->getObject()->getHealth() <= 0)
	{
		for (auto& it : target->getObject()->getItemArray())
		{
			cout << it->getName() << endl;
			inven->addItem(it);
		}
		target->removeObj();
	}
}

void Player::goStore() {


	cout << "������� �����Դϴ�~!" << endl;
	int flag = 1;
	while (flag)
	{
		int input;
		cout << "\n\n1. ���� ����  2. ���� �Ǹ�  3. �ڷΰ���" << endl;
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

void Player::water(Item* tool, Tile* target)
{
		cout << "���� �ѷȽ��ϴ�. " << endl;

		//���� ���ֱ�
		target->setIsWet(true);
}
void Player::fertilize(Item* tool, Tile* target) {

	cout << "��Ḧ �ѷȽ��ϴ�." << endl;

	target->setFertilizer(true);
}

void Player::reduce_MO_HP(MapObject* mo)
{
	int hp = mo->getHealth();
	if (hp > 0)
	{
		mo->setHealth(hp-30);
		cout << "object hp: " << mo->getHealth() << endl;
	}
}


//�ָӴϿ��� ���� ���� ���� & Ÿ�Ͽ� �� �Ѹ��� 
void Player::seeding(Item* seed, Tile* target)
{
	//Ÿ�Ͽ� �� �Ѹ���
	inven->removeItem(seed);

	//���� ���� ����
	if (inven->findIter(seed) == inven->items.end())
	{
		cout << "������ �����ϴ�" << endl;  return;
	}
	//if (inven->findItem(seed) == NULL) return;
	cout << "������ �ѷȽ��ϴ�. ���� ����: " << seed->getName() << " " << inven->findIter(seed)->second << endl;

	if (target->getObject() != nullptr) return;
	string name = seed->getName();
	size_t pos = name.find("����");
	if (pos != string::npos)name.erase(pos, 2);
	MapObject* mo = new MapObject(ObjectType::harvest, name);
	target->setObject(mo);
}
