/*
	note:	csp201604-2
	date:	2018/2/8
	tag:	ע���±��ͬ�� 
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
			if (p[i][j + pos] + t[i][j] == 2)		// !!! �±�Ҫע��ͬ��  p t ��Ҫ��Ӧ�� 
				return false;
	return true;
}


int main()
{
	for (int i = 0; i<15; ++i)
		for (int j = 0; j<10; ++j)
			cin >> a[i][j];
	for (int i = 15; i<19; ++i)			// ���ϱ߽� 
		for (int j = 0; j<10; ++j)
			a[i][j] = 1;
	for (int i = 0; i<4; ++i)
		for (int j = 0; j<4; ++j)
			cin >> t[i][j];
	cin >> pos;
	--pos;

	int(*p)[10];
	p = a;

	while (Pass(p))			// �������ϰ����� 
	{
		++p;				// ����һ�� 
	}

	--p;
	for (int i = 0; i<4; ++i)				// �������˴� 
		for (int j = 0; j<4; ++j)
			p[i][j+pos] += t[i][j];			// !!! �±�Ҫע��ͬ��  p t ��Ҫ��Ӧ�� 

	// ���
	for (int i = 0; i<15; ++i)
	{
		for (int j = 0; j<10; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
