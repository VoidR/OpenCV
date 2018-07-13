#include "stdafx.h"
#include "CLord.h"


CLord::CLord()
{
	m_Pos.x = 2;
	m_Pos.y =2;
	m_Body = cvLoadImage("Pic\\mob011.png");
	m_BlockKeyR[0] = cvLoadImage("Pic\\block001.png");
	m_BlockKeyR[1] = cvLoadImage("Pic\\block001.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block000.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block000.png");
	m_BasicHealth = 30;
	m_BasicDamage = 7;
	m_BasicArmor = 4;
	m_Text = cvLoadImage("Pic\\mob011t.png");
}

CLord::CLord(CvPoint pos)
{
	m_Pos.x = pos.x;
	m_Pos.y = pos.y;
	m_Body = cvLoadImage("Pic\\mob011.png");
	m_BlockKeyR[0] = cvLoadImage("Pic\\block001.png");
	m_BlockKeyR[1] = cvLoadImage("Pic\\block001.png");
	m_BlockKey[0] = cvLoadImage("Pic\\block000.png");
	m_BlockKey[1] = cvLoadImage("Pic\\block000.png");
	m_BasicHealth = 30;
	m_BasicDamage = 7;
	m_BasicArmor = 4;
	m_Text = cvLoadImage("Pic\\mob011t.png");
}


CLord::~CLord()
{
}
