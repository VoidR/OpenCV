#include "opencv2/opencv.hpp"
using namespace cv;
int main()
{
	const char *fn = "D:\\opencv\\sources\\samples\\data\\apple.jpg";
	Mat image = imread(fn);
	imshow("Hello World", image);
	waitKey(0);
}