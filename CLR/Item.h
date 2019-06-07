#pragma once
#include <string>

/**
* Item�� �����ϴ� Ŭ����
* ��� ���:
*	Item(ItemType, name)���� �ν��Ͻ� ����
*	ItemType:	������ Ÿ�� ������.
*	item�� �ִ� ����, ���� ���� �ʿ� (MAX_NUM, cost)
*	item�� �̸� ���� �ʿ�
* @author KIM SUN JUNG
* @date 2019.05.26
*/

/*������ Ÿ��. NONE(NULL���), ����, ��Ȯ�۹�, ��, ����, ����*/
enum ItemType {NONE, SEED, CROP, STONE, WOOD, TOOL};	

class Item
{
public:
	Item();
	Item(enum ItemType, const std::string& name);
	~Item();

	void setName(const std::string& name);
	void setMAX_NUM(int num);
	void setCost(int cost);
	void setItemType(ItemType itemType);

	ItemType getItemType();
	int getMAX_NUM();
	int getCost();
	std::string& getName();
	

private:
	int MAX_NUM = 10;	/*�����ۺ� ���� �� �ִ� �ִ� ��*/
	int cost = -1;
	std::string name;

protected:
	ItemType itemType;	/*�� Instance�� Ÿ��*/
};