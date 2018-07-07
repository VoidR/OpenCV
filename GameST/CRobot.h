#pragma once
#include "CPlayer.h"
class CRobot :
	public CPlayer
{
public:
	CRobot();
	~CRobot();
	void Move(char key);
	void Draw2Back(IplImage* pback);
};

