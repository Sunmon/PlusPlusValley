#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include "Item.h"

using namespace std;

enum ObjectType
{
	//tree = 1, stone, harvest,
	tree, stone, harvest, npc
};
class MapObject {
protected:
	ObjectType objectType;
	int place[2];
	int health;
	string name;
	vector<Item*> itemArray;
	//Item* itemArray[3];
	// Item수를 정할건지 아니면 동적으로 늘어나게 할건지 얘기가 안되어서 일단 3개로 대충 잡아놨습니다!

public:

	MapObject(){
		for (auto& i : itemArray)
		{
			i = nullptr;
		}
	}
	MapObject(ObjectType ot, const string& name): MapObject(ot) {
		this->name = name;
		setEarnItem(ot, name);
	}

	MapObject(ObjectType object) : MapObject()
	{
		objectType = object;
		health = 5;
	}

	//Object 부셨을 때 획득하는 item 생성
	void setEarnItem(ObjectType ot, const string& name) {
		/*switch (ot)
		{
		case tree:
			setItemArray(ItemType::WOOD, "나무조각", 0);
			break;
		case stone:
			setItemArray(ItemType::STONE, "돌조각", 0);
			break;
		case harvest:
			setItemArray(ItemType::CROP, name, 0);
			setItemArray(ItemType::SEED, name+"씨앗", 1);
			break;
		default:
			break;
		}
*/
		switch (ot)
		{
		case tree:
			//setItemArray(ItemType::WOOD, "나무조각", 0);
			setItemArray(ItemType::WOOD, "나무조각");
			break;
		case stone:
			//setItemArray(ItemType::STONE, "돌조각", 0);
			setItemArray(ItemType::STONE, "돌조각");
			break;
		case harvest:
			setItemArray(ItemType::CROP, name);
			setItemArray(ItemType::SEED, name + "씨앗");
			break;

			//setItemArray(ItemType::CROP, name, 0);
			//setItemArray(ItemType::SEED, name + "씨앗", 1);
		case npc: break;
		default:
			break;
		}
	}

	void setItemArray(ItemType it, const string& name)
	{
		itemArray.push_back(new Item(it, name));
	}

	void setItemArray(ItemType it, const string& name, int index)
	{
		itemArray[index] = new Item(it,name);
		
	}

	vector<Item*> getItemArray()
	{
		return itemArray;
	}



	void setPlace(int p[]) {
		place[0] = p[0];
		place[1] = p[1];
	}

	void setPlace(int x, int y) {
		place[0] = x;
		place[1] = y;
	}

	int* getPlace() {
		return place;
	}
	void setObjectType(ObjectType objectType) {
		this->objectType = objectType;
	}

	ObjectType getObjectType() {
		return this->objectType;
	}

	void setHealth(int health) {
		this->health = health;
	}

	int getHealth() {
		return this->health;
	}

	void setName(string n)
	{
		name = n;
	}
	
	string getName()
	{
		return this->name;
	}
	void addItem(int n, ItemType itemType) {
		itemArray[n]->setItemType(itemType);
	}

	Item* getItem(int n) {
		if (itemArray[n]->getItemType() == ItemType::NONE) {
			cout << "해당 위치에 Item이 없습니다" << endl;
			exit(1);
		}
		else {
			return itemArray[n];
		}
	}
	virtual int growing() {
		cout << "check" << endl;
		return 0;
	}

};