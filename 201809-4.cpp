#include <cstdio>
#include <cstring>

const int maxn = 305;

int n, a[maxn], b[maxn];

bool match(int cur)
{
	if (cur == 0)
	{
		return true;	
	}
	else if (cur == 1) {
		return (b[cur]+b[cur-1])/2 == a[cur-1];
	}
	else if (cur < n-1) {
		return (b[cur]+b[cur-1]+b[cur-2])/3 == a[cur-1];
	}
	else
	{
		return ((b[cur]+b[cur-1]+b[cur-2])/3 == a[cur-1]) && ((b[cur]+b[cur-1])/2 == a[cur]);
	}
}

bool dfs(int cur)
{
	if (cur == n) {
		return true;
	}
	
	for (int i=1; i<200; i++) {
		b[cur] = i;
		if (!match(cur)) continue;
		if (dfs(cur+1)) return true;
	}
	
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", a+i);
	
	dfs(0);
	for (int i=0; i<n; i++) printf("%d ", b[i]);
	
	return 0;
}
