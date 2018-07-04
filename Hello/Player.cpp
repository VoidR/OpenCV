#include "Player.h"
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


Player::Player()
{
	char filename[] = "pic\\player0.jpg";
	for (int i = 0; i < 4; i++)
	{
		filename[10] = '0' + i;
		Img[i] = cvLoadImage(filename);
	}
	PosX = 10;
	PosY = 10;
	Speed = 10;
	Dir = 0;
}


Player::~Player()
{
	for (int i = 0; i < 4; i++)
	{
		cvReleaseImage(&Img[i]);
	}
}

void Player::Move(int key)
{
	switch (key)
	{
	case 'w':
		PosY -= Speed;
		Dir = 0;
		break;
	case 'a':
		PosX -= Speed;
		Dir = 2;
		break;
	case's':
		PosY += Speed;
		Dir = 3;
		break;
	case'd':
		PosX += Speed;
		Dir = 1;
		break;
	default:
		break;
	}
}

void Player::Draw2Back(IplImage * pback)
{
	IplImage* pimg = Img[Dir];
	for (int i = 0; i < pimg->height; i++)
	{
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if (top_b >= 220 && top_r >= 220 && top_r >= 220)
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + PosY, (j + PosX) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + PosY, (j + PosX) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + PosY, (j + PosX) * 3 + 2) = top_r;
		}
	}
}
