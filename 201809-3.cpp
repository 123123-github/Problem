#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const int maxn = 108, maxm = 12;

int n, m;
string src[maxn];
int level[maxn];

vector<int> ans;
vector<string> q_vec;

void init_deal(int r, string& s)
{
	int x;
	for (x=0; s[x] && s[x]=='.'; x++); level[r] = x/2;
	for (int i=x; s[i] && s[i]!='#'; i++) { s[i] = tolower(s[i]); }
}

void tolower(string& s) { for (int i=0; s[i]; i++) s[i] = tolower(s[i]); }

void get_qvec(const string& quest)
{
	q_vec.clear();
	
	string q;
	stringstream ss(quest);
	while (ss >> q) {
		if (q[0] != '#') { tolower(q); }
		q_vec.push_back(q);
	}
}

void get_result()
{
	ans.clear();
	
	int r = 0, le = -1;
	int len = q_vec.size();
	string q;
	for (int i=0; i<len-1; i++) {
		q = q_vec[i];
		for (int k=r; k<n; k++) if ( le < level[k] )
		{
			if (src[k].find(q) != string::npos) {
				
				string& s = src[k];
				int x = s.find(q);
				int y = x + q.length();
				if ( x>0 && isalnum(s[x-1]) ) continue;
				if ( y<s.length() && isalnum(s[y+1]) ) continue;
				
				le = level[k]; r = k+1; break;
			}
		}
	}
	
	q = q_vec.back();
	for (int k=r; k<n; k++) 
	{
		if (le < level[k])
		{
			if (src[k].find(q) != string::npos) {
				
				string& s = src[k];
				int x = s.find(q);
				int y = x + q.length();
				if ( x>0 && isalnum(s[x-1]) ) continue;
				if ( y<s.length() && isalnum(s[y+1]) ) continue;
				
				ans.push_back(k+1);
			}
		}
	}
}

void print_result()
{
	int len = ans.size(); cout << len << ' ';
	for (int i=0; i<len; i++) cout << ans[i] << ' ';
	putchar(10);
}

int main()
{
	freopen("data.txt", "r", stdin);
	
	cin >> n >> m; getchar();
	for (int i=0; i<n; i++) {
		getline(cin, src[i]);
		init_deal(i, src[i]);
	}
	
	string quest;
	while (m--) {
		getline(cin, quest);
		get_qvec(quest);
		get_result();
		print_result();
	}
	
	return 0;
}
