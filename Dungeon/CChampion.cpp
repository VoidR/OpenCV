#include  "stdafx.h"
#include  "CChampion.h"


CChampion::CChampion()
{
	
}


CChampion::~CChampion()
{
	cvReleaseImage(&m_Face);
	cvReleaseImage(&m_Body);
	cvReleaseImage(&m_Weapon);
	cvReleaseImage(&m_Minor);
	cvReleaseImage(&m_Frame);
}

int CChampion::GetFaceRow()
{
	return 140 + (m_iRow - 1) * 58 + 2;
}

int CChampion::GetFaceCol()
{
	return (m_iCol - 1) * 58 + (58 - m_Face->width) / 2 + 5;
}

int CChampion::GetBodyRow()
{
	return 140 + (m_iRow - 1) * 58 + m_Face->height+1;
}

int CChampion::GetBodyCol()
{
	return (m_iCol - 1) * 58 + (58 - m_Body->width) / 2 + (m_Face->width - m_Body->width) / 2 + 5 - 1;
}

int CChampion::GetWeaponRow()
{
	return 140 + m_iRow * 58 - m_Weapon->height -7;
}

int CChampion::GetWeaponCol()
{
	return  m_iCol * 58 - m_Weapon->width - 2;
}

int CChampion::GetMinorRow()
{
	return 140 + m_iRow * 58 - m_Minor->height - 7 - 2;
}

int CChampion::GetMinorCol()
{
	return  (m_iCol - 1) * 58 + 7 + 7;
}

int CChampion::GetFrameRow()
{
	return  140 + (m_iRow - 1) * 58 + 2;
}

int CChampion::GetFrameCol()
{
	return (m_iCol - 1) * 58 + 2 + 7;
}

void CChampion::Move(char key)
{
	switch (key)
	{
	case 'w':
		m_iRow--;
		break;
	case 'a':
		m_iCol--;
		break;
	case's':
		m_iRow++;
		break;
	case'd':
		m_iCol++;
		break;
	default:
		break;
	}
}
