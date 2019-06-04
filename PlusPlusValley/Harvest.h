#pragma once
#include <iostream>
#include "MapObject.h"
using namespace std;

class Harvest : MapObject {
private:
	int growth;
	int growingPoint = 70;
	int level;
	MapObject *mo = new MapObject();
public:

	Harvest() {
		growth = 0;
		level = 0;
	}

	Harvest(ItemType it, const string& name):  MapObject(it,name){
		this->health = 1;
	}

	bool checkPlace(int x, int y) {
		if (mo->getPlace[0] == x && mo->getPlace[1] == y) {
			return true;
		}
		else {
			return false;
		}
	}


	int growing() {
		if (growth >= growingPoint) {
			level++;
		}
		return level;
	}
};
