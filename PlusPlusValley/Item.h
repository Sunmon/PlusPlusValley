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
	Item(enum ItemType, std::string name);
	~Item();
	
	ItemType itemType;
	std::string name;
	int num = 0;

private:
	int max_num_of_item = -1;	//�����ۺ� ���� �� �ִ� �ִ� ��
	int cost = -1;	//����
};