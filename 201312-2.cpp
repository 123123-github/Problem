/*
	note:	csp201312-2
	date:	2018/2/8
	tag:	×Ö·û´®´¦Àí 
*/
#include <cstdio>
using namespace std;

char s[15];


int main()
{
	scanf("%s",s);
	char *p=s;
	
	int t;
	int sum = 0;
	int i = 1;
	while (*p!='\0')
	{
		t = *p - '0';
		++p;
		
		if (0<=t && t<10)
		{
			sum += t*i;
			++i;
		}
		if (i==10)
		{
			++p;
			sum %= 11;
			
			if (*p-'0'==sum || (*p=='X' && sum==10))
				printf("Right");
			else
			{
				*p = (sum==10)? 'X': sum +'0';
				printf("%s",s);
			}
			return 0;
		}
	}
	
	return 0;
}
