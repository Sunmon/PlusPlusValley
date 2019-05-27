
int main()
{

	Map map;

	Tile* maketile = map.gettile(15, 10);
	Player player(maketile);
	MoveThread move(&player);
	usetime time(9 * 60);
	move.start();

	while (1)
	{
		Sleep(1000);
		time.nexttime();
		cout << setw(2) << setfill('0') << time.gethour() << ':' << setw(2) << setfill('0') << time.getminute() << endl;
	}
}
