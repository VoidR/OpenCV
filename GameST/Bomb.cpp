#include "stdafx.h"
#include "Bomb.h"
#include"System.h"
Bomb::Bomb()
{
}

Bomb::Bomb(int x, int y)
{
	m_PosX = x;
	m_PosY = y;
	m_Dir = 0;
	m_Image[0] = cvLoadImage("Pic\\crump0.png");
	m_Image[1] = cvLoadImage("Pic\\crump1.png");
}


Bomb::~Bomb()
{
	for (int i = 0; i < 2; i++)
	{
		cvReleaseImage(&m_Image[i]);
	}
}

bool Bomb::Rebomb(IplImage* pback)
{
	Tools::Draw2Back(pback, m_Image[(m_Dir++) % 2], m_PosX, m_PosY,'R');
	if (m_Dir >= m_Time)
		return true;
	else return false;

}
