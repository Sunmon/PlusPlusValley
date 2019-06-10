#pragma once
#include <iostream>
#include "MapObject.h"
using namespace std;

class Harvest : public MapObject {
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

	Harvest(ObjectType ot, const string& name):  MapObject(ot,name){
		this->health = 1;
	}

	//bool checkPlace(int x, int y) {
	//	if (mo->getPlace[0] == x && mo->getPlace[1] == y) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}


	int growing() {
		if (growth <= growingPoint) {
			growth = growth + 20;
		}
		cout << growth << endl;
		return level;
	}
};
