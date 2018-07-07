#include  "stdafx.h"
#include  "CKnight.h"


CKnight::CKnight()
{
	m_iRow = 2;
	m_iCol = 2;
	m_Face = cvLoadImage("Pic\\face000.png");
	m_Body = cvLoadImage("Pic\\body000.png");
	m_Weapon = cvLoadImage("Pic\\wepon000.png");
	m_Minor = cvLoadImage("Pic\\minor100.png");
	m_Frame = cvLoadImage("Pic\\block1.png");
	m_Health = 42;
	m_Damage = 8;
	m_Armor = 3;
	m_Mana = 20;

}


CKnight::~CKnight()
{
}
