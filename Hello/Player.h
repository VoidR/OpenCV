#pragma once
#include<opencv2\opencv.hpp>
using namespace cv;
class Player
{
protected:
	int Speed;//�ٶ�
	int PosX;//x����
	int PosY;//y����
	IplImage* Img[4];//�ĸ�����ͼƬ
	int Dir;

public:
	Player();
	~Player();
	void Move(int key);
	void Draw2Back(IplImage* pback);
};

