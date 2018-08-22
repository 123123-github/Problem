// date: 8/3/2018
// ccf csp 201703-0 Markdown
#include <cstdio>
#include <cstring>
#include <cctype>

const int maxn = 105;
char str[maxn];
bool in_para = false, in_list = false;
char text[maxn], link[maxn];

void deal_line(char *s)
{
	bool first = true;
	
	int len = strlen(s);
	for (int i=0; i<len-1; i++)
	{
		if (s[i] == '_')
		{
			printf("%s", first? "<em>": "</em>");
			first = !first;
		}
		else if (s[i] == '[')
		{
			memset(text, '\0', sizeof(text));
			memset(link, '\0', sizeof(link));
			
			int t_begin = i + 1, t_end = strchr(s+i, ']') - s;
			int l_begin = strchr(s+t_end, '(') + 1 - s, l_end = strchr(s+l_begin, ')') - s;
			
			strncpy(text, s+t_begin, t_end-t_begin);
			strncpy(link, s+l_begin, l_end-l_begin);
			
			printf("<a href=\"");
			for (int k=l_begin; k<l_end; k++)
				if (s[k] == '_')
				{
					printf("%s", first? "<em>": "</em>");
					first = !first;
				}
				else
					putchar(s[k]);
			printf("\">");
			for (int k=t_begin; k<t_end; k++)
				if (s[k] == '_')
				{
					printf("%s", first? "<em>": "</em>");
					first = !first;
				}
				else
					putchar(s[k]);
			printf("</a>");
			
			i = l_end;
		}	
		else
			putchar(s[i]);
	}
}

void deal_header(char *s)
{
	char t[10];
	sscanf(s, "%s", t);
	
	int d = strlen(t);
	printf("<h%d>", d);
	
	int i;
	for (i=d; s[i] && s[i] == ' '; i++); 
	deal_line(s + i);
	
	printf("</h%d>\n", d);
}

void deal_para(char *s)
{
	deal_line(s);
}

void deal_list(char *s)
{
	printf("<li>");
	
	int i;
	for (i=1; s[i] && s[i] == ' '; i++); 
	
	deal_line(s + i);
	
	printf("</li>\n");
}


int main()
{
	//freopen("data.txt", "r", stdin);
	
	while (fgets(str, maxn, stdin))
	{
		char ch = str[0];
		
		if (in_para)
		{
			if (isspace(ch)){
				in_para = false;
				printf("</p>\n");
			}
			else
			{
				putchar(10);
				deal_para(str);
			}
			
		}
		else if (in_list)
		{
			if (isspace(ch)){
				in_list = false;
				printf("</ul>\n");
			}
			else
				deal_list(str);
		}
		else
		{
			if (ch == '*'){
				in_list = true;  printf("<ul>\n");
				deal_list(str);
			}
			else if (ch == '#')
				deal_header(str);
			else if (isspace(ch))
				continue;
			else{
				in_para = true;  printf("<p>");
				deal_para(str);
			}
		}
	}
	if (in_para)  printf("</p>");
	else if (in_list)  printf("</ul>");
	
	return 0;
}
