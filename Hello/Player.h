#pragma once
#include<opencv2\opencv.hpp>
using namespace cv;
class Player
{
protected:
	int m_Speed;//�ٶ�
	int m_PosX;//x����
	int m_PosY;//y����
	IplImage* m_Img[16];//��*4������ͼƬ
	int m_Dir;
	char lastch;
public:
	Player();
	virtual~Player();
	virtual void Move(char key) = 0;
	void Draw2Back(IplImage* pback);
	//static void loadimg();
};

