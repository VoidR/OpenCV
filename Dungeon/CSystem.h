#pragma once
#include "CChampion.h"

class CSystem
{
protected:
	bool m_IsSave;//�Ƿ��д浵
	int m_Level;//�ؿ�
	int m_Room;//����
	int m_Map[8][8];//��ͼ
	const int m_MapSize = 6;//��ͼ��С

	IplImage* m_Back0;//�հױ���
	IplImage* m_BackStart[2];//��ʼ����
	IplImage* m_BackMap;//��Ϸ����
	IplImage* m_Backt;//��������
	IplImage* m_ImgBit[3];//����ͼƬ
	IplImage* m_ImgUp[8];//�ϱ߿�ͼƬ
	IplImage* m_ImgLeft[3];//��߿�ͼƬͼƬ
	IplImage* m_ImgRight[3];//�ұ߿�ͼƬͼƬ
	IplImage* m_ImgDown[3];//�±߿�ͼƬͼƬ
	IplImage* m_ImgVillage[4];//��ׯͼƬ
	IplImage* m_ImgJungle[4];//����ͼƬ
	IplImage* m_ImgDoor[3];//��ͼƬ
	IplImage* m_TextLevelName[5];//�ؿ�����


	CChampion* m_Player;//���Ƶ�Ӣ��

public:
	CSystem();
	~CSystem();

	void Init();//ȫ����ʼ��
	void InitSave();//�浵�ظ�
	void Init_Map();//��ʼ����ͼ
	void RandMap();//������ɵ�ͼ
	void DrawMap();//���Ʋ�ͬ�ؿ��ĵ�ͼ
	void ReMap();//���µ�ͼ

	void CreateChampion();//����Ӣ��
	void DrawChampion();//��Ӣ��

	void Run();//
	bool IsSpace(char key, int x, int y);
};

