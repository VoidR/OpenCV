#include "stdafx.h"
#include "CMurloc.h"


CMurloc::CMurloc()
{
	m_Pos.x = 2;
	m_Pos.y = 2;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_BlockKeyR[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKeyR[1] = cvLoadImage("Pic\\block4.png");
	m_BasicHealth = 15;
	m_BasicDamage = 4;
	m_BasicArmor = 3;
}

CMurloc::CMurloc(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob022.png");
	m_BlockKeyR[0] = cvLoadImage("Pic\\block2.png");
	m_BlockKeyR[1] = cvLoadImage("Pic\\block4.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block002.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block004.png");
	m_BasicHealth = 15;
	m_BasicDamage = 5;
	m_BasicArmor = 3;
	m_Text = cvLoadImage("Pic\\mob022t.png");
}


CMurloc::~CMurloc()
{
}
