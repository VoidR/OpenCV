#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	double dtime = (double)getTickCount();//��ȡ��ʼʱ��
	IplImage* pimg = cvLoadImage("test2.jpg");
	//cvNamedWindow("ԭͼ", 1);
	cvShowImage("ԭͼ", pimg);
	//width->��� height->�߶� RGBͨ����width��
	//Mat: rows->����  cols->���� RGBͨ����col��
	int width = pimg->width;
	int heigh = pimg->height;
	int centerX = width >> 1;
	int centerY = heigh >> 1;

	float radio = (width > heigh) ? (float)heigh / (float)width : (float)width / (float)heigh;

	int maxT = centerX * centerX + centerY * centerY;
	int minT = (int)(maxT*(1 - 0.3));
	int diff = maxT - minT;//��Χ

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < heigh; j++)
		{
			int b = CV_IMAGE_ELEM(pimg, uchar, j, i * 3);
			int g = CV_IMAGE_ELEM(pimg, uchar, j, i * 3 + 1);
			int r = CV_IMAGE_ELEM(pimg, uchar, j, i * 3 + 2);

			float dx = centerX - i;
			float dy = centerY - j;

			if (width > heigh)
				dx *= radio;
			else dy *= radio;

			float t = ((float)(dx * dx + dy * dy) / diff);//�̶�

			r = (int)(r + t * 255);
			g = (int)(g + t * 255) + 120 * (1 - t);
			b = (int)(b + t * 255);

			r = (r>255 ? 255 : (r<0 ? 0 : r));
			g = (g>255 ? 255 : (g<0 ? 0 : g));
			b = (b>255 ? 255 : (b<0 ? 0 : b));

			CV_IMAGE_ELEM(pimg, uchar, j, i * 3) = (uchar)b;
			CV_IMAGE_ELEM(pimg, uchar, j, i * 3 + 1) = (uchar)g;
			CV_IMAGE_ELEM(pimg, uchar, j, i * 3 + 2) = (uchar)r;

		}
	}
	cvNamedWindow("�޸ĺ�", 1);
	cvShowImage("�޸ĺ�", pimg);
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//��ȡ����ʱ�䣬getTickFrequency()����ÿ��ļ�ʱ������
	cout << dtime << endl;
	waitKey(0);
	cvReleaseImage(&pimg);
	cvDestroyAllWindows();

	return 0;
}