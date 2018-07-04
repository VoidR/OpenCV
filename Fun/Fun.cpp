// Fun.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	IplImage* img = cvLoadImage("output14.bmp");
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
	for (int i = 0; i < irow ; i++)
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
	imwrite("out14.bmp", image1);
	Mat image2 = cv::cvarrToMat(res2);
	imwrite("out15.bmp", image2);
	waitKey(0);
    return 0;
}
 
