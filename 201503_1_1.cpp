#include <iostream>
using namespace std;

int main()
{
	int **a;
	int m, n;

	//输入行列信息
	cin >> m >> n;

	//动态申请二维空间
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	//输入图片信息
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	//反转输出
	for (int j = n-1; j >=0; j--)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	//释放空间
	for (int i = 0; i < m; i++)
	{
		delete a[i];
	}
	delete a;

	system("pause");

	return 0;
}