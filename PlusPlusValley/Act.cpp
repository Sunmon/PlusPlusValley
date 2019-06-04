#include "Act.h"

//map object�� tool���� �´� ��ȣ�ۿ��� �� �� obj�� hp�� ���Ҵٸ� true����
bool Act::interact(MapObject* mo, Tool* tool)
{
	std::string str[4] = { "������ ������", "���� �ν���", "�۹��� ��Ȯ�ߴ�", "���� �ѷȴ�" };
	cout << "toolType: " << tool->toolType << " objectType: " << mo->getObjectType() << endl;
	if (tool->toolType != mo->getObjectType()) return true;
	
	//TODO: object hp �����ϰų� �� ���� ����
	return reduceHP(mo);
}


//tile�� item���� ��ȣ�ۿ�
void Act::interact(Tile* target, Tool* item)
{
	if (target == NULL || target->getObject() == NULL)
	{
		cout << "�ƹ��͵� �� �� ����." << endl;
		return;
	}

	//��ȣ�ۿ� �� Ÿ�� ���� �缳��
	bool isValid = interact(target->getObject(),item);
	if (isValid) return;
	target->removeObj();
	cout << "removed obj" << endl;
}

bool Act::reduceHP(MapObject* mo)
{
	int hp = mo->getHealth();
	if (--hp > 0)
	{
		mo->setHealth(hp);
		cout << "object hp: " << mo->getHealth() << endl;
		return true;
	}
	return false;
}