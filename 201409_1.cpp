#include <iostream>
using namespace std;

void sort(int *a, int n)
{
	int p, t;
	for (int i = 0;i<n - 1;i++)
	{
		p = i;
		for (int j = i + 1;j<n;j++)
		{
			if (a[p]>a[j])
				p = j;
		}
		if (p != i)
		{
			t = a[p];
			a[p] = a[i];
			a[i] = t;
		}
	}
	return;
}

/*------------------------遇到的问题-----------------------*/
//忘记对 n 进行初始化。 要记得参数输入个数，不要使用没有初始化的值！
int main()
{
	//数据输入 
	int *a, n;
	cin >> n;
	a = new int[n];
	for (int i = 0;i<n;i++)
	{
		cin >> a[i];
	}

	//排序 
	sort(a, n);

	//统计数对个数
	int count = 0;
	for (int i = 1;i<n;i++)
	{
		if (a[i] == a[i - 1] +
			1)
			count++;
	}
	cout << count;

	//释放空间
	delete a;

	return 0;
}