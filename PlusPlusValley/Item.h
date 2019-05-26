#pragma once
/**
* Item�� �����ϴ� Ŭ����
* ��� ���:
* @author KIM SUN JUNG
* @date 2019.05.26
*/
class Item
{
public:
	Item();
	Item(enum itemType);
	~Item();

private:
	enum itemType {SEED, CROP, STONE, WOOD, TOOL};	//������ Ÿ��. ����, ��Ȯ�۹�, ��, ����, ����
	const int MAX_NUM_OF_ITEM;	//�����ۺ� ���� �� �ִ� �ִ� ��
	int cost;	//����
};