#pragma once
#include "System.h"
class CPlayer
{
protected:
	int m_Speed;//�ٶ�
	IplImage* m_Image[16];//4*4����ͼƬ
	int m_Dir;//ͼƬѡȡ
	char m_LastCh;//��һ������
public:
	CPlayer();
	virtual ~CPlayer();
	int m_PosX;//����X
	int m_PosY;//����Y
	virtual void Move(char key, System sys);
	virtual void Draw2Back(IplImage* pback) = 0;
	void Boom();
};

