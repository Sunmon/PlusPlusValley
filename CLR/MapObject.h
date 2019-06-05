#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class MapObject {
private:
	string objectType;
	int health;
	int place[2];
	Item itemArray[3] = { Item(),Item(),Item() };
	// Item���� ���Ұ��� �ƴϸ� �������� �þ�� �Ұ��� ��Ⱑ �ȵǾ �ϴ� 3���� ���� ��Ƴ����ϴ�!

public:
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
	void setObjectType(string objectType) {
		this->objectType = objectType;
	}

	string getObjectType() {
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


};