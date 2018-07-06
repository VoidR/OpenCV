#pragma once
#include "CPlayer.h"
class CBaoBao :
	public CPlayer
{
public:
	CBaoBao();
	~CBaoBao();
	void Move(char key, System sys);
	void Draw2Back(IplImage* pback);
};

