#include <opencv2\opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

int amain()
{
	double dtime = (double)getTickCount();//��ȡ��ʼʱ��
	Mat mat_p = (Mat_<int>(3, 3) << 200, 0, 1, 0, 1, 0, 1, 0, 1);
	IplImage *p = NULL;
	char winname[5][5] = { "0","1","2","3" };
	char filename[5][20] = { "0","templ.png", "orange.jpg","apple.jpg" };
	for (int i = 1; i <= 3; i++)
	{
		p = cvLoadImage(filename[i], 1);
		cvNamedWindow(winname[i], CV_WINDOW_AUTOSIZE);//CV_WINDOW_AUTOSIZE��������Ӧ���ڴ��ڴ�С
		if (p != 0)
			cvShowImage(winname[i], p);
		moveWindow(winname[i], (i - 1) * 550, 0);
	}
	/*p = cvLoadImage("templ.png");
	cvNamedWindow("p1",CV_WINDOW_AUTOSIZE);//CV_WINDOW_AUTOSIZE��������Ӧ���ڴ��ڴ�С
	if (p != 0)
		cvShowImage("p1", p);
	moveWindow("p1", 0, 0);

	p = cvLoadImage("orange.jpg");
	cvNamedWindow("p2", CV_WINDOW_AUTOSIZE);
	if (p != 0)
		cvShowImage("p2", p);
	moveWindow("p2", 150, 0);

	p = cvLoadImage("apple.jpg");
	cvNamedWindow("p3", CV_WINDOW_AUTOSIZE);
	if (p != 0)
		cvShowImage("p3", p);
	moveWindow("p3", 700, 0);*/
	cvReleaseImage(&p);
	dtime = ((double)getTickCount() - dtime) / getTickFrequency();//��ȡ����ʱ�䣬getTickFrequency()����ÿ��ļ�ʱ������
	cout << dtime << endl;
	waitKey(0);

	//Mat img = imread("templ.png");
	/*imshow("p1", img);
	moveWindow("p1", 0, 0);
	img = imread("orange.jpg");
	imshow("p2", img);
	moveWindow("p2", 150, 0);
	img = imread("apple.jpg");
	imshow("p3", img);
	moveWindow("p3", 700, 0);*/
	return 0;
}
