/*
	note:	csp201712-2
	date:	2018/2/8
	tag:	模拟线性表删除 
*/

#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	
	int a[n];
	for (int i=0;i<n;++i)
		a[i] = i+1;
	
	
	int len = n;
	
	int t = 1;
	int *p = a;
	int *end = a+n-1;
	while (len != 1)
	{
		while (len!=1 && (t%k!=0 && t%10!=k))	// 跳过不需要删除的位置 
		{
			p = (p==end)? a: p+1; 		// 循环遍历 
			t = (*p==0)? t: t+1;
		}
		
		*p = 0;				// 标记为删除 
		--len; 
		
		do
		{
			p = (p==end)? a: p+1;
			t = (*p==0)? t: t+1;
		}while(len!=1 && *p==0);
	}
	for (int i=0; i<n; ++i)
		if (a[i])
			cout << a[i]; 
	
	return 0;
}
