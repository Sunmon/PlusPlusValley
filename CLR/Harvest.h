#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif
#include <iostream>
#include "MapObject.h"
using namespace std;

class Harvest {
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
