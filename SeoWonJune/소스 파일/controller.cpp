#include <iostream>
#include <iomanip>
#include "MoveThread.h"
#include "character.h"
using namespace std;

class usetime
{
private:
	int gmtime;
public:

	void settime(int time)
	{
		this->gmtime = time;
	}
	usetime(int initialtime)
	{
		settime(initialtime);
	}
	int gethour()
	{
		int newtime = (this->gmtime) / 60;
		return newtime;
	}
	int getminute()
	{
		int newtime = (this->gmtime) % 60;
		return newtime;
	}
	void nexttime()
	{
		int newtime = this->gmtime;
		settime(newtime + 10);
	}

};
int main()
{


	mainchara chara(0, 0);
	MoveThread move(&chara);
	usetime time(9 * 60);
	move.start();

	while (1)
	{
		Sleep(1000);
		time.nexttime();
		cout << setw(2) << setfill('0') << time.gethour() << ':' << setw(2) << setfill('0') << time.getminute() << endl;
	}
}
