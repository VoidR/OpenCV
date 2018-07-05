#include "stdafx.h"
#include "CRobot.h"


CRobot::CRobot()
{
	char filename[] = "Pic\\Robot\\play0.png";
	for (int i = 0; i < 10; i++)
	{
		filename[14] = '0' + i;
		m_Image[i] = cvLoadImage(filename);
		//cout << filename << endl;
	}
	char filename1[] = "Pic\\Robot\\play10.png";
	for (int i = 0; i < 6; i++)
	{
		filename1[15] = '0' + i;
		m_Image[i + 10] = cvLoadImage(filename1);
		//cout << filename1 << endl;
	}
	m_Speed = 2;
	m_PosX = 17 * 40;
	m_PosY = 40 * 14;
	m_Dir = 0;
	m_LastCh = 's';
}


CRobot::~CRobot()
{
	for (int i = 0; i < 16; i++)
	{
		cvReleaseImage(&m_Image[i]);
	}
}

void CRobot::Move()
{
	int randt = rand() % 4;
	switch (randt)
	{
	case 0:
		m_PosY -= m_Speed;
		if (m_LastCh != 'w')
		{
			m_LastCh = 'w';
			m_Dir = 12;
		}
		else
			m_Dir = 12 + (m_Dir + 1) % 4;
		break;
	case 1:
		m_PosX -= m_Speed;
		if (m_LastCh != 'a')
		{
			m_LastCh = 'a';
			m_Dir = 4;
		}
		else
			m_Dir = 4 + (m_Dir + 1) % 4;
		break;
	case 2:
		m_PosY += m_Speed;
		if (m_LastCh != 's')
		{
			m_LastCh = 's';
			m_Dir = 0;
		}
		else
			m_Dir = (m_Dir + 1) % 4;
		break;
	case 3:
		m_PosX += m_Speed;
		if (m_LastCh != 'd')
		{
			m_LastCh = 'd';
			m_Dir = 8;
		}
		else
			m_Dir = 8 + (m_Dir + 1) % 4;
		break;
	default:
		break;
	}
}

void CRobot::Draw2Back(IplImage * pback)
{
	IplImage* pimg = m_Image[m_Dir];
	//µØÍ¼±ß½çÅÐ¶Ï
	if (m_PosY > pback->height - pimg->height - 10)
		m_PosY = pback->height - pimg->height - 10;
	if (m_PosX > pback->width - pimg->width - 200)
		m_PosX = pback->width - pimg->width - 200;
	if (m_PosX < 0)	m_PosX = 0;
	if (m_PosY < 0)	m_PosY = 0;

	for (int i = 0; i < pimg->height; i++)
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if (top_b == 0 && top_g == 0 && top_r >= 250)
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 2) = top_r;
		}
}
