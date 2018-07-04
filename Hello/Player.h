#pragma once
#include<opencv2\opencv.hpp>
using namespace cv;
class Player
{
protected:
	int Speed;//速度
	int PosX;//x坐标
	int PosY;//y坐标
	IplImage* Img[4];//四个方向图片
	int Dir;

public:
	Player();
	~Player();
	void Move(int key);
	void Draw2Back(IplImage* pback);
};

