/*
	note:	csp201412-3
	date:	2018/2/14
	tag:	??? 80 ???
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const char BUY = 'b';
const char SELL = 's';
const char CANCEL = 'c';

struct Record
{
	char tag;
	float money;
	long long mount;
}rSet[5010];
int rNum = 0;

bool cmp(const Record& a,const Record& b)
{
	return (a.money==b.money)? a.tag<b.tag: a.money>b.money;
}

int main()
{
	char ins[10];		// ��¼����
	float price;		// �۸�
	long long int num;	// ����
	int pos;			// �����ļ�¼
	
	while (cin >> ins)
	{
		rSet[rNum].tag = *ins;
		
		if (*ins == CANCEL)					// ���Ϊ ����  
		{
			rSet[rNum].money = 0;
			++rNum;
			
			cin >> pos;
			rSet[pos-1].tag = 'c';
			
			continue; 
		}
		cin >> price >>  num;
		
		rSet[rNum].money = price;
		rSet[rNum].mount = num;
		++rNum;
	}
	
	sort(rSet,rSet+rNum,cmp);		// ���ռ۸�Ӵ�С���� 
	
	int sum = 0;
	for (int i=0; i<rNum; ++i)		// ��ǰ������� b  
	{
		if (rSet[i].tag == BUY)
		{
			rSet[i].mount += sum;
			sum = rSet[i].mount;
		}
	}
	sum = 0;
	for (int i=rNum-1; i>=0; --i)	// �Ӻ���ǰ���� s 
	{
		if (rSet[i].tag == SELL)
		{
			rSet[i].mount += sum;
			sum = rSet[i].mount;
		}
	} 
	
	long long int outNum = 0;
	float outPrice = 0;
	long long mA = 0;
	long long mB = 0;
	long long mC;
	
	for (int i=0; i<rNum; ++i)
	{
		if (rSet[i].tag == BUY)
		{
			mA = rSet[i].mount;
			for (int j=i+1; j<rNum; ++j)
			{
				if (rSet[j].tag == SELL)
				{
					mB = rSet[j].mount;
					break;
				}
			}
			
			mC = (mA<mB)? mA: mB;
		}
		else if (rSet[i].tag == SELL)
		{
			mA = rSet[i].mount;
			for (int j=i-1; j>=0; --j)
			{
				if (rSet[j].tag == BUY)
				{
					mB = rSet[j].mount;
					break;
				}
			}
			
			mC = (mA<mB)? mA: mB;
		}
		else
			continue;
		
		if (outNum < mC)
		{
			outNum = mC;
		 	outPrice = rSet[i].money;
		}
		
		mA = mB = 0;
	}
	
	cout << fixed << setprecision(2);
	cout << outPrice << ' ' << outNum;
	
	return 0;
}
