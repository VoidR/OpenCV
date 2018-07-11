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

	IplImage* m_BlockKey[2];//带钥匙的边框
	IplImage* m_Text;//图鉴图片
	int m_Key;//是否有钥匙
	int m_IsAttack;//是否已经攻击
};

