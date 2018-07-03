#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int _tmain()
{
	Mat img = imread("templ.png");
	//Mat img = imread("templ.png",IMREAD_GRAYSCALE);// »Ò¶ÈÍ¼Ïñ
	imshow("Hello World", img);
	//cout << "image£¨c£© = " << endl << img << endl << endl;
	waitKey(0);
	return 0;
}