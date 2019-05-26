#pragma once
/**
* Item�� �����ϴ� Ŭ����
* ��� ���:
* @author KIM SUN JUNG
* @date 2019.05.26
*/
#include <string>

class Item
{
public:
	enum ItemType {SEED, CROP, STONE, WOOD, TOOL};	//������ Ÿ��. ����, ��Ȯ�۹�, ��, ����, ����
	Item();
	Item(enum ItemType, const std::string& name);
	~Item();
	ItemType itemType;
	void setName(const std::string& name);
	void setMAX_NUM(int num);
	void setCost(int cost);
	void setItemType(ItemType itemType);
	ItemType getItemType();
	int getMAX_NUM();
	int getCost();
	std::string& getName();
	

private:
	int MAX_NUM = -1;	//�����ۺ� ���� �� �ִ� �ִ� ��
	int cost = -1;
	std::string name;
};