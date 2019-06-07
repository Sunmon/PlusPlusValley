#include "Act.h"

MapObject* Act::interact(MapObject* mo, Item* item)
{
	//tool이라면 cast
	if (item->getItemType() == TOOL)
	{
		std::string str[4] = { "나무를 베었다", "돌을 부쉈다", "작물을 수확했다", "씨를 뿌렸다" };
		cout << "toolType: " << static_cast<Tool*>(item)->toolType << " objectType: " << mo->getObjectType() << endl;
		if (static_cast<Tool*>(item)->toolType != mo->getObjectType()) return mo;
		return reduceHP(mo);
	}

	else if (item->getItemType() == SEED)
	{
		std::string str = "씨를 뿌렸다";
		cout << str << endl;
		mo = new Harvest(ObjectType::harvest, item->getName());

		//TODO: 씨앗 개수 줄이기
		return mo;
	}

	return mo;

}

void Act::interact(Tile* target, Item* item)
{
	if (target == NULL)
	{
		cout << "아무것도 할 수 없다." << endl;
		return;
	}

	//상호작용 후 타일 상태 재설정
	int isValid = interact(target->getObject(), item)->getHealth();

	if (isValid) return;
	target->removeObj();
	cout << "removed obj" << endl;
}


//mapobject의 체력을 감소. 부서지면 false 리턴
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