#include<opencv2\opencv.hpp>
#include<iostream>
#include "Player.h"
using namespace std;
using namespace cv;

int main()
{
	double dtime = (double)getTickCount();//获取开始时间

	IplImage* back0 = cvLoadImage("pic\\back1.jpg");
	IplImage* backt = cvCloneImage(back0);
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	cvShowImage("Face", back0);

	Player player;

	//不停接收按键
	while (1)
	{
		char key = cvWaitKey(40);
		player.Move(key);
		cvCopy(back0, backt);
		player.Draw2Back(backt);
		cvShowImage("Face", backt);
	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);
	cvReleaseImage(&back0);
	cvReleaseImage(&backt);
	delete &player;
	cvDestroyAllWindows();

	return 0;
}