#pragma once
/**
* Item을 관리하는 클래스
* 사용 방법:
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
	enum itemType {SEED, CROP, STONE, WOOD, TOOL};	//아이템 타입. 씨앗, 수확작물, 돌, 나무, 도구
	const int MAX_NUM_OF_ITEM;	//아이템별 가질 수 있는 최대 수
	int cost;	//가격
};