#include "Player.h"
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;



Player::Player()
{
}


Player::~Player()
{
}

void Player::Move(char key)
{
}

void Player::Draw2Back(IplImage * pback)
{
	IplImage* pimg = m_Img[m_Dir];
	if (m_PosY > pback->height - pimg->height - 10)
		m_PosY = pback->height - pimg->height - 10;
	if (m_PosX > pback->width - pimg->width - 200)
		m_PosX = pback->width - pimg->width - 200;
	if (m_PosX < 0)	m_PosX = 0;
	if (m_PosY < 0)	m_PosY = 0;

	for (int i = 0; i < pimg->height; i++)
	{
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if (top_b >= 230 && top_r >= 230 && top_r >= 230)
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 2) = top_r;
		}
	} 
}
/*
void Player::loadimg()
{
	char filename[] = "pic\\player0.jpg";
	for (int i = 0; i < 4; i++)
	{
		filename[10] = '0' + i;
		m_Img[i] = cvLoadImage(filename);
		cout << filename << endl;
	}
}*/
