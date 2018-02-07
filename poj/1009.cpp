/*
	note:	POJ1009
	date:	2018/2/7
	tag:	跳跃搜索 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define maxsize 1050

int width;					// 宽度 (列数)
int total;					// 输入总个数 

struct Data
{
	int pix;
	int index;
};
Data input[maxsize];
Data output[8 * maxsize];

int GetPix(int ind)			// 返回该点的值 
{
	int i = 0;
	while (ind >= input[i].index)
		++i;

	return input[i - 1].pix;
}

int GetOutPix(int ind)		// 返回该点的输出值 
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
			if (i<0 || i >= total / width || j<0 || j >= width || (i == r && j == c))		// 不能包含本身 
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

	// 读取数据 
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

		// 处理图像数据  
		int ind;
		int outNum = 0;
		for (int k = 0; k < inNum; ++k)						// 取遍变化的起点
		{
			ind = input[k].index;
			int pos;

			// 计算相关联的九个值  
			for (int i = -width;i <= width;i += width)
			{
				for (int j = -1; j <= 1; j++)
				{
					pos = ind + i + j;
					if (pos < 0 || pos >= total)
						continue;

					// 在数据范围中
					output[outNum].index = pos;
					output[outNum].pix = GetOutPix(pos);
					++outNum;
				}
			}
		}
		// 最后一行的行首需要计算 ,因为最后一行 没有下一行 的影响 所以较特殊 
		output[outNum].index = total - width;
		output[outNum].pix = GetOutPix(total - width);
		++outNum;
		
		output[outNum].index = total;
		output[outNum].pix = -1;

		// 排序
		sort(output, output + outNum, cmp);

		// 无重复的输出 
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
