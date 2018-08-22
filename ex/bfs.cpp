/*
	bfs
	UVa 572
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 105;

char pic[maxn][maxn];
int idx[maxn][maxn];

int m, n;

void bfs(int r, int c, int id)
{
	if (r<0 || r>=m ||c<0 || c>=n)  return;
	
	queue<pair<int, int> > q;
	pair<int, int> u(r,c);
	
	q.push(u);
	while (!q.empty())
	{
		u = q.front();  q.pop();
		int a = u.first, b = u.second;
		
		idx[a][b] = id;
		
		for (int i=-1; i<=1; ++i)
			for (int j=-1; j<=1; ++j)  if (i!=0 || j!=0)
				if (idx[a+i][b+j] == 0 && pic[a+i][b+j] == '@'){
					pair<int, int> v(a+i, b+j);
					q.push(v);
				}
	}
}

int main()
{
	while (scanf("%d%d", &m, &n) == 2 && m && n)
	{
		for(int i=0; i<m; ++i)	scanf("%s", pic[i]);
		memset(idx, 0, sizeof(idx));
		
		int cnt = 0;
		
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				if (idx[i][j] == 0 && pic[i][j] == '@')
					bfs(i, j, ++cnt);
		
		printf("%d\n", cnt);
	}	
	
	return 0;
}
