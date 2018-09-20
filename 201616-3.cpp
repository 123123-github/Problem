#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int maxn = 105;

vector<int> role_list[maxn];
vector<string> privi_list[maxn];
map<string, int> user_id, role_id;

bool find_match(const string& a, const string& b, int& rank)
{
	int pos_a = a.find(':'), pos_b = b.find(':');
	bool A = ( pos_a >= 0 ), B = ( pos_b >= 0);
	
	if (!A && !B) return a==b;
	else if (A && B)
	{
		string a_name = a.substr(0, pos_a), b_name = b.substr(0, pos_b);
		char a_rank = a[pos_a+1], b_rank = b[pos_b+1];
		
		return a_name==b_name && a_rank<=b_rank;
	}
	else if (!A && B)
	{
		string a_name = a.substr(0, pos_a), b_name = b.substr(0, pos_b);
		char b_rank = b[pos_b+1];
		
		if (a_name == b_name) { rank = max(rank, b_rank-'0'+0); return true; }
		else return false;
	}
	else return false;
}


int main()
{
	string str;
	int p, r, u;
	cin >> p; for (int i=0; i<p; i++) cin >> str;
	
	cin >> r; role_id.clear();
	int s;
	for (int i=0; i<r; i++) {
		cin >> str >> s;
		role_id[str] = i;
		privi_list[i].clear();
		privi_list[i].resize(s);
		for (int k=0; k<s; k++) cin >> privi_list[i][k];
	}
	
	cin >> u; user_id.clear();
	int t;
	for (int i=0; i<u; i++) {
		cin >> str >> t;
		user_id[str] = i;
		role_list[i].clear();
		for (int k=0; k<t; k++) {
			cin >> str;
			role_list[i].push_back( role_id[str] );
		}
	}
	
	int q; cin >> q;
	string q_user, q_privi;
	while (q--)
	{
		int rank = -1;
		bool find = false;
		
		cin >> q_user >> q_privi;
		
		if (user_id.count(q_user))
		{	
			int user = user_id[q_user];	
			vector<int>& rL = role_list[user];
			for (int i=0; i<rL.size(); i++)
			{
				int role = rL[i];
				vector<string>& pL = privi_list[role];
				for (int k=0; k<pL.size(); k++) {
					string privilege = pL[k];
					if ( find_match(q_privi, privilege, rank) ) { find = true; }
				}
			}
		}
		
		if (rank >= 0) {
			cout << rank << '\n';
			continue;
		}
		
		if (find) cout << "true\n";
		else cout << "false\n";
	}
	
	return 0;
}
