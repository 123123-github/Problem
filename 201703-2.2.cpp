/*
	csp 2017-03-2
	Using Link List
*/
#include <cstdio>
#include <cstring>

const int maxn = 1008;
const int head = 0;

int n, m;
int s[maxn];
int tail, next[maxn], pre[maxn];

void go_next(int &cur, int dx)
{
	while (dx--) cur = next[cur];
}

void go_pre(int &cur, int dx)
{
	while (dx--) cur = pre[cur];
}

void Del(int x)
{
	next[ pre[x] ] = next[x];
	pre[ next[x] ] = pre[x];
}

void Insert(int f, int x, int t)
{
	next[f] = x; next[x] = t;
	pre[x] = f; pre[t] = x;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i=1; i<=n; i++) s[i] = i;
	
	next[tail = head] = pre[head] = 0;
	for (int i=1; i<=n; i++) {
		next[i] = next[tail];
		next[tail] = i;
		
		pre[ next[i] ] = i;
		pre[i] = tail;
		
		tail = i;
	}
	
	int x, dx, cur;
	while (m--)
	{
		scanf("%d%d", &x, &dx);
		cur = x;
		
		if (dx > 0) go_next(cur, dx);
		else go_pre(cur, -dx + 1);
		
		Del(x);
		Insert(cur, x, next[cur]);
	}
	
	
	for (int i=next[head]; i; i=next[i]) {
		printf("%d ", s[i]);
	}
		
	return 0;
}
