//CSP �𳵹�Ʊ
#include <iostream>
using namespace std;

//�𳵵�������ÿ�ŵ���λ��
#define ROW 20
#define COL 5

//��Ʊָ��ķ������
struct OrderFeedback
{
	int row;	//��Ʊ������
	int left;	//������ʱʣ���Ʊ��
	int num;	//���ߵ�Ʊ��
};

//����Ʊ������Ϊ��Ʊָ�������ĳ�Ʊ�����������ط������
void GetTickets(int train[], int order, OrderFeedback *feedback, int &InsNum)
{
	InsNum = 0;
	//������ȫ����λ
	for (int i = 0; i < ROW; i++)
	{
		if (train[i]>=order)
		{
			feedback[InsNum].left = train[i];
			feedback[InsNum].row = i;
			feedback[InsNum].num = order;

			train[i] -= order;
			InsNum++;
			return;
		}
	}
	//�򲻵�ȫ����λ
	int sum = 0;
	int i = 0;
	InsNum = 0;
	while (sum<order)
	{
		if (train[i]!=0)
		{
			sum += train[i];
			feedback[InsNum].row = i;
			feedback[InsNum].left = train[i];
			feedback[InsNum].num = train[i];
			InsNum++;
		}
		i++;
	}
	//�޸����һ�ι�Ʊ����Ŀ
	sum -= train[i - 1];
	train[i - 1] -= order - sum;

	return;
}
//��ӡ���ε��ŵķ������ feedback
void PrintSingleOrder(OrderFeedback feedback)
{
	int start;
	start = COL*feedback.row + (COL - feedback.left + 1);

	for (int i = 0; i < feedback.num; i++)
	{
		cout << start + i << ' ';
	}
	return;
}

int main()
{
	//��Ʊָ������
	int num_order;
	cin >> num_order;
	int *order;
	order = new int[num_order];
	for (int i = 0; i < num_order; i++)
	{
		cin >> order[i];
	}

	//��ʼ������λ
	int train[ROW];
	for (int i = 0; i < ROW; i++)
	{
		train[i] = COL;
	}

	OrderFeedback feedback[5];
	int num_feedback;
	//ִ�� num_order ����Ʊָ��
	for (int i = 0; i < num_order; i++)
	{
		//��ó�Ʊ����
		GetTickets(train, order[i], feedback, num_feedback);
		//��ӡ��Ʊ
		for (int i = 0; i < num_feedback; i++)
		{
			PrintSingleOrder(feedback[i]);
		}
		cout << '\n';
	}

	//�ͷſռ�
	delete order;

	system("pause");

	return 0;
}