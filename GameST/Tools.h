#pragma once
class Tools
{
public:
	Tools();
	~Tools();
	static void Draw2Back(IplImage* pback, char* str, int x, int y, char aim);
	static void Draw2Back(IplImage* pback, IplImage* pimg, int x, int y, char aim);
	static bool DisRed(int b, int g, int r);
	static bool DisWhite(int b, int g, int r);

};

