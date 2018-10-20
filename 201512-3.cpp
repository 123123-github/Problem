#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 108;

int m, n, q;
char pic[maxn][maxn], ch;

void dfs(int x, int y)
{
	if (x<0 || x>=m || y<0 || y>=n) return;
	if (pic[x][y] == ch || pic[x][y] == '-' || pic[x][y] == '|' || pic[x][y] == '+') return;
	
	pic[x][y] = ch;
	
	dfs(x+1, y);
	dfs(x, y+1);
	dfs(x-1, y);
	dfs(x, y-1);
}

void pic_fill()
{
	int x, y;
	scanf("%d %d %c", &x, &y, &ch);
	
	dfs(x, y);
}

void pic_line()
{
	int s, t;
	int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	if (x1 == x2) { 
		s = min(y1, y2); t = max(y1, y2);
		for (int j=s; j<t+1; j++) pic[x1][j] = (pic[x1][j]=='-' || pic[x1][j]=='+')? '+': '|';
	} else {
		s = min(x1, x2); t = max(x1, x2);
		for (int i=s; i<t+1; i++) pic[i][y1] = (pic[i][y1]=='|' || pic[i][y1]=='+')? '+': '-';
	}
}

void print_result()
{
	for (int j=n-1; j>=0; j--) {
		for (int i=0; i<m; i++) {
			putchar(pic[i][j]);
		}
		putchar(10);
	}
	
}

int main()
{
	freopen("data.txt", "r", stdin);
	
	memset(pic, '.', sizeof(pic));
	
	scanf("%d%d%d", &m, &n, &q);
	while (q--)	
	{
		int type; scanf("%d", &type);
		
		if (type) pic_fill();
		else pic_line();
	}
	
	print_result();
	
	return 0;
}
