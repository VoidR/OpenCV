#pragma once
class CPlayer
{
protected:
	int m_PosX;//����X
	int m_PosY;//����Y
	int m_Speed;//�ٶ�
	IplImage* m_Image[16];//4*4����ͼƬ
	int m_Dir;//ͼƬѡȡ
	char m_LastCh;//��һ������
public:
	CPlayer();
	virtual ~CPlayer();
	virtual void Move(char key);
	virtual void Draw2Back(IplImage* pback) = 0;
};

