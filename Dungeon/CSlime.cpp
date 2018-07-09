#include "stdafx.h"
#include "CSlime.h"


CSlime::CSlime()
{
	m_Pos.x = 2;
	m_Pos.y = 2;
	m_Body = cvLoadImage("Pic\\mob008.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block4.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}

CSlime::CSlime(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob008.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block4.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}


CSlime::~CSlime()
{
}
