// csp 201512-2

#include <cstdio>
#include <cstring>

const int maxn = 35;
int n, m;
int pic[maxn][maxn];
int vis[maxn][maxn];
int ans[maxn][maxn];

int d;

bool kase_match(int r1, int c1, int r2, int c2)
{
	if (r1<0 || r1>=n || r2<0 || r2>=n || c1<0 || c1>=m || c2<0 || c2>=m)  return false;
	
	if ( (pic[r1][c1] == d) && (pic[r1][c1] == pic[r2][c2]) )
	{
		ans[r1][c1] = ans[r2][c2] = 0;
		vis[r1][c1] = vis[r2][c2] = 1;
		
		return true;
	}
	
	return false;
}

void delete_same(int r, int c)
{
	vis[r][c] = 1;
	
	if( kase_match(r, c-2, r, c-1) || kase_match(r, c+1, r, c+2) || kase_match(r-2, c, r-1, c)
	|| kase_match(r+1, c, r+2, c) || kase_match(r-1, c, r+1, c) || kase_match(r, c-1, r, c+1) )
		ans[r][c] = 0;
	else
		ans[r][c] = d;
}


int main()
{
	freopen("data.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			scanf("%d", &pic[i][j]);
			
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)  if (!vis[i][j]){
			d = pic[i][j];
			delete_same(i, j);
		}
	}	
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%d ", ans[i][j]);
		}
		putchar(10);
	}
	
	return 0;
}
