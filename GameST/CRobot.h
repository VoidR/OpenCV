#pragma once
#include "CPlayer.h"
class CRobot :
	public CPlayer
{
public:
	CRobot();
	~CRobot();
	void Move(System sys);
	void Draw2Back(IplImage* pback);
};

