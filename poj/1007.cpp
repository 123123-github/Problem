#include <cstdio>
#include <algorithm> 
using namespace std;

int len,n;
struct Node
{
	int inver;
	int pos;
};

int sortedness(char *s)
{
	int count = 0;
	
	for (char *p=s; *p!='\0'; ++p)
		for (char *q=p+1; *q!='\0'; ++q)
			if (*q < *p)
				++count;
	
	return count;
}

bool cmp(const Node& a,const Node& b)
{
	return a.inver<b.inver;
}

int main()
{
	// 读取数据 
	scanf("%d%d",&len,&n);
	getchar();
	
	char s[n][len+2];
	Node a[n];								// 逆序数与字符串的对应 
	
	for (int i=0; i<n; ++i)
	{
		gets(s[i]);
		a[i].pos = i;
		a[i].inver = sortedness(s[i]);

	}
	
	// 排序
	sort(a,a+n,cmp); 
	
	// 输出对应的串 
	int pos;
	for (int i=0; i<n; ++i)
	{
		pos = a[i].pos;
		puts(s[pos]);
	} 
	
	return 0;
}
