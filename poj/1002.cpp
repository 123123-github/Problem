#include <cstdio>
#include <algorithm>
using namespace std;

char s[16];

int H[25] = 
{
	2,2,2,
	3,3,3,
	4,4,4,
	5,5,5,
	6,6,6,
	7,7,7,7,
	8,8,8,
	9,9,9,
};

int getData()
{
	int num = 0;
	for (char* p=s; *p!='\0'; p++)
	{
		if (*p == '-')
			continue;
		if ('0'<= *p && *p <= '9')
		{
			num = num*10 + (*p-'0');
			
		}
		else
		{
			num = num*10 + H[*p - 'A'];
		}
	}
	return num;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int data[n];
	
	// 输入 并 转化为实数 
	for (int i=0; i<n; ++i)
	{
		gets(s);
		data[i] = getData();
	}
	
	// 排序
	sort(data,data + n); 
	
	// 统计
	bool noDup = true;
	int num = 1;
	for (int i=0; i<n-1; ++i)
	{
		while (data[i] == data[i+1])
		{
			++num;
			++i;
		}
		if (num > 1)
		{
			printf("%03d-%04d %d\n",data[i-1]/10000,data[i-1]%10000,num);
			noDup = false;
			num = 1;
		}
	}
	if (noDup)
		printf("No duplicates.");
	
	return 0;
}
