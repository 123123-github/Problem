// score 60
// ccf csp »®œﬁ≤È—Ø 
#include <cstdio>
#include <cstring>
#include <cctype>

const int maxn = 105;
int p, r, u;

char privi[maxn][50];
struct Tag
{
	char name[52];
	int  num;
	char tag[10][35];
} role[maxn], user[maxn];


int q;
char t_user[maxn], t_privi[maxn];
int exist = 0;
bool cate = false, first = true;
char t_role[maxn];

char t_privi_f[maxn], role_f[maxn];

bool search_role(Tag &role)
{
	for (int i=0; i<role.num; i++)  if (role.tag[i][0] == t_privi[0])
	{	
		int r_len = strlen(role.tag[i]), t_len = strlen(t_privi);

//		if (strcmp(role.tag[i], t_privi) == 0)
//			exist = 1;

		if (cate)
		{
			if ( (strchr(privi[i],':') - privi[i]) >= 0)
			{
				if ((t_len == r_len-2) && (strncmp(t_privi, role.tag[i], t_len) == 0)){
					int t = role.tag[i][r_len-1] - '0' + 0;
					if (t > exist){
						exist = t;
					}
				}
			}
		}
		else
		{
			int t;
			if ( (t = strchr(privi[i],':') - privi[i]) >= 0)
			{
				if ((t_len == r_len) && strncmp(t_privi, role.tag[i], t_len-2) && (t_privi[t+1]>=role.tag[i][t+1]))
					exist = 1;
			}
			if (strcmp(role.tag[i], t_privi) == 0)
				exist = 1;
		}
	}
}

bool search_user(Tag &user)
{
	for (int i=0; i<user.num; i++){
		strcpy(t_role, user.tag[i]);		
	
		for (int k=0; k<r; k++)  if (t_role[0] == role[k].name[0]) {
			if (strcmp(t_role, role[k].name) == 0)
				search_role(role[k]);
		}
	}
}


int main()
{
	freopen("data.txt", "r", stdin);

	int s, t;	
	scanf("%d", &p);
	for (int i=0; i<p; i++)  scanf("%s", privi[i]);
	scanf("%d", &r);
	for (int i=0; i<r; i++){
		scanf("%s%d", role[i].name, &s);
		for (int j=0; j<s; j++)  scanf("%s", role[i].tag[j]);
		role[i].num = s;
	}
	scanf("%d", &u);
	for (int i=0; i<u; i++){
		scanf("%s %d", user[i].name, &t);
		for (int j=0; j<t; j++)  scanf("%s", user[i].tag[j]);
		user[i].num = t;
	}
	
	
	scanf("%d", &q);	
	while (q--)
	{	
		exist = 0;  first = true;  cate = false;
		
		scanf("%s %s", t_user, t_privi);
	
		int len1 = strlen(t_privi);
		for (int i=0; i<p; i++)  if(privi[i][0] == t_privi[0]){
			int len2 = strlen(privi[i]);
			if ( isdigit(privi[i][len2-1]) && (len1==len2-2) && (strncmp(t_privi, privi[i], len1) == 0) )
				cate = true;
		}
	
		for (int i=0; i<u; i++)  if (t_user[0] == user[i].name[0]){
			if (strcmp(t_user, user[i].name) == 0)
				search_user(user[i]);
		}
		
		if (cate && exist)
			printf("%d\n", exist);
		else
			printf("%s\n", exist? "true": "false");
			
	}
	
	return 0;
}
