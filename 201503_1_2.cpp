#include <iostream>
using namespace std;

int main()
{
	//�洢������Ϣ
	int m, n;
	int *a;
	cin >> m >> n;
	int num = m*n;

	//����ռ�
	a = new int[num];
	//��������
	for (int i = 0; i <num ; i++)
	{
		cin >> a[i];
	}
	//����ʽ���
	for (int k = n - 1; k >= 0; k--)
	{
		for (int i = k; i < num; i+=n)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	//�ͷſռ�
	delete a;

	system("pause");

	return 0;
}