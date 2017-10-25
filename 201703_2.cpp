#include <iostream>
using namespace std;

struct Change
{
	int student;
	int position;
};

int LocateStudent(int list[], int n, int student)
{
	int i;

	for ( i = 0;i < n;i++)
		if (list[i] == student)
			break;

	return i + 1;
}

void ChangeStudent(int list[], int n, int position_before, int position_now)
{
	int t = list[position_before - 1];

	for (int i = position_before;i < position_now;i++)
		list[i - 1] = list[i];

	for (int i = position_before;i > position_now;i--)
		list[i - 1] = list[i - 2];

	list[position_now - 1] = t;

	return;
}

int main()
{
	int n, m;
	int *list;
	Change *change;

	cin >> n;
	cin >> m;

	list = new int[n];
	for (int i = 0; i < n; i++)
		list[i] = i + 1;

	change = new Change[m];

	for (int i = 0;i < m;i++)
		cin >> change[i].student >> change[i].position;

	int position;
	for (int i = 0;i < m;i++)
	{
		position = LocateStudent(list, n, change[i].student);
		ChangeStudent(list, n, position, position + change[i].position);
	}

	for (int i = 0;i < n;i++)
		cout << list[i] << ' ';

	system("pause");

	return 0;
}