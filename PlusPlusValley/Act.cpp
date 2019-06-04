#include "Act.h"

//map object와 tool별로 맞는 상호작용을 한 후 obj의 hp가 남았다면 true리턴
bool Act::interact(MapObject* mo, Tool* tool)
{
	std::string str[4] = { "나무를 베었다", "돌을 부쉈다", "작물을 수확했다", "씨를 뿌렸다" };
	cout << "toolType: " << tool->toolType << " objectType: " << mo->getObjectType() << endl;
	if (tool->toolType != mo->getObjectType()) return true;
	
	//TODO: object hp 삭제하거나 새 씨앗 놓기
	return reduceHP(mo);
}


//tile과 item별로 상호작용
void Act::interact(Tile* target, Tool* item)
{
	if (target == NULL || target->getObject() == NULL)
	{
		cout << "아무것도 할 수 없다." << endl;
		return;
	}

	//상호작용 후 타일 상태 재설정
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