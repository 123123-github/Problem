//CSP �𳵹�Ʊ
#include <iostream>
using namespace std;

struct Train
{
	int seat_num;
	bool status;
};
//��Ե�����Ʊ��Ϣ��ӡ��Ʊ
void PrintTicksts(int order, Train train[][5], int leftticksts[])
{
	for (int i = 0; i < 20; i++)
	{
		if (leftticksts[i]>=order)
		{
			//��Ʊ
			leftticksts[i] -= order;
			//��ӡ��λ
			for (int j = 0; j < 5; j++)
			{
				if (order && train[i][j].status)
				{
					cout << train[i][j].seat_num << ' ';
					train[i][j].status = false;
					order--;
				}
			}
			//�ҵ�������λ����ӡ�공Ʊ�󷵻�
			return;
		}
	}
	//�Ҳ�������λ
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (order && train[i][j].status)
			{
				cout << train[i][j].seat_num << ' ';
				train[i][j].status = false;
				order--;
			}
			if (order==0)
			{
				return;
			}
		}
	}
}

int main()
{
	Train train[20][5];
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			train[i][j].seat_num = 5 * i + j + 1;
			train[i][j].status = true;
		}
	}
	int lefttickets[20];
	for (int i = 0; i < 20; i++)
	{
		lefttickets[i] = 5;
	}
	//ָ����
	int n;
	cin >> n;
	int *order;
	order = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> order[i];
	}
	//��Ʊ
	for (int i = 0; i < n; i++)
	{
		PrintTicksts(order[i], train, lefttickets);
		cout << endl;
	}
	//�ռ��ͷ�
	delete order;

	system("pause");

	return 0;
}