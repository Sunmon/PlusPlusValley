#pragma once
#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class MapObject {
private:
	string objectType;
	int health;
	item itemArray[3] = {item(),item(),item()};
	// item���� ���Ұ��� �ƴϸ� �������� �þ�� �Ұ��� ��Ⱑ �ȵǾ �ϴ� 3���� ���� ��Ƴ����ϴ�!

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

	item getItem(int n) {
		if (itemArray[n].getItemType() == "") {
			cout << "�ش� ��ġ�� item�� �����ϴ�" << endl;
			exit(0);
		}
		else {
			return itemArray[n];
		}
	}
	
	
};
