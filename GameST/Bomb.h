#pragma once
class Bomb
{
protected:
	int m_PosX;//坐标X
	int m_PosY;//坐标Y
	IplImage* m_Image[2];//2张图片
	int m_Dir;//图片选取
	const int m_Time = 20;//爆炸时间
public:
	Bomb();
	Bomb(int x, int y);
	~Bomb();
	bool Rebomb(IplImage* pback);
};

