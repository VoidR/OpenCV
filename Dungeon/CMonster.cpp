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

void CMonster::ReProperty(int grade)
{
	grade--;
	m_Health = grade * 8 + m_BasicHealth;;
	m_Damage = grade * 2 + m_BasicDamage;
	m_Armor = grade * 2 + m_BasicArmor;
}
