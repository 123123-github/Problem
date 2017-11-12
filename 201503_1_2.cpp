#include <iostream>
using namespace std;

int main()
{
	//存储行列信息
	int m, n;
	int *a;
	cin >> m >> n;
	int num = m*n;

	//申请空间
	a = new int[num];
	//输入数据
	for (int i = 0; i <num ; i++)
	{
		cin >> a[i];
	}
	//按格式输出
	for (int k = n - 1; k >= 0; k--)
	{
		for (int i = k; i < num; i+=n)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	//释放空间
	delete a;

	system("pause");

	return 0;
}