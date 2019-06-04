#include "Act.h"

//map object�� tool���� �´� ��ȣ�ۿ�
void Act::interact(MapObject* mo, Tool* tool)
{
	std::string str[4] = { "������ ������", "���� �ν���", "�۹��� ��Ȯ�ߴ�", "���� �ѷȴ�" };

	//FIXME: tooltype �³�
	cout << "toolType: " << tool->toolType << " objectType: " << mo->getObjectType() << endl;
	if (tool->toolType != mo->getObjectType()) return;
	
	//TODO: map���� object �����ϰų� ����
	cout << str[tool->toolType] << endl;
}


//tile�� item���� ��ȣ�ۿ�
void Act::interact(Tile* target, Tool* item)
{
	if (target == NULL || target->getObject() == NULL)
	{
		cout << "�ƹ��͵� �� �� ����." << endl;
		return;
	}

	//tool�� ���
	interact(target->getObject(),item);
}
