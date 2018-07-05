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
	m_PosX = 10;
	m_PosY = 10;
	m_Speed = 20;
	m_Dir = 3;
}


CBaoBao::~CBaoBao()
{
	for (int i = 0; i < 4; i++)
	{
		cvReleaseImage(&m_Image[i]);
	}
}

void CBaoBao::Move(char key)
{
	switch (key)
	{
	case 'w':
		m_PosY -= m_Speed;
		m_Dir = 0;
		break;
	case 'a':
		m_PosX -= m_Speed;
		m_Dir = 2;
		break;
	case's':
		m_PosY += m_Speed;
		m_Dir = 3;
		break;
	case'd':
		m_PosX += m_Speed;
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

			if (top_b >= 230 && top_r >= 230 && top_r >= 230)
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + m_PosY, (j + m_PosX) * 3 + 2) = top_r;
		}
}
