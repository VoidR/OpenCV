#pragma once
#include "System.h"
class CPlayer
{
protected:
	int m_Speed;//速度
	IplImage* m_Image[16];//4*4方向图片
	int m_Dir;//图片选取
	char m_LastCh;//上一个方向
public:
	CPlayer();
	virtual ~CPlayer();
	int m_PosX;//坐标X
	int m_PosY;//坐标Y
	virtual void Move(char key, System sys);
	virtual void Draw2Back(IplImage* pback) = 0;
	void Boom();
};

