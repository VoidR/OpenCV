#include<opencv2\opencv.hpp>
#include<iostream>
#include<Windows.h>
#include "Player.h"
#include "Doraemon.h"
#include "Baobao.h"
using namespace std;
using namespace cv;


void runplayer(Player &p1, IplImage*& pback, int opt)
{
	char key = 's';
	IplImage* t = cvCloneImage(pback);

	//cvShowImage("t", t);
	switch (opt)
	{
		case 0: key = 's'; break;
		case 1: key = 'd'; break;
		case 2: key = 'w'; break;
		case 3: key = 'a'; break;
	}
	for (int i = 0; i < 10; i++)
	{
		p1.Move(key);
		cvCopy(pback, t);
		p1.Draw2Back(t);
		cvShowImage("Face", t);
		Sleep(50);
	}
}
int main()
{
	double dtime = (double)getTickCount();//获取开始时间


	IplImage* back0 = cvLoadImage("pic\\back1.jpg");
	IplImage* backt = cvCloneImage(back0);
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	cvShowImage("Face", back0);

	Doraemon player1;
	Baobao player2;

	//初始显示
	player2.Draw2Back(backt);
	player1.Draw2Back(backt);
	cvShowImage("Face", backt);

	int n = 0;
	//不停接收按键
	while (1)
	{
		//char key1 = cvWaitKey(10);
		char key2 = cvWaitKey(0);
		//if (key1 == '0'||key2=='0')	break;
		if (key2 == '0')	break;
		//player1.Move(key1);
		player2.Move(key2);
		cvCopy(back0, backt);
		/*for (int i = 0; i < 12; i++)
		{
			cvCopy(back0, backt);
			player2.Move(key2);
			player2.Draw2Back(backt);
			Sleep(3);
		}*/
		player2.Draw2Back(backt);
		runplayer(player1, backt, n);
		n = (n + 1) % 4;
		//player1.Draw2Back(backt);
		//cvShowImage("Face", backt);

	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);
	cvReleaseImage(&back0);
	cvReleaseImage(&backt);
	delete &player1;
	cvDestroyAllWindows();

	return 0;
}