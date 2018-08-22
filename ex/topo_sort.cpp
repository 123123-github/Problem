#include <cstdio>
#include <cstring>

// Topological Sort

const int maxn = 105;

int n, m;
int G[maxn][maxn];
int visit[maxn];

int topo[maxn], t;

bool dfs(int u)
{
	visit[u] = -1;
	
	for (int v=1; v<=n; v++) if (G[u][v])
	{
		if (visit[v] == -1)		// NOT DAG
			return false;
		else if(!visit[v] && !dfs(v))
			return false;
	}
	
	visit[u] = 1;
	topo[--t] = u;
	
	return true;
}


bool topo_sort()
{
	for (int u=1; u<=n; u++)
		if (!visit[u] && !dfs(u))
			return false;
	
	return true;
}


int main()
{	
	while (scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		t = n;
		memset(G, 0, sizeof(G));
		memset(visit, 0, sizeof(visit));

		int a, b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			G[a][b] = 1;
		}
	
		if(topo_sort())
		{
	        for(int i=0; i<n; i++){
	            if(i == 0) printf("%d", topo[i]);
	            else printf(" %d", topo[i]);
	        }
	        putchar(10);    
	    }
	    else
	        printf("No\n");
	}
	
	return 0;
}
