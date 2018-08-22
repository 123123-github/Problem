/*
	date:	7/21/2018
	tag:	ccf csp 201803-3	
*/

#include <iostream>
#include <string>
using namespace std;

bool match(string s1, string s2, bool output)
{
	int k1=0, k2=0, len1=s1.length(), len2=s2.length();
	
	while (k1<len1 && k2<len2)
	{
		if (s1[k1] == s2[k2])
		{
			k1++,k2++;
			continue;
		}
		
		if (s1[k1++] != '<')	return false;
		
		if (output)	cout << ' ';
		
		if (s1[k1] == 'i')			// int 
		{
			bool numBeg = false;
			
			while (s2[k2] && isdigit(s2[k2]))
			{
				if (s2[k2] > '0')	numBeg = true;
				if (output && numBeg)	cout << s2[k2];
				k2++;
			}
			if (!numBeg)	return false;
			k1 += 4;
		}
		else if (s1[k1] == 's')		// str
		{
			bool isStr = false;
			
			while (s2[k2] && isalnum(s2[k2]))
			{
				isStr = true;
				if (output && isStr)	cout << s2[k2];
				k2++;
			}
			if (!isStr)		return false;
			k1 += 4;
		}
		else if (s1[k1] == 'p')		// path
		{
			if (output) while (s2[k2]) cout << s2[k2++];
			return true;
		}
	}
	
	return (k1==len1 && k2==len2);
}


int main()
{
	int n, m;
	cin >> n >> m;
	string p[n], r[n], s;
	
	for (int i=0; i<n; i++)	cin >> p[i] >> r[i];
	
	for (int i=0; i<m; i++)
	{
		cin >> s;
		bool find = false;
		
		for (int j=0; j<n && !find; j++)
		{
			if (match(p[j], s, false))
			{
				find = true;
				cout << r[j];
				match(p[j], s, true);
			}
		}	
		if (!find)	cout << "404";
		cout << endl;
	}
	
	return 0;
}
