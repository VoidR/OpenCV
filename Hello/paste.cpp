#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void paste2(IplImage* img, IplImage* back, int x, int y)
{

	for (int i = 0; i < img->height; i++)
	{
		for (int j = 0; j < img->width; j++)
		{
			uchar top_b = CV_IMAGE_ELEM(img, uchar, i, j * 3);
			uchar top_g = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 1);
			uchar top_r = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 2);

			uchar back_b = CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3);
			uchar back_g = CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3 + 1);
			uchar back_r = CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3 + 2);

			if (top_b >= 230 && top_r >= 230)
				continue;

			CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3) = (int)(back_b * 0.4 + top_b * 0.6);
			CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3 + 1) = (int)(back_g * 0.4 + top_g * 0.6);
			CV_IMAGE_ELEM(back, uchar, i + x, (j + y) * 3 + 2) = (int)(back_r * 0.4 + top_r * 0.6);
		}
	}
	cvNamedWindow("修改后", CV_WINDOW_AUTOSIZE);
	cvShowImage("修改后", back);
	waitKey(100);
}

int dmain()
{
	double dtime = (double)getTickCount();//获取开始时间
	IplImage* back = cvLoadImage("test2.jpg");
	IplImage* top = cvLoadImage("test1.png");
	int heigh_back = back->height;
	int width_back = back->width;
	int heigh_top = top->height;
	int width_top = top->width;

	//cvCreateImage(iamgesize，深度，通道数)
	IplImage*temp = cvCreateImage(cvSize(width_back, heigh_back), IPL_DEPTH_8U, 3);

	int a = 0, b = 0;
	//cvShowImage("1", back);

	while (a < heigh_back - heigh_top && b < width_back - width_top)
	{
		//cvCopy 复制函数 （源图片，目标图片，模板--NULL表示没有模板） 使用前目标图片需要用cvCreateImage()开一段内存
		cvCopy(back, temp, NULL);
		paste2(top, temp, a, b);
		a += 20;
		b += 20;
	}
	
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//获取结束时间，getTickFrequency()返回每秒的计时周期数
	cout << "耗时：" << dtime << "s" << endl;
	waitKey(0);
	cvReleaseImage(&temp);
	cvReleaseImage(&back);
	cvReleaseImage(&top);
	cvDestroyAllWindows();

	return 0;
}