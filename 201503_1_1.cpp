#include <iostream>
using namespace std;

int main()
{
	int **a;
	int m, n;

	//����������Ϣ
	cin >> m >> n;

	//��̬�����ά�ռ�
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	//����ͼƬ��Ϣ
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	//��ת���
	for (int j = n-1; j >=0; j--)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	//�ͷſռ�
	for (int i = 0; i < m; i++)
	{
		delete a[i];
	}
	delete a;

	system("pause");

	return 0;
}