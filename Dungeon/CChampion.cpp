#include  "stdafx.h"
#include  "CChampion.h"


CChampion::CChampion()
{
	
}


CChampion::~CChampion()
{
	
}


int CChampion::GetFaceRow()
{
	return 140 + (m_Pos.x - 1) * 58 + 2;
}


int CChampion::GetFaceCol()
{
	return (m_Pos.y - 1) * 58 + (58 - m_Face->width) / 2 + 5;
}


int CChampion::GetBodyRow()
{
	return 140 + (m_Pos.x - 1) * 58 + m_Face->height + 1;
}


int CChampion::GetBodyCol()
{
	return (m_Pos.y - 1) * 58 + (58 - m_Body->width) / 2 + (m_Face->width - m_Body->width) / 2 + 5 - 1;
}


int CChampion::GetBlockRow()
{
	return  140 + (m_Pos.x - 1) * 58 + 2;
}


int CChampion::GetBlockCol()
{
	return (m_Pos.y - 1) * 58 + 2 + 7;
}

void CChampion::ReProperty(int grade[4])
{
	m_Health = m_HealthMax = grade[0] * 8 + m_BasicHealth;
	m_Mana = grade[1] * 6 + m_BasicMana;
	m_Damage = grade[2] * 2 + m_BasicDamage;
	m_Armor = grade[3] * 2 + m_BasicArmor;
}

void CChampion::Recover()
{
	m_Health += m_HealthMax * 0.4;
	if (m_Health > m_HealthMax)
		m_Health = m_HealthMax;
}

void CChampion::ReMAX()
{
	m_Health = m_HealthMax;
}


int CChampion::GetWeaponRow()
{
	return 140 + m_Pos.x * 58 - m_Weapon->height - 7;
}


int CChampion::GetWeaponCol()
{
	return  m_Pos.y * 58 - m_Weapon->width - 2;
}


int CChampion::GetMinorRow()
{
	return 140 + m_Pos.x * 58 - m_Minor->height - 7 - 2;
}


int CChampion::GetMinorCol()
{
	return  (m_Pos.y - 1) * 58 + 7 + 7;
}