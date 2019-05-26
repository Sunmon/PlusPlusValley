#pragma once
/**
* Item을 관리하는 클래스
* 사용 방법:
* @author KIM SUN JUNG
* @date 2019.05.26
*/
#include <string>

class Item
{
public:
	enum ItemType {SEED, CROP, STONE, WOOD, TOOL};	//아이템 타입. 씨앗, 수확작물, 돌, 나무, 도구
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
	int MAX_NUM = -1;	//아이템별 가질 수 있는 최대 수
	int cost = -1;
	std::string name;
};