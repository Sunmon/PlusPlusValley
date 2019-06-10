#pragma once

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
	int gettime();
};

