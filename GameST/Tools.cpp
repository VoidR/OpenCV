#include "stdafx.h"
#include "Tools.h"


Tools::Tools()
{
}


Tools::~Tools()
{
}

void Tools::Draw2Back(IplImage * pback, char * str, int x, int y, char aim)
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

void Tools::Draw2Back(IplImage * pback, IplImage * pimg, int x, int y, char aim)
{
	//int Y = (y - 1) * 40, X = (x - 1) * 40;
	int Y = y, X = x;
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
}

bool Tools::DisRed(int b, int g, int r)
{
	if (b <= 10 && g <= 10 && r >= 240)
		return true;
	else
		return false;
}

bool Tools::DisWhite(int b, int g, int r)
{
	if (b >= 245 && g >= 245 && r >= 245)
		return true;
	else
		return false;
}

