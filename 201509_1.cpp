#include <iostream>
using namespace std;

int main()
{
	int *a,n;
	//输入
	cin >> n;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	//类似统计字符串中的单词个数
	int part = 1;
	int i = 1;
	while (i<n)
	{
		while (i<n && a[i]==a[i-1])
		{
			i++;
		}
		part++;
		i++;
	}
	if (a[n-1] == a[n - 2])
		part--;
	cout << part;

	delete a;

	system("pause");

	return 0;
}