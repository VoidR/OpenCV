// Fun.cpp: 定义控制台应用程序的入口点。
//

#include  "stdafx.h"

//竖切
int main()
{
	Cut f;
	Resize s;
	//char str[] = "player10.png";
	//f.heng(str, 3, 0);
	//f.shu(str, 1, 0);
	/*
	for (int i = 0; i <= 5; i++)
	{
		str[7] = '0' + i;
		s.size(str,i);
		//waitKey();
	}
	*/
	IplImage* img = cvLoadImage("imageCN.png");
	char str[30];
	//String str;
	int x, y, width, height;
	ifstream in;
	in.open("in.txt");
	if (in.is_open())
	{
		for (int i = 0; i < 1477; i++)
		{
			in >> str;
			in >> x >> y >> width >> height;
			cout << i << "\t" << str << "\t" << x << "\t" << y << "\t" << width << "\t" << height << "\t" << endl;
			char ch;
			while (1)
			{
				in >> ch;
				if (ch == '>')
					break;
			}
			f.cut(str, x, y, width, height, img);
		}
	}

	/*for (int i = 0; i<640; i++)
		for (int j = 0; j < 360; j++)
		{
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3) = 7;
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3 + 1) = 7;
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3 + 2) = 7;
		}
	IplImage* top = cvLoadImage("Pic\\loading.png");
	CTools::Draw2Back(m_Back0, top, 515, (360 - top->width) / 2, 'R');
	Mat img = cvarrToMat(m_Back0);
	imwrite("Pic\\loading.png", img);*/


	//IplImage* img1 = cvLoadImage("Pic\\bg1.png");
	//IplImage* img2 = cvLoadImage("Pic\\image039.png");
	//IplImage* back = cvLoadImage("Pic\\block8.png");
	//IplImage* bu = cvCreateImage(CvSize(58, 58), IPL_DEPTH_8U, 3);

	//for (int i = 0; i<58; i++)
	//	for (int j = 0; j < 58; j++)
	//	{
	//		CV_IMAGE_ELEM(bu, uchar, i, j * 3) = 0;
	//		CV_IMAGE_ELEM(bu, uchar, i, j * 3 + 1) = 0;
	//		CV_IMAGE_ELEM(bu, uchar, i, j * 3 + 2) = 255;
	//	}
	//CTools::Draw2Back(bu, img1, (58 - img1->width) / 2, (58 - img1->width) / 2, 'B');
	//CTools::Draw2Back(bu, img2, (58 - img2->width) / 2, (58 - img2->width) / 2, 'B');
	//CTools::Draw2Back(bu, back, (58 - back->width) / 2, (58 - back->width) / 2, 'R');
	//Mat img = cvarrToMat(bu);
	//imwrite("Pic\\block3.png", img);
	return 0;
}
 
