#include "Act.h"

MapObject* Act::interact(MapObject* mo, Item* item)
{
	//tool�̶�� cast
	if (item->getItemType() == TOOL)
	{
		std::string str[4] = { "������ ������", "���� �ν���", "�۹��� ��Ȯ�ߴ�", "���� �ѷȴ�" };
		cout << "toolType: " << static_cast<Tool*>(item)->toolType << " objectType: " << mo->getObjectType() << endl;
		if (static_cast<Tool*>(item)->toolType != mo->getObjectType()) return mo;
		return reduceHP(mo);
	}

	else if (item->getItemType() == SEED)
	{
		std::string str = "���� �ѷȴ�";
		cout << str << endl;
		mo = new Harvest(ObjectType::harvest, item->getName());

		//TODO: ���� ���� ���̱�
		return mo;
	}

	return mo;

}

void Act::interact(Tile* target, Item* item)
{
	if (target == NULL)
	{
		cout << "�ƹ��͵� �� �� ����." << endl;
		return;
	}

	//��ȣ�ۿ� �� Ÿ�� ���� �缳��
	int isValid = interact(target->getObject(), item)->getHealth();

	if (isValid) return;
	target->removeObj();
	cout << "removed obj" << endl;
}


//mapobject�� ü���� ����. �μ����� false ����
MapObject* Act::reduceHP(MapObject* mo)
{
	int hp = mo->getHealth();
	if (hp > 0)
	{
		mo->setHealth(--hp);
		cout << "object hp: " << mo->getHealth() << endl;
	}
	return mo;
}