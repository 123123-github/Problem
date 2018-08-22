#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000;

int A[maxn];
int P[maxn];

bool in_array(int* A, int len, int d, int n)
{
	int c1 = 0, c2 = 0;
	for (int i=0; i<len; i++) if (A[i] == d) c1++;
	for (int i=0; i<n; i++) if (P[i] == d) c2++;
	if (c1 < c2)  return false;
	
	return true;
}

void print_permutation(int *A, int* P, int n, int len)
{
	if (len == n) {
		for (int i=0; i<len; i++)  printf("%d", A[i]);
		putchar(10);
	}
	else {
		for (int i=0; i<n; i++) if (!i || P[i] != P[i-1]){
			if (!in_array(A, len, P[i], n)){
				A[len] = P[i];
				print_permutation(A, P, n, len+1);
			}
		}
	}
}

int main()
{
	int n;
	
	while (scanf("%d", &n)==1)
	{
		for (int i=0; i<n; i++) scanf("%d", P+i);
		sort(P, P+n);
		
		print_permutation(A, P, n, 0);
	}
	
	return 0;
}
