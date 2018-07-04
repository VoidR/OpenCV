#include "Doraemon.h"
#include<iostream>
using namespace std;


Doraemon::Doraemon()
{
	char filename[] = "pic\\out0.png";
	for (int i = 0; i < 10; i++)
	{
		filename[7] = '0' + i; 
		m_Img[i] = cvLoadImage(filename);
		//cout << filename << endl;
	}
	char filename1[] = "pic\\out10.png";
	for (int i = 0; i < 6; i++)
	{
		filename1[8] = '0' + i;
		m_Img[i+10] = cvLoadImage(filename1);
		//cout << filename1 << endl;
	}
	m_Speed = 30;
	m_PosX = 10;
	m_PosY = 100;
	m_Dir = 0;
	lastch = 's';
}


Doraemon::~Doraemon()
{
	for (int i = 0; i < 16; i++)
	{
		cvReleaseImage(&m_Img[i]);
	}
}

void Doraemon::Move(char key)
{
	switch (key)
	{
	case 'w':
		m_PosY -= m_Speed;
		if (lastch != 'w')
		{
			lastch = 'w';
			m_Dir = 12;
		}
		else
			m_Dir = 12 + (m_Dir + 1) % 4;
		break;
	case 'a':
		m_PosX -= m_Speed;
		if (lastch != 'a')
		{
			lastch = 'a';
			m_Dir = 4;
		}
		else
			m_Dir = 4 + (m_Dir + 1) % 4;
		break;
	case's':
		m_PosY += m_Speed;
		if (lastch != 's')
		{
			lastch = 's';
			m_Dir = 0;
		}
		else
			m_Dir =(m_Dir + 1) % 4;
		break;
	case'd':
		m_PosX += m_Speed;
		if (lastch != 'd')
		{
			lastch = 'd';
			m_Dir = 8;
		}
		else
			m_Dir = 8 + (m_Dir + 1) % 4;
		break;
	default:
		break;
	}
}
