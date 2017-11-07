#include <iostream>
using namespace std;

//�����Ϊ������
//���ݴ洢
//������
//�������
//Ϊ�˱��ڳ�����д������ģ�黯�����������������ֿ��������˳������е�Ч��

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
	//���ݴ洢
	win *window;
	window = new win[n];
	for (int i = 0; i < n; i++)
	{
		cin >> window[i].x1 >> window[i].y1
			>> window[i].x2 >> window[i].y2;
	}
	//������
	bool canvas[101][101] = {false};
	for (int i = 0; i < n; i++)
	{
		DrawOnCanvas(canvas, window[i]);
	}
	//�������
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