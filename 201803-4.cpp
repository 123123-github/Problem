#include <cstdio>
#include <cstring>

int pic[3][3];
int vis[3][4][6];

bool win(int p)
{
	for (int i=0; i<3; i++) if (vis[p][0][i]==3 || vis[p][1][i]==3) return true;
	if (vis[p][2][2]==3 || vis[p][3][3] == 3) return true;
	return false;
}


int dfs(int p, int tot)
{
	if ( win(3-p) ) {
		int score = 1; for (int i=0; i<3; i++) for (int j=0; j<3; j++) if (!pic[i][j]) score++;
		if (p==1) return -score;	// Alice lose
		else return score;
	}
	if ( tot == 9 ) { return 0; }
	
	int min = 100, max = -100;
	for (int i=0; i<3; i++) for (int j=0; j<3; j++) if (!pic[i][j]) {
		pic[i][j] = p;
		vis[p][0][i]++; vis[p][1][j]++; vis[p][2][i+j]++; vis[p][3][i-j+3]++;
		int t = dfs(3-p, tot+1);
		vis[p][0][i]--; vis[p][1][j]--; vis[p][2][i+j]--; vis[p][3][i-j+3]--;
		pic[i][j] = 0;
		if (t < min) min = t; if (t > max) max = t;
	}
	return (p==1)? max: min;
}

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i=0; i<3; i++) for (int j=0; j<3; j++) scanf("%d", &pic[i][j]);	
		
		int tot = 0;
		memset(vis, 0, sizeof(vis));
		for (int i=0; i<3; i++) for (int j=0; j<3; j++) if (pic[i][j]) {
			int p = pic[i][j];
			vis[p][0][i]++; vis[p][1][j]++; vis[p][2][i+j]++; vis[p][3][i-j+3]++;
			tot++;
		}
			
		printf("%d\n", dfs(1, tot));
	}
	
	return 0;
}
