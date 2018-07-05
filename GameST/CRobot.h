#pragma once
#include "CPlayer.h"
class CRobot :
	public CPlayer
{
public:
	CRobot();
	~CRobot();
	void Move();
	void Draw2Back(IplImage* pback);
};

