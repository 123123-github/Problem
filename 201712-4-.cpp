/*
	note:	csp201712-4
	date:	2018/2/8
	tag:	Dijkstra
*/

#include <bits/stdc++.h>
using namespace std;

const bool Small = true;
const bool Big = false;
const int INFINI = 1e6;

int n;
int m;

inline getPos(int i,int j)
{
	return (2*n-i)*(i-1)/2 + j-i - 1;
}

void Dijkstra(int **mat,int* const &P,int* const &D)
{
	const int v0 = 1;
	bool finished[n+1];
	
	for (int i=1; i<=n; ++i)
	{
		P[i] = v0;
		D[i] = mat[v0][i];
		finished[i] = false;
	}
	
	finished[v0] = true;
	
	for (int i=1; i<=n-1; ++i) 
	{
		int v;
		int min = 1e6;
		
		for (int w=1; w<=n; ++w)
		{
			if (!finished[w] && min>D[w])
			{
				min = D[w];
				v = w;
			}
		}
		
		finished[v] = true;
		
		for (int w=1; w<=n; ++w)
		{
			if ( !finished[w] && (D[w] > min+mat[v][w]) )
			{
				D[w] = min + mat[v][w];
				P[w] = v;
			}
		}
	}
}


int main()
{
	
	scanf("%d%d",&n,&m);
	
	int rodeType[n*(n-1)/2];
	int mat[n+1][n+1];
	// mat 初始化 
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			mat[i][j] = INFINI;
	for (int i=1; i<=n; ++i)
		mat[i][i] = 0;
	
	int pos;
	int t,a,b,s;
	for (int i=1; i<=m; ++i)
	{
		scanf("%d%d%d%d",&t,&a,&b,&s);
		
		mat[a][b] = mat[b][a] = s;
		pos = (a<b)? getPos(a,b): getPos(b,a);
		rodeType[pos] = t;
	}
	
	int P[n+1];
	int D[n+1];
	
	int* temp[n+1];					// 指针数组 传递参数 
	for (int i=1; i<=n; ++i)
		temp[i] = mat[i];
	Dijkstra(temp,P,D);				// 获得路径 
	
	// 根据路的类型重新计算距离 
	bool lastType;
	bool nowType;
	bool same;
	
	int i,j;
	int sum = 0;		// 总距离 
	int dis = 0;		// 每段路的距离 
	for (i=n; i!=1; i=j)
	{
		j = P[i];
		
		pos = (i<j)? getPos(i,j): getPos(j,i);
		nowType = rodeType[pos];
		same = (lastType==nowType)? true: false;
		
		if (!same)
		{
			if ( nowType==Small )
				dis*=dis; 
			
			sum += dis;
			dis = 0;
		}
		
		dis += mat[i][j];
	}
	if (nowType==Small)
		dis*=dis;
	sum += dis;
	
	
	printf("%d",sum);
	
	return 0;
}
