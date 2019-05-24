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
	// item수를 정할건지 아니면 동적으로 늘어나게 할건지 얘기가 안되어서 일단 3개로 대충 잡아놨습니다!

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
			cout << "해당 위치에 item이 없습니다" << endl;
			exit(0);
		}
		else {
			return itemArray[n];
		}
	}
	
	
};
