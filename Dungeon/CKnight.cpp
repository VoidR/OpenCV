#include  "stdafx.h"
#include  "CKnight.h"


CKnight::CKnight()
{
	m_Pos.x = 1;
	m_Pos.y = 1;
	m_Face = cvLoadImage("Pic\\face000.png");
	m_Body = cvLoadImage("Pic\\body000.png");
	m_Weapon = cvLoadImage("Pic\\wepon000.png");
	m_Minor = cvLoadImage("Pic\\minor100.png");
	m_Block = cvLoadImage("Pic\\block1.png");
	m_Health = 42;
	m_Damage = 8;
	m_Armor = 3;
	m_Mana = 20;
}

CKnight::CKnight(CvPoint pos)
{
	m_Pos = pos;
	m_Face = cvLoadImage("Pic\\face000.png");
	m_Body = cvLoadImage("Pic\\body000.png");
	m_Weapon = cvLoadImage("Pic\\wepon000.png");
	m_Minor = cvLoadImage("Pic\\minor100.png");
	m_Block = cvLoadImage("Pic\\block1.png");
	m_Health = 42;
	m_Damage = 8;
	m_Armor = 3;
	m_Mana = 20;
}

CKnight::~CKnight()
{
}
