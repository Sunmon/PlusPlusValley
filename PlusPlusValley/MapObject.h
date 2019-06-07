#pragma once
#include <iostream>
#include <string> 
#include "Item.h"

using namespace std;

enum ObjectType
{
	//tree = 1, stone, harvest,
	tree, stone, harvest
};
class MapObject {
protected:
	ObjectType objectType;
	int place[2];
	int health;
	Item* itemArray[3];
	// Item���� ���Ұ��� �ƴϸ� �������� �þ�� �Ұ��� ��Ⱑ �ȵǾ �ϴ� 3���� ���� ��Ƴ����ϴ�!

public:

	MapObject(){
		for (auto& i : itemArray)
		{
			i = nullptr;
		}
	}
	MapObject(ObjectType ot, const string& name): MapObject(ot) {
		setEarnItem(ot, name);
	}

	MapObject(ObjectType object) : MapObject()
	{
		objectType = object;
		health = 5;
	}

	//Object �μ��� �� ȹ���ϴ� item ����
	void setEarnItem(ObjectType ot, const string& name) {
		switch (ot)
		{
		case tree:
			setItemArray(ItemType::WOOD, "��������", 0);
			break;
		case stone:
			setItemArray(ItemType::STONE, "������", 0);
			break;
		case harvest:
			setItemArray(ItemType::CROP, name, 0);
			setItemArray(ItemType::SEED, name+"����", 1);
			break;
		default:
			break;
		}
	}
	void setItemArray(ItemType it, const string& name, int index)
	{
		itemArray[index] = new Item(it,name);
		
	}

	Item** getItemArray()
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


	void addItem(int n, ItemType itemType) {
		itemArray[n]->setItemType(itemType);
	}

	Item* getItem(int n) {
		if (itemArray[n]->getItemType() == ItemType::NONE) {
			cout << "�ش� ��ġ�� Item�� �����ϴ�" << endl;
			exit(1);
		}
		else {
			return itemArray[n];
		}
	}


};