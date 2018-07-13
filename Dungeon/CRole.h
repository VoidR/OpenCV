#pragma once
class CRole
{
public:
	CRole();
	~CRole();
	CvPoint m_Pos;//����
	int m_Health;//����ֵ
	int m_Damage;//�˺�
	int m_Armor;//����

	int m_BasicHealth;//��������ֵ
	int m_BasicDamage;//�����˺�
	int m_BasicArmor;//��������

	IplImage* m_Body;//����ͼƬ

	virtual int GetBodyRow() = 0;//��������������������
	virtual int GetBodyCol() = 0;//�������������������
	virtual int GetBlockRow() = 0;//����߿�������������
	virtual int GetBlockCol() = 0;//����߿������������

	void Move(char key);//�ƶ�
	void RePos(CvPoint next);//�޸�����
	int Hurt(int damage);//�ܵ��˺�
};

