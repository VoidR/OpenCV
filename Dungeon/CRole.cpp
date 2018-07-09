#include "stdafx.h"
#include "CRole.h"


CRole::CRole()
{
}


CRole::~CRole()
{
	//cvReleaseImage(&m_Face);
	cvReleaseImage(&m_Body);
	//cvReleaseImage(&m_Weapon);
	//cvReleaseImage(&m_Minor);
	//cvReleaseImage(&m_Block);
}




int CRole::GetBlockCol()
{
	return (m_Pos.y - 1) * 58 + 2 + 7;
}

void CRole::Move(char key)
{
	switch (key)
	{
	case 'w':
		m_Pos.x--;
		break;
	case 'a':
		m_Pos.y--;
		break;
	case's':
		m_Pos.x++;
		break;
	case'd':
		m_Pos.y++;
		break;
	default:
		break;
	}
}

void CRole::RePos(CvPoint next)
{
	m_Pos = next;
}

int CRole::Hurt(int damage)
{
	int damagenum = damage - m_Armor;
	if (damagenum <= -5)	damagenum = 0;
	else if (damagenum <= 0)	damagenum = 1;
	m_Health -= damagenum;
	return damagenum;
}

