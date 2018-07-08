#include "stdafx.h"
#include "CMonster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

int CMonster::GetBodyRow()
{
	return 140 + (m_Pos.x - 1) * 58 + (58 - m_Body->height) / 2;
}

int CMonster::GetBodyCol()
{
	return (m_Pos.y - 1) * 58 + (58 - m_Body->width) / 2 + 7;
}

int CMonster::GetBlockRow()
{
	return  140 + (m_Pos.x - 1) * 58 + 2;
}

int CMonster::GetBlockCol()
{
	return (m_Pos.y - 1) * 58 + 2 + 7;
}
