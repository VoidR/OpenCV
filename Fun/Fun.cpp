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
	
	return 0;
}
 
