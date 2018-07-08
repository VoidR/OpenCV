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