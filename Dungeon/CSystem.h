#pragma once
class CSystem
{
protected:
	int m_Level;//�ؿ�
	int m_Map[8][8];//��ͼ
	const int m_MapSize = 6;//��ͼ��С
	IplImage* m_Back0;//�հױ���
	IplImage* m_BackStart;//��ʼ����
	IplImage* m_BackMap;//��Ϸ����

public:
	CSystem();
	~CSystem();
	void Init_Map();
	void DrawMap();
};

