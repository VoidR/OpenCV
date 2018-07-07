// GameST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	double dtime = (double)getTickCount();//获取开始时间

	System sys;
	cvNamedWindow("Face", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Face", backcreate);
	IplImage* backt = cvCloneImage(sys.backcreate);

	//生成玩家
	CRobot robot;
	CBaoBao player1;
	
	//初始显示
	robot.Draw2Back(backt);
	player1.Draw2Back(backt);
	cvShowImage("Face", backt);

	//不停接收按键
	while (1)
	{
		char key = cvWaitKey(500);
		//char key = ' ';
		if (key == '0')	break;
		else if (key == ' ')
		{
			sys.CreateBomb(player1.m_PosX, player1.m_PosY);
		}
		player1.Move(key,sys);
		robot.Move(sys);

		sys.ReMap();
		cvCopy(sys.backcreate, backt);
		player1.Draw2Back(backt);
		robot.Draw2Back(backt);
		cvShowImage("Face", backt);
	}

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);

	cvReleaseImage(&backt);
	delete &player1;
	delete &robot;
	delete &sys;
	cvDestroyAllWindows();

	return 0;
}
