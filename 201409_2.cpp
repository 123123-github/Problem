#include <iostream>
using namespace std;

//程序分为三部分
//数据存储
//画矩形
//计算面积
//为了便于程序书写及更加模块化，画矩形与计算面积分开，降低了程序运行的效率

struct win
{
	int x1, y1;
	int x2, y2;
};

void DrawOnCanvas(bool canvas[][101], win window)
{
	for (int i = window.x1; i < window.x2; i++)
	{
		for (int j = window.y1; j < window.y2; j++)
		{
			canvas[i][j] = true;
		}
	}

	return;
}

int main()
{
	int n;
	cin >> n;
	//数据存储
	win *window;
	window = new win[n];
	for (int i = 0; i < n; i++)
	{
		cin >> window[i].x1 >> window[i].y1
			>> window[i].x2 >> window[i].y2;
	}
	//画矩形
	bool canvas[101][101] = {false};
	for (int i = 0; i < n; i++)
	{
		DrawOnCanvas(canvas, window[i]);
	}
	//计算面积
	int area = 0;
	for(int i=0;i<101;i++)
		for (int j = 0; j < 101; j++)
		{
			if (canvas[i][j])
				area++;
		}

	cout << area;

	delete window;

	system("pause");

	return 0;
}