#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 10008;

int n, m;
vector<int> G[maxn];

bool inStack[maxn];
int dfn[maxn], low[maxn], stack[maxn];
int ans = 0, tot = 0, top = -1;

void tarjan(int u)
{
	stack[++top] = u;
	inStack[u] = true;
	dfn[u] = low[u] = ++tot;
	
	for (int i=0; i<G[u].size(); i++) {
		int v = G[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (inStack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	if (low[u] == dfn[u]) {
		int cnt = 0;
		do {
			inStack[stack[top]] = false;
			top--;
			cnt++;
		} while (stack[top+1] != u);
		ans += ( ((cnt-1) * cnt) >> 1 );
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int a, b, i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
	}
	
	memset(dfn, 0, sizeof(dfn));
	
	for (int i=1; i<=n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	
	printf("%d", ans);
	
	return 0;
}
