#pragma once
#include "CRole.h"
class CMonster :
	public CRole
{
public:
	CMonster();
	~CMonster();
	int GetBodyRow();//��������������������
	int GetBodyCol();//�������������������
	int GetBlockRow();//����߿�������������
	int GetBlockCol();//����߿������������
};

