//题目：公共钥匙盒
#include <iostream>
using namespace std;

struct keychange
{
	int type;
	int time;
	int state;
};

void SortChange_by_time(keychange c[], int n)
{
	int p;
	keychange t;

	for (int i = 0;i < n - 1;i++)
	{
		p = i;
		for (int j = i + 1;j < n;j++)
		{
			if (c[p].time > c[j].time)
				p = j;
			if (c[p].time == c[j].time)
			{
				if (c[p].state < c[j].state)
					p = j;
				if (c[p].state == c[j].state && c[p].type > c[j].type)
					p = j;
			}
		}
		
		if (p != i)
		{
			t = c[p];
			c[p] = c[i];
			c[i] = t;
		}
	}
	
	return;
}

void keybox_get(int keybox[], int n,int keytype)
{
	for (int i = 0;i < n;i++)
		if (keybox[i] == keytype)
			keybox[i] = 0;

	return;
}

void keybox_put(int keybox[], int n, int keytype)
{
	for (int i = 0; i < n; i++)
		if (keybox[i] == 0)
		{
			keybox[i] = keytype;
			break;
		}

	return;
}

int main()
{
	int num_key, n, N;
	int *keybox;
	keychange *change;
	int usetime = 0;

	cin >> num_key >> n;

	N = n * 2;

	keybox = new int[num_key];
	for (int i = 0; i < num_key; i++)
		keybox[i] = i + 1;

	change = new keychange[N];

	for (int i = 0; i < n; i++)
	{
		cin >> change[i].type >> change[i].time >> usetime;
		change[i].state = 0;

		change[i + n].type = change[i].type;
		change[i + n].time = change[i].time + usetime;
		change[i + n].state = 1;
	}

	SortChange_by_time(change, N);

	for (int i = 0;i < N;i++)
	{
		if (change[i].state == 0)
			keybox_get(keybox, num_key, change[i].type);
		else
			keybox_put(keybox, num_key, change[i].type);
	}

	for (int i = 0; i < num_key;i++)
		cout << keybox[i] << ' ';

	system("pause");

	return 0;
}