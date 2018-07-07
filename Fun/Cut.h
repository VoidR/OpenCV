#pragma once
class Cut
{
public:
	Cut();
	~Cut();
	void shu(char* str,int n, int a);//文件名，原图起始下标，输出起始下标
	void heng(char* str,int n, int a);//文件名，原图起始下标，输出起始下标
	void cut(char * str, int y, int x, int width, int height,IplImage* img);
};

