#pragma once
class Cut
{
public:
	Cut();
	~Cut();
	void shu(char* str,int n, int a);//�ļ�����ԭͼ��ʼ�±꣬�����ʼ�±�
	void heng(char* str,int n, int a);//�ļ�����ԭͼ��ʼ�±꣬�����ʼ�±�
	void cut(char * str, int y, int x, int width, int height,IplImage* img);
};

