#pragma once
#include <iomanip>
#include "MoveThread.h"
#include "Character.h"
#include "Map.h"

class UseTime
{
private:
	int gmtime;
public:
	UseTime();
	UseTime(int initialtime);
	~UseTime();
	void settime(int time);

	int gethour();
	
	int getminute();
	void nexttime();
	

};

