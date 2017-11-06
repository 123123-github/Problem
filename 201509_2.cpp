#include <iostream>
using namespace std;

//ÅÐ¶ÏÊÇ·ñÊÇÈòÄê
bool IsLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;

	return false;
}

int main()
{
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int year, day;
	cin >> year >> day;

	if (IsLeap(year))
		mon[2]++;

	int i = 1;
	while (true)
	{
		if (day > mon[i])
		{
			day -= mon[i];
			i++;
		}
		else
		{
			cout << i << '\n' << day;
			break;
		}
	}

	system("pause");

	return 0;
}