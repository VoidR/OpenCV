#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int bmain()
{
	double dtime = (double)getTickCount();//获取开始时间
	Mat img = imread("baboon.jpg", IMREAD_GRAYSCALE);
	uchar lutdata[256];
	for (int i = 0; i < 256; i++)
	{
		/*if (i < 50)	lutdata[i] = 0;
		else if (i < 100)	lutdata[i] = 50;
		else if (i < 150)	lutdata[i] = 100;
		else if (i < 200)	lutdata[i] = 150;
		else lutdata[i] = 200;*/
		if (i < 50)	lutdata[i] = 255;
		else lutdata[i] = i;
	}
	Mat lut(1, 256, CV_8UC1, lutdata);
	imshow("灰度原图", img);
	Mat result;
	LUT(img, lut, result);
	imshow("lut处理后", result);
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << dtime << endl;
	waitKey(0);
	return 0;
}