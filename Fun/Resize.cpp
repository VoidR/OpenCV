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
	//����ͼ��
	Mat srcImage = imread(str);
	Mat temImage, dstImage1, dstImage2;
	temImage = srcImage;

	//��ʾԭͼ
	imshow("ԭͼ", srcImage);

	//�ߴ����
	resize(temImage, dstImage1, Size(temImage.cols *0.4, temImage.rows *0.4), 0, 0, INTER_LINEAR);
	//resize(temImage, dstImage2, Size(temImage.cols * 2, temImage.rows * 2), 0, 0, INTER_LINEAR);

	imshow("��С", dstImage1);
	//imshow("�Ŵ�", dstImage2);

	char outstr[] = "player10.png";
	outstr[7] = '0' + a;
	imwrite(outstr, dstImage1);


}
