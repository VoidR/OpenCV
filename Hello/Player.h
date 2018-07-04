#pragma once
#include<opencv2\opencv.hpp>
using namespace cv;
class Player
{
protected:
	int m_Speed;//速度
	int m_PosX;//x坐标
	int m_PosY;//y坐标
	IplImage* m_Img[16];//四*4个方向图片
	int m_Dir;
	char lastch;
public:
	Player();
	virtual~Player();
	virtual void Move(char key) = 0;
	void Draw2Back(IplImage* pback);
	//static void loadimg();
};

