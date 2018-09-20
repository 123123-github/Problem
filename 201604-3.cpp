/*
	date:	9/9/2018
	tag:	201604-3
*/

#include <iostream>
#include <string>
using namespace std;

const int maxn = 1005;

char s[maxn];
string cur, line;

int main()
{
	int p, pos;
	cin >> p >> cur;
	cin.get();
	
	while (p--)
	{
		cin.getline(s, maxn, '\n');
		line = s;
		
		// add root
		if (line[0] != '/') line = cur + '/' + line + '/';
		
		// multi slash
		while ( (pos = line.find("//")) != -1 )
		{
			int cnt = 2;
			while (line[pos+cnt]=='/') cnt++;
			line.erase(pos, cnt-1);
		}
		
		// "./"
		while ( (pos = line.find("/./")) != -1 ) line.erase(pos+1, 2);
		
		// "../"
		while ( (pos = line.find("/../")) != -1 )
		{
			line.erase(pos+1, 3);
			
			if (pos != 0)
			{
				int pre_pos = line.rfind("/", pos-1);
				line.erase(pre_pos+1, pos-pre_pos);
			}
		}
		
		if (line.size() == 0) line = "/";
		if (line.size() > 1 && line[line.size()-1]=='/') line.erase(line.size()-1);
		
		cout << line << '\n';
	}
	
	return 0;
}
