#include "Act.h"

//map object와 tool별로 맞는 상호작용
void Act::interact(MapObject* mo, Tool* tool)
{
	std::string str[4] = { "나무를 베었다", "돌을 부쉈다", "작물을 수확했다", "씨를 뿌렸다" };

	//FIXME: tooltype 맞냐
	cout << "toolType: " << tool->toolType << " objectType: " << mo->getObjectType() << endl;
	if (tool->toolType != mo->getObjectType()) return;
	
	//TODO: map에서 object 삭제하거나 놓기
	cout << str[tool->toolType] << endl;
}


//tile과 item별로 상호작용
void Act::interact(Tile* target, Tool* item)
{
	if (target == NULL || target->getObject() == NULL)
	{
		cout << "아무것도 할 수 없다." << endl;
		return;
	}

	//tool인 경우
	interact(target->getObject(),item);
}
