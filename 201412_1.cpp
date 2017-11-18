//CSP题目
//门禁系统 (直接循环统计,时间复杂度 O(n^2)，应该有效率更高的解法)
#include <iostream>
using namespace std;

int main()
{
	//数据输入
	int *a,n;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//统计输出
	int count;
	for(int i=0;i<n;i++)
	{
		count=1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]==a[j])
				count++;
		}
		cout<<count<<' ';
	} 
	//空间释放
	delete a; 
	
	return 0;
}
