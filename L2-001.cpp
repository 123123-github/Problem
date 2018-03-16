/*
	note:	L2-001 紧急救援
	date:	2018/3/6
	tag:	Dijkstra 的变式 计算最短路径 最短条数 二级比较 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

const int INFI = 0x3f3f3f3f;

int N,M;
int v0,dest;

/*
	士兵最多数量计数错误 
*/

int main()
{
	scanf("%d%d%d%d",&N,&M,&v0,&dest);
	
	int man[N];
	for (int i=0; i<N; ++i)
		scanf("%d",man+i);
	
	int mat[N][N];
	memset(mat,0x3f,sizeof(mat));
	for (int i=0; i<N; ++i)
		mat[i][i] = 0;
	
	
	int a,b,len;
	for (int i=0; i<M; ++i)
	{
		scanf("%d%d%d",&a,&b,&len);
		mat[a][b] = len;
		mat[b][a] = len;
	}
	
	
	// Dijikstra
	
	int pathNum[N];
	int P[N],D[N];
	bool finished[N];
	int M[N];
	for (int v=0; v<N; ++v)
	{
		P[v] = v0;
		D[v] = mat[v0][v];
		finished[v] = false;
		
		M[v] = man[v];
		pathNum[v] = 0;
	}
	pathNum[v0] = 1;
	for (int i=0; i<N; ++i)
	{
		int v = v0;
		int min = 0x3f3f3f3f;
		for (int w=0; w<N; ++w)
			if ( !finished[w] && min>D[w] )
			{
				min = D[w];
				v = w;
			}
		finished[v] = true;
		for (int w=0; w<N; ++w)
			if ( !finished[w] )
				if ( (D[w] > min+mat[v][w]) )
				{
					D[w] = min+mat[v][w];
					P[w] = v;
					
					pathNum[w] = pathNum[v];
					M[w] = M[v] + man[w];
				}
				else if( (D[w] == min+mat[v][w]) )
				{
					if ( M[w] < M[v]+man[w] )
					{
						D[w] = min+mat[v][w];
						P[w] = v;
						
						M[w] = M[v] + man[w];
					}
					pathNum[w] += pathNum[v];
				}
	}
	
	int count = 0;
	int path[N];
	for (int i=dest; i!=v0; i=P[i])
		path[count++] = i;

	printf("%d %d\n",pathNum[dest],M[dest]);
	printf("%d",v0);
	for (int i=count-1; i>=0; --i)
		printf(" %d",path[i]);
	putchar('\n');
	
	return 0;
}
