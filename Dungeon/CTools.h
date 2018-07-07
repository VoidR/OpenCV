#pragma once
class CTools
{
public:
	CTools();
	~CTools();
	static void Draw2Back(IplImage* pback, char* str, int x, int y, char aim);
	static void Draw2Back(IplImage* pback, IplImage* pimg, int x, int y, char aim);
	static void Draw2BackTrans(IplImage* pback, IplImage* pimg, int x, int y);
	static bool DisRed(int b, int g, int r);
	static bool DisWhite(int b, int g, int r);
	static bool DisBlack(int b, int g, int r);
};

