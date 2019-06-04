#pragma once
#include <iostream>
#include <string> 
#include "Item.h"

using namespace std;

enum ObjectType
{
	tree = 1, stone, harvest,
};
class MapObject {
private:
	ObjectType objectType;
	int health;
	int place[2];
	Item itemArray[3];
	// Item���� ���Ұ��� �ƴϸ� �������� �þ�� �Ұ��� ��Ⱑ �ȵǾ �ϴ� 3���� ���� ��Ƴ����ϴ�!

public:
	MapObject() {
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
		itemArray[n].setItemType(itemType);
	}

	Item getItem(int n) {
		if (itemArray[n].getItemType() == ItemType::NONE) {
			cout << "�ش� ��ġ�� Item�� �����ϴ�" << endl;
			exit(1);
		}
		else {
			return itemArray[n];
		}
	}

	MapObject(ObjectType object)
	{
		objectType = object;
		health = 5;
	}
};