#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

/*
	note:	L1-025. 正整数A+B
	date:	2018/3/9 
	tag:	输入数据的方式 字符串的读取 
*/

int main()
{
	int a,b;
	bool ar = true,br = true;
	char A[5000],B[5000];
	cin.getline(A,5000,' ');
	cin.getline(B,5000);
	
	for (char *p=A; *p!='\0'; ++p)
	{
		if(!isdigit(*p))
			ar = false;
	}
	for (char *p=B; *p!='\0'; ++p)
	{
		if(!isdigit(*p))
			br = false;
	}
	a = atoi(A);
	b = atoi(B);
	if (a<1 || a>1000)
		ar = false;
	if (b<1 || b>1000)
		br = false;
	
	if (ar && br)
		printf("%d + %d = %d",a,b,a+b);
	else if (ar && !br)
		printf("%d + ? = ?",a);
	else if (!ar && br)
		printf("? + %d = ?",b);
	else
		printf("? + ? = ?");
	
	return 0;
}
