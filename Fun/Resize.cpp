#include "stdafx.h"
#include "Resize.h"


Resize::Resize()
{
}


Resize::~Resize()
{
}

void Resize::size(char * str,int a)
{
	//读入图像
	Mat srcImage = imread(str);
	Mat temImage, dstImage1, dstImage2;
	temImage = srcImage;

	//显示原图
	imshow("原图", srcImage);

	//尺寸调整
	resize(temImage, dstImage1, Size(temImage.cols *0.4, temImage.rows *0.4), 0, 0, INTER_LINEAR);
	//resize(temImage, dstImage2, Size(temImage.cols * 2, temImage.rows * 2), 0, 0, INTER_LINEAR);

	imshow("缩小", dstImage1);
	//imshow("放大", dstImage2);

	char outstr[] = "player10.png";
	outstr[7] = '0' + a;
	imwrite(outstr, dstImage1);


}
