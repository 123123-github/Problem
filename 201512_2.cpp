//Dev-C++ 编译需删除delete后的[]内容
#include <iostream>
using namespace std;

struct elem
{
	int data;
	int count_row;
	int count_col;
};

void CountNum_Row(elem **a,int m,int n)
{
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i][j].data == a[i][j - 1].data)
				a[i][j].count_row = ++count;
			else
				count = 0;
		}
		//每次循环完成后要将count归零！
		count = 0;
	}

	return;
}

void CountNum_List(elem **a, int m, int n)
{
	int count = 0;

	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i < m; i++)
		{
			if (a[i][j].data == a[i - 1][j].data)
				a[i][j].count_col = ++count;
			else
				count = 0;
		}
		//每次循环完成后要将count归零！
		count = 0;
	}

	return;
}

void Delete_Row(elem **a, int m, int start, int finale)
{
	for (int j = start; j <= finale; j++)
	{
		a[m][j].data = 0;
	}

	return;
}

void Delete_List(elem **a, int n, int start, int finale)
{
	for (int i = start; i <= finale; i++)
	{
		a[i][n].data = 0;
	}

	return;
}

void FindDelete_Row(elem **a, int m, int n)
{
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[i][j].count_row>=2)
			{
				count = a[i][j].count_row;
				Delete_Row(a, i, j - count, j);
				j = j - count;
			}
		}
	}

	return;
}

void FindDelete_List(elem **a, int m, int n)
{
	int count = 0;

	for (int j = 0; j < n; j++)
	{
		for (int i = m - 1; i >= 0; i--)
		{
			if (a[i][j].count_col >= 2)
			{
				count = a[i][j].count_col;
				Delete_List(a, j, i - count, i);
				i = i - count;
			}
		}
	}

	return;
}

int main()
{
	elem **a;
	int m, n;

	cin >> m >> n;
	a = new elem *[m];
	for (int i = 0;i < m;i++)
	{
		a[i] = new elem[n];
	}

	for (int i = 0;i < m;i++)
	{
		for (int  j = 0; j < n; j++)
		{
			cin >> a[i][j].data;
			a[i][j].count_row = 0;
			a[i][j].count_col = 0;
		}
	}

	CountNum_Row(a, m, n);
	CountNum_List(a, m, n);

	FindDelete_Row(a, m, n);
	FindDelete_List(a, m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j].data << ' ';
		}
		cout << '\n';
	}

	//释放空间
	for (int i = 0; i < m; i++)
	{
		delete [n]a[i];
		a[i] = NULL;
	}
	delete [m]a;
	a = NULL;

	system("pause");

	return 0;
}