#pragma once
class Bomb
{
protected:
	int m_PosX;//����X
	int m_PosY;//����Y
	IplImage* m_Image[2];//2��ͼƬ
	int m_Dir;//ͼƬѡȡ
	const int m_Time = 20;//��ըʱ��
public:
	Bomb();
	Bomb(int x, int y);
	~Bomb();
	bool Rebomb(IplImage* pback);
};

