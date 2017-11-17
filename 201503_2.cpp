#include <iostream>
using namespace std;

struct NumCount
{
	int num;
	int count;
};

void Sort(NumCount a[],int n)
{
	int p;
	NumCount t;
	
	for(int i=1;i<n-1;i++)
	{
		p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[p].count<a[j].count)
				p=j;
			else if(a[p].count==a[j].count && a[p].num>a[j].num)
				p=j;
		}
		if(p!=i)
		{
			t=a[p];
			a[p]=a[i];
			a[i]=t;
		}
	}
	return;
}

int main() 
{
	int *num,N;
	//�������� 
	cin>>N;
	num=new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>num[i];
	}
	
	//��ʼ��ͳ�Ʊ� 
	NumCount a[1001];
	for(int i=0;i<1001;i++)
	{
		a[i].num=i;
		a[i].count=0;
	}
	//���� 
	int n;
	for(int i=0;i<N;i++)
	{
		n=num[i];
		a[n].count++;
	}
	//����
	Sort(a,1001);
	
	//���
	//�ҵ����������
	int p;
	for(int i=1;i<=N;i++)
	{
		if(a[i].count==0)
		{
			p=i;
			break;
		}
	} 
	for(int i=1;i<p;i++)
	{
		cout<<a[i].num<<' '<<a[i].count<<'\n'; 
	}
	
	//�ͷſռ�
	delete num; 
	
	return 0;
}
