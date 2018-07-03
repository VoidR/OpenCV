#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int bmain()
{
	double dtime = (double)getTickCount();//��ȡ��ʼʱ��
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
	imshow("�Ҷ�ԭͼ", img);
	Mat result;
	LUT(img, lut, result);
	imshow("lut�����", result);
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//��ȡ����ʱ�䣬getTickFrequency()����ÿ��ļ�ʱ������
	cout << dtime << endl;
	waitKey(0);
	return 0;
}