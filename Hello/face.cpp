#include<opencv2\opencv.hpp>
#include<iostream>
#include "Player.h"
using namespace std;
using namespace cv;

int main()
{
	double dtime = (double)getTickCount();//��ȡ��ʼʱ��

	IplImage* back0 = cvLoadImage("pic\\back1.jpg");
	IplImage* backt = cvCloneImage(back0);
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	cvShowImage("Face", back0);

	Player player;

	//��ͣ���հ���
	while (1)
	{
		char key = cvWaitKey(40);
		player.Move(key);
		cvCopy(back0, backt);
		player.Draw2Back(backt);
		cvShowImage("Face", backt);
	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//��ȡ����ʱ�䣬getTickFrequency()����ÿ��ļ�ʱ������
	cout << "��ʱ��" << dtime << "s" << endl;

	waitKey(0);
	cvReleaseImage(&back0);
	cvReleaseImage(&backt);
	delete &player;
	cvDestroyAllWindows();

	return 0;
}