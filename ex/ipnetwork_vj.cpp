#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1005;
unsigned int a[maxn];

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int m, ip[4];;
	while (scanf("%d", &m) == 1)
	{
		for (int i=0; i<m; i++){
			scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
			unsigned int t = 0; for (int k=0; k<4; k++) { t <<= 8; t |= ip[k]; }
			a[i] = t;
		}
		
		std::sort(a, a+m);
		unsigned min = a[0], max = a[m-1];
		
		unsigned t_mask = min ^ max;
		int k;  for (k=0; k<32 && (t_mask>>k); k++);
		
		unsigned int ip_mask = (k==32)? 0: ( ~( t_mask >> k) << k);
		unsigned int ip_addr = ip_mask & min;
		
		for (int i=0; i<4; i++) { ip[i] = ip_addr & 0xff;  ip_addr >>= 8; }
		printf("%d.%d.%d.%d\n", ip[3], ip[2], ip[1], ip[0]);
		
		for (int i=0; i<4; i++) { ip[i] = ip_mask & 0xff;  ip_mask >>= 8; }
		printf("%d.%d.%d.%d\n", ip[3], ip[2], ip[1], ip[0]);
	}
	
	return 0;
}

/*
input:
3
0.0.0.0
0.0.0.0
255.0.0.0

output:
0.0.0.0
0.0.0.0

*/
