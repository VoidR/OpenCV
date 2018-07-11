#include "stdafx.h"
#include "CMurloc.h"


CMurloc::CMurloc()
{
	m_Pos.x = 2;
	m_Pos.y = 2;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block4.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
}

CMurloc::CMurloc(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block4.png");
	m_Health = 8;
	m_Damage = 4;
	m_Armor = 3;
	m_Text = cvLoadImage("Pic\\mob022t.png");
}


CMurloc::~CMurloc()
{
}
