#include "stdafx.h"
#include "CBaoBao.h"


CBaoBao::CBaoBao()
{
	char filename[] = "Pic\\BaoBao\\player0.jpg";
	for (int i = 0; i < 4; i++)
	{
		filename[17] = '0' + i;
		m_Image[i] = cvLoadImage(filename);
		//cout << filename << endl;
	}
	m_PosX = 0;
	m_PosY = 0;
	m_Speed = 40;
	m_Dir = 3;
}


CBaoBao::~CBaoBao()
{
	for (int i = 0; i < 4; i++)
	{
		cvReleaseImage(&m_Image[i]);
	}
}

void CBaoBao::Move(char key, System sys)
{
	//cout << m_PosX + 1 << m_PosY + 1 << endl;
	switch (key)
	{
	case 'w':
		if (sys.m_Map[abs(m_PosX - m_Speed) / 40 + 1][m_PosY / 40 + 1] == -1)
			m_PosX -= m_Speed;
		m_Dir = 0;
		break;
	case 'a':
		if (sys.m_Map[m_PosX / 40 + 1][abs(m_PosY - m_Speed) / 40 + 1] == -1)
			m_PosY -= m_Speed;
		m_Dir = 2;
		break;
	case's':
		if (sys.m_Map[(m_PosX + m_Speed) / 40 + 1][m_PosY / 40 + 1] == -1)
			m_PosX += m_Speed;
		m_Dir = 3;
		break;
	case'd':
		if (sys.m_Map[m_PosX / 40 + 1][(m_PosY + m_Speed) / 40 + 1] == -1)
			m_PosY += m_Speed;
		m_Dir = 1;
		break;
	default:
		break;
	}
}

void CBaoBao::Draw2Back(IplImage * pback)
{
	IplImage* pimg = m_Image[m_Dir];
	//µØÍ¼±ß½çÅÐ¶Ï
	if (m_PosX > pback->height - pimg->height - 10)
		m_PosX = pback->height - pimg->height - 10;
	if (m_PosY > pback->width - pimg->width - 200)
		m_PosY = pback->width - pimg->width - 200;
	if (m_PosX < 0)	m_PosX = 0;
	if (m_PosY < 0)	m_PosY = 0;

	for(int x=0;x<pimg->height;x++)
		for (int y = 0; y < pimg->width; y++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, x, y * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, x, y * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, x, y * 3 + 2);

			if (top_b >= 230 && top_g >= 230 && top_r >= 230)
				continue;

			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, x + m_PosX, (y + m_PosY) * 3 + 2) = top_r;
		}
}
