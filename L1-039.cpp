/*
	note:	L1-039. �ŷ��Ű� (����������������)
	date:	2018/3/1
	tag: 	�ѳ�ʼ���Ŀռ���ΪԽ�絼�³��ִ���Ľ�� 
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
		for (int j=0; j<n; ++j)			// ����ʱ �±��Խ�� �����ַ���Խ������� 
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
