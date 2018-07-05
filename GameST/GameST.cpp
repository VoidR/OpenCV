// GameST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	double dtime = (double)getTickCount();//获取开始时间


	IplImage* back0 = cvLoadImage("Pic\\back1.jpg");
	IplImage* backt = cvCloneImage(back0);
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	cvShowImage("Face", back0);

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
		player1.Move(key);
		robot.Move();
		cvCopy(back0, backt);
		player1.Draw2Back(backt);
		robot.Draw2Back(backt);
		cvShowImage("Face", backt);
	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);
	cvReleaseImage(&back0);
	cvReleaseImage(&backt);
	delete &player1;
	delete &robot;
	cvDestroyAllWindows();

	return 0;
}

