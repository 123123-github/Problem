/*
	note:	L1-006.连续因子 
	date:	2018/3/4
	tag:	简化循环 逻辑分析 特殊数据处理 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	
	int a,len = 0;
	int tl;
	
	int N;
	cin >> N;
	
	int M;
	for (int i=2; i<=sqrt(N); ++i)
	{
		M = i;
		if (N%M != 0)
			continue;
		tl = 1;
		
		for (int j=i+1; j<=sqrt(N)+1; ++j)
		{
			M *= j;
			if (N%M != 0)
			{
				if (tl > len)
				{
					len = tl;
					a = i;
				}
				break;
			}
			else
			{
				tl++;
			}	
		}
	}
	if (len == 0)
	{
		a = N;
		len = 1;
	}
	
	cout << len << '\n';
	cout << a;
	for (int i=a+1; i<a+len; ++i)
		cout << '*' << i;
	
	return 0;
}
