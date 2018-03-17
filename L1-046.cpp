/*
	note:	L1-046. 整除光棍
	date:	2018/3/17
	tag:	类似高精度除法	模拟处罚过程 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

char s[500];		// 存放商 

int main()
{
	memset(s,0,sizeof(s));
	
	int x;
	cin >> x;
	
	int num = 1;
	char *p = s;
	int t;
	
	int k = 1;
	
	while (true)
	{
		t = num % x;
		if (t == 0)
		{
			*p = num/x - 0 + '0';	
			break;
		}
		else
		{
			*p++ = num/x - 0 + '0';
			num = t*10 + 1;
			k++;
		}
	}
	
	p = s;
	while (*p == '0')
		p++;
	cout << p << ' ' << k;
	
	return 0;
}
