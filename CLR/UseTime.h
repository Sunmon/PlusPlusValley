#pragma once
#ifdef DLL2_EXPORTS
#define DLL2_API__declspec(dllexport)
#else
#define DLL2_API__declspec(dllimport)
#endif

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

