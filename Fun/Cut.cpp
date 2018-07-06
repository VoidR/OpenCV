#include "stdafx.h"
#include "Cut.h"


Cut::Cut()
{
}


Cut::~Cut()
{
}

void Cut::shu(char* str, int n,int a)
{
	char outstr[] = "in0.png";
	for (int k = 0; k < n; k++)
	{
		str[2] = '0' + k;
		IplImage* img = cvLoadImage(str);
		int irow = img->height;
		int icol = img->width;

		IplImage* res1 = cvCreateImage(CvSize(icol / 2, irow), IPL_DEPTH_8U, 3);
		IplImage* res2 = cvCreateImage(CvSize(icol / 2, irow), IPL_DEPTH_8U, 3);
		IplImage* t = img;
		for (int i = 0; i < irow; i++)
		{
			for (int j = 0; j < icol / 2; j++)
			{
				CV_IMAGE_ELEM(res1, uchar, i, j * 3) = CV_IMAGE_ELEM(t, uchar, i, j * 3);
				CV_IMAGE_ELEM(res1, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 1);
				CV_IMAGE_ELEM(res1, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 2);
			}
		}
		for (int i = 0; i < irow; i++)
		{
			for (int j = icol / 2; j < icol; j++)
			{
				CV_IMAGE_ELEM(res2, uchar, i, (j - icol / 2) * 3) = CV_IMAGE_ELEM(t, uchar, i, j * 3);
				CV_IMAGE_ELEM(res2, uchar, i, (j - icol / 2) * 3 + 1) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 1);
				CV_IMAGE_ELEM(res2, uchar, i, (j - icol / 2) * 3 + 2) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 2);
			}
		}
		//cvSaveImage("res1.jpg", res1);
		//cvSaveImage("res2.jpg", res2);
		Mat image1 = cv::cvarrToMat(res1);
		outstr[2] = '0' + (a++);
		imwrite(outstr, image1);
		Mat image2 = cv::cvarrToMat(res2);
		outstr[2] = '0' + a++;
		imwrite(outstr, image2);
		waitKey(0);
	}
}

void Cut::heng(char * str, int n, int a)
{
	char outstr[] = "player10.png";
	for (int k = 0; k < n; k++)
	{
		str[1] = '5' + k;
		IplImage* img = cvLoadImage(str);
		int irow = img->height;
		int icol = img->width;

		IplImage* res1 = cvCreateImage(CvSize(icol, irow / 2), IPL_DEPTH_8U, 3);
		IplImage* res2 = cvCreateImage(CvSize(icol, irow / 2), IPL_DEPTH_8U, 3);
		IplImage* t = img;
		for (int i = 0; i < irow / 2; i++)
		{
			for (int j = 0; j < icol; j++)
			{
				CV_IMAGE_ELEM(res1, uchar, i, j * 3) = CV_IMAGE_ELEM(t, uchar, i, j * 3);
				CV_IMAGE_ELEM(res1, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 1);
				CV_IMAGE_ELEM(res1, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(t, uchar, i, j * 3 + 2);
			}
		}
		for (int i = 0; i < irow / 2; i++)
		{
			for (int j = 0; j < icol; j++)
			{
				CV_IMAGE_ELEM(res2, uchar, i, j * 3) = CV_IMAGE_ELEM(t, uchar, i + irow / 2, j * 3);
				CV_IMAGE_ELEM(res2, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(t, uchar, i + irow / 2, j * 3 + 1);
				CV_IMAGE_ELEM(res2, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(t, uchar, i + irow / 2, j * 3 + 2);
			}
		}
		//cvSaveImage("res1.jpg", res1);
		//cvSaveImage("res2.jpg", res2);
		Mat image1 = cv::cvarrToMat(res1);
		outstr[7] = '0' + a++;
		imwrite(outstr, image1);
		Mat image2 = cv::cvarrToMat(res2);
		outstr[7] = '0' + a++;
		imwrite(outstr, image2);
		waitKey(0);
	}
}

