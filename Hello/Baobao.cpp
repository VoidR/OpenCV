#include "Baobao.h"



Baobao::Baobao()
{
	char filename[] = "pic\\player0.jpg";
	for (int i = 0; i < 4; i++)
	{
		filename[10] = '0' + i;
		m_Img[i] = cvLoadImage(filename);
	}
	m_PosX = 10;
	m_PosY = 10;
	m_Speed = 20;
	m_Dir = 0;
}


Baobao::~Baobao()
{
	for (int i = 0; i < 4; i++)
	{
		cvReleaseImage(&m_Img[i]);
	}
}

void Baobao::Move(char key)
{
	switch (key)
	{
	case '8':
		m_PosY -= m_Speed;
		m_Dir = 0;
		break;
	case '4':
		m_PosX -= m_Speed;
		m_Dir = 2;
		break;
	case'2':
		m_PosY += m_Speed;
		m_Dir = 3;
		break;
	case'6':
		m_PosX += m_Speed;
		m_Dir = 1;
		break;
	default:
		break;
	}
}
