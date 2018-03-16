/*
	note:	L1-039. 古风排版 (团体程序设计天梯赛)
	date:	2018/3/1
	tag: 	已初始化的空间因为越界导致出现错误的结果 
*/ 
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	char s[1005];
	cin >> n;
	getchar();

	cin.getline(s,1005);
	
	int len = strlen(s);
	int row = len/n;
	if (len%n != 0)
		++row;
	
	char mat[row][n];
	memset(mat,' ',sizeof(mat));
	
	int k=0;
	for (int i=0; i<row; ++i)
		for (int j=0; j<n; ++j)			// 过长时 下标会越界 还是字符串越界的问题 
			if (k < len)
			{
				mat[i][j] = s[k++];
			}
			
	for (int j=0; j<n; ++j)
	{
		for (int i=row-1; i>=0; --i)
			cout << mat[i][j];
		putchar('\n');
	}
	
		
	return 0;
}
