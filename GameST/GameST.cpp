// GameST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

const int map_x = 16;
const int map_y = 22;
int MAP[map_x + 2][map_y + 2];

void Draw2Back(IplImage* pback, char* str, int x, int y)
{
	int X = (y - 1) * 40, Y = (x - 1) * 40;
	IplImage* pimg = cvLoadImage(str);
	for (int i = 0; i < pimg->height; i++)
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if (top_b >= 230 && top_r >= 230 && top_r >= 230)
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + Y, (j + X) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + Y, (j + X) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + Y, (j + X) * 3 + 2) = top_r;
		}
}
int main()
{
	double dtime = (double)getTickCount();//获取开始时间

	ifstream in;
	in.open("map.txt");
	if (in.is_open())
	{
		for (int i = 0; i <= map_x+1; i++)
		{
			for (int j = 0; j <= map_y+1; j++)
				in >> MAP[i][j];
		}
		in.close();
	}
	else
	{
		cout << "地图打开错误." << endl;
	}
	/*int i, j; 
	for (i = 0; i <= 17; i++)
	{
		for (j = 0; j <= 23; j++)
			cout << MAP[i][j];
		if (j == 24)	cout << "\n";
		else cout << "\t";
	}*/

	IplImage* back0 = cvLoadImage("Pic\\back1.jpg");
	IplImage* backcreate = cvCloneImage(back0);
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Face", backcreate);

	char str_obstacle[] = "Pic\\obstacle0.jpg";
	char str_stone[] = "Pic\\stone0.jpg";
	for (int i = 1; i <= map_x; i++)
	{
		for (int j = 1; j <= map_y; j++)
		{
			//cout << MAP[i][j] << "\t";
			if (MAP[i][j] >= 4)
			{
				str_stone[9] = '0' + MAP[i][j] - 3;
				Draw2Back(backcreate, str_stone, i, j);
			}
			else if (MAP[i][j] > 0)
			{
				str_obstacle[12] = '0' + MAP[i][j];
				//cout << str_obstacle << endl;
				Draw2Back(backcreate, str_obstacle, i, j);
			}
		}
		cout << endl;
	}
	IplImage* backt = cvCloneImage(backcreate);

	CRobot robot;
	CBaoBao player1;

	//初始显示
	robot.Draw2Back(backt);
	player1.Draw2Back(backt);
	cvShowImage("Face", backt);

	//不停接收按键
	while (1)
	{
		char key = cvWaitKey(40);
		if (key == '0')	break;
		player1.Move(key);
		robot.Move();
		cvCopy(backcreate, backt);
		player1.Draw2Back(backt);
		robot.Draw2Back(backt);
		cvShowImage("Face", backt);
	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);
	cvReleaseImage(&back0);
	cvReleaseImage(&backcreate);

	cvReleaseImage(&backt);
	delete &player1;
	delete &robot;
	cvDestroyAllWindows();

	return 0;
}

