#pragma once
#include <string>

/**
* Item을 관리하는 클래스
* 사용 방법:
*	Item(ItemType, name)으로 인스턴스 생성
*	ItemType:	아이템 타입 열거형.
*	item별 최대 개수, 가격 설정 필요 (MAX_NUM, cost)
*	item별 이름 설정 필요
* @author KIM SUN JUNG
* @date 2019.05.26
*/

/*아이템 타입. NONE(NULL대신), 씨앗, 수확작물, 돌, 나무, 도구*/
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
	int MAX_NUM = 10;	/*아이템별 가질 수 있는 최대 수*/
	int cost = -1;
	std::string name;

protected:
	ItemType itemType;	/*현 Instance의 타입*/
};