/*
	note:	csp201604-2
	date:	2018/2/8
	tag:	注意下标的同步 
*/
#include <iostream>
using namespace std;

int a[19][10];
int t[4][4];
int pos;

bool Pass(int(*p)[10])
{
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j < +4; ++j)
			if (p[i][j + pos] + t[i][j] == 2)		// !!! 下标要注意同步  p t 都要对应上 
				return false;
	return true;
}


int main()
{
	for (int i = 0; i<15; ++i)
		for (int j = 0; j<10; ++j)
			cin >> a[i][j];
	for (int i = 15; i<19; ++i)			// 加上边界 
		for (int j = 0; j<10; ++j)
			a[i][j] = 1;
	for (int i = 0; i<4; ++i)
		for (int j = 0; j<4; ++j)
			cin >> t[i][j];
	cin >> pos;
	--pos;

	int(*p)[10];
	p = a;

	while (Pass(p))			// 可以无障碍掉落 
	{
		++p;				// 向下一行 
	}

	--p;
	for (int i = 0; i<4; ++i)				// 掉落至此处 
		for (int j = 0; j<4; ++j)
			p[i][j+pos] += t[i][j];			// !!! 下标要注意同步  p t 都要对应上 

	// 输出
	for (int i = 0; i<15; ++i)
	{
		for (int j = 0; j<10; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
