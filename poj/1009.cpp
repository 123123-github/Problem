/*
	note:	POJ1009
	date:	2018/2/7
	tag:	��Ծ���� 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define maxsize 1050

int width;					// ��� (����)
int total;					// �����ܸ��� 

struct Data
{
	int pix;
	int index;
};
Data input[maxsize];
Data output[8 * maxsize];

int GetPix(int ind)			// ���ظõ��ֵ 
{
	int i = 0;
	while (ind >= input[i].index)
		++i;

	return input[i - 1].pix;
}

int GetOutPix(int ind)		// ���ظõ�����ֵ 
{
	int p = GetPix(ind);
	int t;

	int max = 0;
	int r = ind / width;
	int c = ind % width;

	for (int i = r - 1; i <= r + 1; ++i)
	{
		for (int j = c - 1; j <= c + 1; ++j)
		{
			if (i<0 || i >= total / width || j<0 || j >= width || (i == r && j == c))		// ���ܰ������� 
				continue;

			t = abs(GetPix(i*width + j) - p);
			max = max<t ?  t:max;
		}
	}

	return max;
}

bool cmp(const Data& a, const Data&b)
{
	return a.index<b.index;
}

int main()
{
	int pix, num;

	// ��ȡ���� 
	while (scanf("%d", &width) && width)
	{
		total = 0;
		int inNum = 0;

		while (scanf("%d%d", &pix, &num) && (pix || num))
		{
			input[inNum].index = total;
			input[inNum].pix = pix;

			total += num;
			++inNum;
		}
		input[inNum].index = total;
		input[inNum].pix = -1;

		// ����ͼ������  
		int ind;
		int outNum = 0;
		for (int k = 0; k < inNum; ++k)						// ȡ��仯�����
		{
			ind = input[k].index;
			int pos;

			// ����������ľŸ�ֵ  
			for (int i = -width;i <= width;i += width)
			{
				for (int j = -1; j <= 1; j++)
				{
					pos = ind + i + j;
					if (pos < 0 || pos >= total)
						continue;

					// �����ݷ�Χ��
					output[outNum].index = pos;
					output[outNum].pix = GetOutPix(pos);
					++outNum;
				}
			}
		}
		// ���һ�е�������Ҫ���� ,��Ϊ���һ�� û����һ�� ��Ӱ�� ���Խ����� 
		output[outNum].index = total - width;
		output[outNum].pix = GetOutPix(total - width);
		++outNum;
		
		output[outNum].index = total;
		output[outNum].pix = -1;

		// ����
		sort(output, output + outNum, cmp);

		// ���ظ������ 
		printf("%d\n", width);
		int start = 0;
		for (int i = 0; i < outNum; ++i)
		{
			while (i < outNum && output[i].pix == output[i + 1].pix)
				++i;

			printf("%d %d\n", output[i].pix, output[i + 1].index - start);
			start = output[i + 1].index;
		}
		printf("0 0\n");
	}
	printf("0\n");
	
	return 0;
}
