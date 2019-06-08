#include "UseTime.h"

UseTime::UseTime()
{
}

UseTime::UseTime(int initialtime)
{
	settime(initialtime);
}

UseTime::~UseTime()
{
}

void UseTime::settime(int time)
{
	this->gmtime = time;
}

int UseTime::gethour()
{
	int newtime = (this->gmtime) / 60;
	return newtime;
}

int UseTime::getminute()
{
		int newtime = (this->gmtime) % 60;
		return newtime;
}

void UseTime::nexttime()
{
		int newtime = this->gmtime;
		settime(newtime + 10);
}

