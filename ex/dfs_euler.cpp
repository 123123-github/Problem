#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int G['z'+1]['z'+1];
int vis['z'+1];
int set['z'+1];
bool has_vec['z'+1];

string s;


void dfs(int u, int id)
{
	vis[u] = id;	
	
	for (int v='a'; v<='z'; v++)
		if (has_vec[v] && vis[v] == 0)
			if (G[u][v] != 0)
				dfs(v, id);
}


int main()
{
	int T;  cin >> T;
	while (T--){
		
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		memset(set, 0, sizeof(set));
		memset(has_vec, false, sizeof(has_vec));
		
		int n;  cin >> n;
		for (int i=0; i<n; ++i)
		{
			cin >> s;
			char a = s[0], b = s[s.length()-1];
			G[a][b]++, G[b][a]++;
			set[a]++, set[b]--;
			has_vec[a] = has_vec[b] = true;
		}
		
		int p[3] = {0, 0, 0}, k = 0;
		for (int i='a'; i<='z'; i++)  if (set[i] != 0 && k < 3){
			p[k++] = set[i];
		}
		
		bool euler = false;
		if (k == 0)  euler = true;
		else if (k == 2 && ((p[0]==1 && p[1]==-1) || (p[0]==-1 && p[1]==1)))  euler = true;
		
		int cnt = 0;
		for (int i='a'; i<='z'; i++)
			if (has_vec[i] && vis[i] == 0)
				dfs(i, ++cnt);
		
		if (cnt == 1 && euler)
			cout << "Ordering is possible.\n";
		else
			cout << "The door cannot be opened.\n";
	}
	
	return 0;
}
