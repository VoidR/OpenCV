// GameST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	double dtime = (double)getTickCount();//获取开始时间

	System sys;
	
	//初始显示
	sys.Show();

	//不停接收按键
	sys.Run();
	

	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;

	waitKey(0);

	delete &sys;
	cvDestroyAllWindows();

	return 0;
}
