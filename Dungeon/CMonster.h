#pragma once
#include "CRole.h"
class CMonster :
	public CRole
{
public:
	CMonster();
	~CMonster();
	int GetBodyRow();//��������������������
	int GetBodyCol();//�������������������
	int GetBlockRow();//����߿�������������
	int GetBlockCol();//����߿������������

	IplImage* m_BlockKeyR[2];//��Կ�׵Ŀɹ����߿�߿�
	IplImage* m_BlockKey[2];//��Կ�׵ı߿�
	IplImage* m_Text;//ͼ��ͼƬ
	int m_Key;//�Ƿ���Կ��
	int m_IsAttack;//�Ƿ��Ѿ�����
	int m_HonorOut;//���ܺ��õ�����ֵ

	void ReProperty(int grade);
};

