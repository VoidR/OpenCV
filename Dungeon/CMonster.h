#pragma once
#include "CRole.h"
class CMonster :
	public CRole
{
public:
	CMonster();
	~CMonster();
	int GetBodyRow();//计算身体纵向像素坐标
	int GetBodyCol();//计算身体横向像素坐标
	int GetBlockRow();//计算边框纵向像素坐标
	int GetBlockCol();//计算边框横向像素坐标
};

