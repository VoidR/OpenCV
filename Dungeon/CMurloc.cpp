#include "stdafx.h"
#include "CMurloc.h"


CMurloc::CMurloc()
{
	m_Pos.x = 2;
	m_Pos.y = 2;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_Block = cvLoadImage("Pic\\block2.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}

CMurloc::CMurloc(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_Block = cvLoadImage("Pic\\block2.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}


CMurloc::~CMurloc()
{
}
