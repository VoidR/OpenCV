#pragma once
#include "CPlayer.h"
class CBaoBao :
	public CPlayer
{
public:
	CBaoBao();
	~CBaoBao();
	void Move(char key);
	void Draw2Back(IplImage* pback);
};

