/*
	note:	csp201409-3	
	date:	2018/2/13
	tag:	�⺯��ʹ�� cstring
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char des[120];
	char strDes[120]; 
	cin >> des;			// Ŀ�괮 
	
	int tag;
	cin >> tag;
	
	int n;
	cin >> n;
	
	char s[120];
	char str[120];
	char *p;
	
	
	if (tag == 0)		// ��Сд������ 
	{
		strcpy(strDes,des);
		strlwr(strDes);	
	
		for (int i=0; i<n; ++i)
		{
			cin >> s;
			strcpy(str,s);
			
			strlwr(str);
			p = strstr(str,strDes);
			if (p)
				cout << s << '\n';
		}
	}
	else
	{
		for (int i=0; i<n; ++i)
		{
			cin >> s;
			
			p = strstr(s,des);
			if (p)
				cout << s << '\n';
		}
	}
	
	return 0;
}
