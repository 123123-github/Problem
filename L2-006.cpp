/*
	note:	L2-006. 树的遍历
	date:	2018/3/16
	tag:	根据 中序 后序 建立树	递归	层次遍历	格式控制	重定向数据输入 输出 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

struct TNode
{
	int left;                                             
	int right;
};

int N;
int Midd[50];
int Post[50]; 	
TNode t[50];

int build(int a1, int a2, int b1, int b2)
{
	if (a1 > a2)
		return 0;
	
	int r = Post[b2];
	int p1 = a1;					// 中序中的分割点，前段末尾 
	int p2;							 // 后序中的 
	
	while ( Midd[p1] != r )
		p1++;
	p2 = b1 + (p1-a1) - 1;
	
	t[r].left  = build(a1, p1-1, b1, p2);
	t[r].right = build(p1+1, a2, p2+1, b2-1);
	
	return r;
}

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	
	int a[N];
	int k = 0;
	int p;
	
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		a[k++] = p;
		
		if (t[p].left  != 0)
			q.push(t[p].left );
		if (t[p].right != 0)                                                                                                               
			q.push(t[p].right);
	}
	
	for (int i=0; i<N; ++i)
		printf("%d%c", a[i], i==N-1? '\n': ' ');
}

int main()
{
	// 递归来利用后序中序建树 
	
//	freopen("data.txt","r",stdin);  
//	freopen("out.txt","w",stdout);  
	
	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> Post[i];
	for (int i=0; i<N; ++i)
		cin >> Midd[i];
	
	int r = build(0,N-1,0,N-1);
	bfs(r);
	
	return 0;
}
