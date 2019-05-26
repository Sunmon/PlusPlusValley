#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class MapObject {
private:
	string objectType;
	int health;
	Item itemArray[3] = { Item(),Item(),Item() };
	// Item���� ���Ұ��� �ƴϸ� �������� �þ�� �Ұ��� ��Ⱑ �ȵǾ �ϴ� 3���� ���� ��Ƴ����ϴ�!

public:

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



	void addItem(int n, string item_in) {
		itemArray[n].setItemType(item_in);
	}

	Item getItem(int n) {
		if (itemArray[n].getItemType() == "") {
			cout << "�ش� ��ġ�� Item�� �����ϴ�" << endl;
			exit(0);
		}
		else {
			return itemArray[n];
		}
	}


};