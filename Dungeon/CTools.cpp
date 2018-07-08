#include "stdafx.h"
#include "CTools.h"


CTools::CTools()
{
}


CTools::~CTools()
{
}

void CTools::Draw2Back(IplImage * pback, char * str, int x, int y, char aim)
{
	int Y = y, X = x;
	IplImage* pimg = cvLoadImage(str);
	for (int i = 0; i < pimg->height; i++)
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if ((aim == 'R'&&DisRed(top_b, top_g, top_r)) || (aim == 'W'&&DisWhite(top_b, top_g, top_r)))
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 2) = top_r;
		}
	cvReleaseImage(&pimg);
}

void CTools::Draw2Back(IplImage * pback, IplImage * pimg, int x, int y, char aim)
{
	int Y = y, X = x;
	//cvShowImage("1", pimg);
	for (int i = 0; i < pimg->height; i++)
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if ((aim == 'R'&&DisRed(top_b, top_g, top_r)) || (aim == 'W'&&DisWhite(top_b, top_g, top_r))|| aim == 'B'&&DisBlack(top_b, top_g, top_r))
				continue;

			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3) = top_b;
			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 1) = top_g;
			CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 2) = top_r;
		}
}

void CTools::Draw2BackTrans(IplImage * pback, IplImage * pimg, int x, int y)
{
	int Y = y, X = x;
	for (int i = 0; i < pimg->height; i++)
		for (int j = 0; j < pimg->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			if (i + X <= 150 || j + Y <= 14 || j + Y >= 355 - 7 || i + X >= 474)
			{
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3) = (uchar)top_b * 0.4 + (uchar)(CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3) * 0.6);
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 1) = (uchar)top_g * 0.4 + (uchar)(CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 1) * 0.6);
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 2) = (uchar)top_r * 0.4 + (uchar)(CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 2) * 0.6);
			}
			else
			{
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3) = top_b;
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 1) = top_g;
				CV_IMAGE_ELEM(pback, uchar, i + X, (j + Y) * 3 + 2) = top_r;
			}
			
		}
}

bool CTools::DisRed(int b, int g, int r)
{
	if (b <= 5 && g <= 5 && r >= 250)
		return true;
	else
		return false;
}

bool CTools::DisWhite(int b, int g, int r)
{
	if (b >= 255 && g >= 255 && r >= 255)
		return true;
	else
		return false;
}

bool CTools::DisBlack(int b, int g, int r)
{
	if (b <= 2 && g <= 2 && r <= 2)
		return true;
	else
		return false;
}
