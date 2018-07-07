#include "stdafx.h"
#include "CRobot.h"
#include"System.h"
CRobot::CRobot()
{
	//char filename[] = "Pic\\WuKong\\player0.png";
	char filename[] = "Pic\\Robot\\play0.png";

	for (int i = 0; i < 10; i++)
	{
		filename[14] = '0' + i;
		m_Image[i] = cvLoadImage(filename);
		cout << filename << endl;
	}
	//char filename1[] = "Pic\\WuKong\\player10.png";
	char filename1[] = "Pic\\Robot\\play10.png";
	for (int i = 0; i < 6; i++)
	{
		filename1[15] = '0' + i;
		m_Image[i + 10] = cvLoadImage(filename1);
		cout << filename1 << endl;
	}
	m_Speed = 40;
	m_PosX = 40 * 14;
	m_PosY = 40 * 17;
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

void CRobot::Move(System sys)
{

	int randt = rand() % 4;
	//randt = 3;
	switch (randt)
	{
	case 0:
		if (sys.m_Map[abs(m_PosX - m_Speed) / 40 + 1][m_PosY / 40 + 1] == -1)
			m_PosX -= m_Speed;
		if (m_LastCh != 'w')
		{
			m_LastCh = 'w';
			m_Dir = 12;
		}
		else
			m_Dir = 12 + (m_Dir + 1) % 4;
		break;
	case 1:
		if (sys.m_Map[m_PosX / 40 + 1][abs(m_PosY - m_Speed) / 40 + 1] == -1)
			m_PosY -= m_Speed;
		if (m_LastCh != 'a')
		{
			m_LastCh = 'a';
			m_Dir = 4;
		}
		else
			m_Dir = 4 + (m_Dir + 1) % 4;
		break;
	case 2:
		if (sys.m_Map[(m_PosX + m_Speed) / 40 + 1][m_PosY / 40 + 1] == -1)
			m_PosX += m_Speed;
		if (m_LastCh != 's')
		{
			m_LastCh = 's';
			m_Dir = 0;
		}
		else
			m_Dir = (m_Dir + 1) % 4;
		break;
	case 3:
		if (sys.m_Map[m_PosX / 40 + 1][(m_PosY + m_Speed) / 40 + 1] == -1)
			m_PosY += m_Speed;
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

	if (m_PosX > pback->height - pimg->height - 10)
		m_PosX = pback->height - pimg->height - 10;
	if (m_PosY > pback->width - pimg->width - 200)
		m_PosY = pback->width - pimg->width - 200;
	if (m_PosX < 0)	m_PosX = 0;
	if (m_PosY < 0)	m_PosY = 0;

	for (int x = 0; x<pimg->height; x++)
		for (int y = 0; y < pimg->width; y++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, x, y * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, x, y * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, x, y * 3 + 2);

			//if (top_b >= 250 && top_g >= 250 && top_r >= 250)
			if (Tools::DisRed(top_b, top_g, top_r))
				continue;

			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3 + 2) = top_r;
		}
}
