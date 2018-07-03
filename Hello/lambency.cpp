#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	double dtime = (double)getTickCount();//获取开始时间
	IplImage* pimg = cvLoadImage("chicky_512.png");
	cvNamedWindow("原图", 1);
	cvShowImage("原图", pimg);
	int width = pimg->width;
	int heigh = pimg->height;
	int centerX = width >> 1;
	int centerY = heigh >> 1;

	int maxT = centerX * centerX + centerY * centerY;
	int minT = (int)(maxT*(1 - 0.6));
	int diff = maxT - minT;//范围

	for (int j = 0; j < heigh; j++)
	{
		for (int i = 0; i < width; i++)
		{
			int b = CV_IMAGE_ELEM(pimg, uchar, i, j * 3);
			int g = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1);
			int r = CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2);

			int dx = centerX - i;
			int dy = centerY - j;

			float t = ((float)(dx * dx + dy * dy) / diff);//程度

			r = (int)(r + t * 255);
			g = (int)(g + t * 255) + 70 * (1 - t);
			b = (int)(b + t * 255);

			r = (r>255 ? 255 : (r<0 ? 0 : r));
			g = (g>255 ? 255 : (g<0 ? 0 : g));
			b = (b>255 ? 255 : (b<0 ? 0 : b));

			CV_IMAGE_ELEM(pimg, uchar, i, j * 3) = (uchar)b;
			CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 1) = (uchar)g;
			CV_IMAGE_ELEM(pimg, uchar, i, j * 3 + 2) = (uchar)r;

		}
	}
	cvNamedWindow("修改后", 1);
	cvShowImage("修改后", pimg);
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << dtime << endl;
	waitKey(0);
	cvReleaseImage(&pimg);
	cvDestroyAllWindows();

	return 0;
}