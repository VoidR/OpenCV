#pragma once
class CChampion
{
protected:
public:
	CChampion();
	~CChampion();
	int m_iRow;//��������
	int m_iCol;//��������
	int m_Health;//����ֵ
	int m_Mana;//����ֵ
	int m_Damage;//�˺�
	int m_Armor;//����

	IplImage* m_Face;//����ͼƬ
	IplImage* m_Body;//����ͼƬ
	IplImage* m_Weapon;//����ͼƬ
	IplImage* m_Minor;//����ͼƬ
	IplImage* m_Frame;//�߿�ͼƬ

	int GetFaceRow();//�����沿������������
	int GetFaceCol();//�����沿������������
	int GetBodyRow();//��������������������
	int GetBodyCol();//�������������������
	int GetWeaponRow();//�����沿������������
	int GetWeaponCol();//�����沿������������
	int GetMinorRow();//��������������������
	int GetMinorCol();//�������������������
	int GetFrameRow();//��������������������
	int GetFrameCol();//�������������������

	void Move(char key);//�ƶ�
};

