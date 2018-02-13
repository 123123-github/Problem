/*
	note:	poj1028 
	date:	2018/2/10 
	tag:	Êı×éÄ£Äâ Õ» 
*/

#include <iostream>
#include <cstring>
using namespace std;

#define VISIT 1
#define BACK 2
#define FORWARD 3
#define QUIT 0

int getIns(const char* s)
{
	switch (*s)
	{
		case 'V':
			return VISIT;
		case 'B':
			return BACK;
		case 'F':
			return FORWARD;
		case 'Q':
			return QUIT;
	}
}

int main()
{
	string urlSet[500];
	int num = 0;
	int count = 0;
	
	urlSet[num++] = "http://www.acm.org/";

	char ins[10];
	string url;
	int i;
	
	while (cin >> ins)
	{
		i = getIns(ins);
		switch(i)
		{
			case VISIT:
				
				cin >> url;
				urlSet[num++] = url;
				cout << url << '\n';
				count = 0;		
				break;
			
			case BACK:
				if (num == 1)
					cout << "Ignored\n";
				else
				{
					cout << urlSet[num-2] << '\n';
					--num;
					++count;
				}
				break;
			
			case FORWARD:
				if (count == 0)
					cout << "Ignored\n";
				else
				{
					cout << urlSet[num++] << '\n';
					--count;
				}
				break;
			
			case QUIT:
				return 0;
		}	
	}
	return 0;
}
