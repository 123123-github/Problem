#include <iostream>
using namespace std;

int main()
{
	char num[15];
	cin >> num;

	int sum = 0, i = 0, plus;

	while (num[i])
	{
		plus = num[i] - '0';
		sum += plus;
		i++;
	}

	cout << sum;

	return 0;
}