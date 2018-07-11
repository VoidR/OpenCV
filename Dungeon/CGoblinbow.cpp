#include "stdafx.h"
#include "CGoblinbow.h"


CGoblinbow::CGoblinbow()
{
	m_Pos.x = 2;
	m_Pos.y = 2;
	m_Body = cvLoadImage("Pic\\mob006.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block3.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block5.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}

CGoblinbow::CGoblinbow(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob006.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block3.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block5.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
	m_Text = cvLoadImage("Pic\\mob006t.png");
}


CGoblinbow::~CGoblinbow()
{
}
