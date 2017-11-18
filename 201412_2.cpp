// Z 字形扫描 
#include <iostream>
using namespace std;

//输出函数
void PPrint(int **a,int col,int start,int end)
{
	for(int i=start;i<end;i++)
	{
		cout<<a[i][col]<<' ';
	}
	return;
}

void NPrint(int **a,int col,int start,int end)
{
	for(int i=end-1;i>=start;i--)	//此处 i>=start , 第一次编写错。i-- 时,要注意判断条件。 
	{
		cout<<a[i][col]<<' ';
	}
	return;
}

int main()
{
	int **a;
	int N;
	//数据输入 空间分配在 N * （2 * N -1） 的矩阵中 
	cin>>N;
	a=new int*[N];
	for(int i=0;i<N;i++)
	{
		a[i]=new int[2*N-1];
	}
	
	//矩阵输入
	int k=0;
	for(int i=0;i<N;i++,k++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>a[i][j+k];
		}
	}
	
	// Z 字形输出
	for(int i=0;i<N;i++)
	{
		if(i%2==0)
			NPrint(a,i,0,i+1);
		else
			PPrint(a,i,0,i+1);
	}
	for(int j=N;j<2*N-1;j++)
	{
		if(j%2==0)
			NPrint(a,j,j-N+1,N);
		else
			PPrint(a,j,j-N+1,N);
	}
	
	//空间释放
	for(int i=0;i<N;i++)
	{
		delete[] a[i];
	}
	delete[] a;
	
	return 0;
}