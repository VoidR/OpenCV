#pragma once
#include "CRole.h"
class CChampion :
	public CRole
{
protected:
public:
	CChampion();
	~CChampion();

	int m_Mana;//����ֵ Ӣ������

	IplImage* m_Face;//����ͼƬ
	IplImage* m_Weapon;//����ͼƬ
	IplImage* m_Minor;//����ͼƬ
	IplImage* m_Block;//�߿�ͼƬ

	int GetFaceRow();//�����沿������������
	int GetFaceCol();//�����沿������������
	int GetBodyRow();//�����沿������������
	int GetBodyCol();//�����沿������������
	int GetWeaponRow();//��������������������
	int GetWeaponCol();//��������������������
	int GetMinorRow();//�������������������
	int GetMinorCol();//������ƺ�����������
	int GetBlockRow();//����߿�������������
	int GetBlockCol();//����߿������������

};

