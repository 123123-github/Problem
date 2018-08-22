/*
	POJ 1175 Starry Night
	DFS & Rotate & Mirror
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 105;

int m, n;
char pic[maxn][maxn];
char idx[maxn][maxn];

struct Cluster
{
	int r, c;
	char map[maxn][maxn];
} cluster[26], c_temp;
int c_n = 0;
char c_c = 'a'-1;	// record the number of existing clusters
char ch;			// modification of idx

int r_min, r_max, c_min, c_max;

void dfs(int r, int c, char id)
{
	if (r<0 || r>=m || c<0 || c>= n)  return;
	if (idx[r][c] != '0' || pic[r][c] != '1')  return;
	
	idx[r][c] = id;
	c_temp.map[r][c] = pic[r][c];
	
	if (r < r_min)  r_min = r;
	else if (r > r_max)  r_max = r;
	if (c < c_min)  c_min = c;
	else if (c > c_max)  c_max = c;
	
	for (int i=-1; i<=1; ++i)
		for (int j=-1; j<=1; ++j)
			if (i!=0 || j!=0)  dfs(r+i, c+j, id);
}


void dfs2(int r, int c, char ch)
{
	if (r<0 || r>=m || c<0 || c>= n)  return;
	if (idx[r][c] != c_c)  return;
	
	idx[r][c] = ch;
	
	for (int i=-1; i<=1; ++i)
		for (int j=-1; j<=1; ++j)
			if (i!=0 || j!=0)
				dfs2(r+i, c+j, ch);
}


bool star_equal(Cluster &s, Cluster &t)
{
	if (! ((s.r == t.r && s.c == t.c) || (s.r == t.c && s.c == t.r)))
		return false;
	
	int r = s.r, c = s.c;
	
	// 8 transformation modes
	if (s.r == t.c && s.c == t.r)
	{
		for (int i=0,jj=c_max;   i<r;   i++,jj--)
			for (int j=0,ii=r_min;   j<c;   j++,ii++)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit1;
		return true;
		
		quit1:
		for (int i=0,jj=c_min;   i<r;   i++,jj++)
			for (int j=0,ii=r_min;   j<c;   j++,ii++)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit2;
		return true;
					
		quit2:
		for (int i=0,jj=c_min;   i<r;   i++,jj++)
			for (int j=0,ii=r_max;   j<c;   j++,ii--)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit3;
		return true;
		
		quit3:
		for (int i=0,jj=c_max;   i<r;   i++,jj--)
			for (int j=0,ii=r_max;   j<c;   j++,ii--)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit4;
		return true;
	}
	quit4:
	if (s.r == t.r && s.c == t.c)
	{
		for (int i=0,ii=r_min;   i<r;   i++,ii++)
			for (int j=0,jj=c_max;   j<c;   j++,jj--)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit5;
		return true;
		
		quit5:
		for (int i=0,ii=r_max;   i<r;   i++,ii--)
			for (int j=0,jj=c_max;   j<c;   j++,jj--)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit6;
		return true;
		
		quit6:
		for (int i=0,ii=r_max;   i<r;   i++,ii--)
			for (int j=0,jj=c_min;   j<c;   j++,jj++)
				if (s.map[i][j] != t.map[ii][jj])
					goto quit7;
		return true;
	}
	quit7:
	return false;
}


int main()
{
	scanf("%d\n%d", &n, &m);
	for (int i=0; i<m; i++)  scanf("%s", pic[i]);
	
	memset(idx, '0', sizeof(idx));
	
	for (int r=0; r<m; r++)
		for (int c=0; c<n; c++)
			if (idx[r][c] == '0' && pic[r][c] == '1')
			{
				r_min = r_max = r;
				c_min = c_max = c;
				memset(c_temp.map, '0', sizeof(c_temp.map));
				
				dfs(r, c, ++c_c);
				
				c_temp.r = r_max - r_min + 1;
				c_temp.c = c_max - c_min + 1;
								
				// compare c_temp with cluster
				bool same = false;
				for (int i=0; i<c_n; i++)
					if (star_equal(cluster[i], c_temp))
					{
						same = true;
						ch = i - 0 + 'a';
						break;
					}
				if (same)     
				{
					dfs2(r, c, ch);
					c_c--;
					
				}
				else
				{
					cluster[c_n].r = c_temp.r;
					cluster[c_n].c = c_temp.c;
					for (int i=0,ii=r_min;   ii<=r_max;   i++,ii++)
						for (int j=0,jj=c_min;   jj<=c_max;   j++,jj++)
							cluster[c_n].map[i][j] = c_temp.map[ii][jj];
					c_n++;		
				}
			}
			
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
			putchar(idx[i][j]);
		putchar(10);
	}
	
	return 0;
}
