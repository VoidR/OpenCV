#pragma once
#include "CRole.h"
#include "CChampion.h"
#include "CMonster.h"
using namespace std;
class CSystem
{
protected:
	bool m_IsSave;//�Ƿ��д浵
	int m_Level;//�ؿ�
	int m_Room;//����
	int m_NumMonsters;//�����й�������
	int m_Map[8][8];//��ͼ
	const int m_MapSize = 6;//��ͼ��С

	const int m_NumberRoad = 0;//��ͼ���--ͨ·
	const int m_NumberObstacle = 1;//��ͼ���--�ϰ���
	const int m_NumberChampion = 2;//��ͼ���--Ӣ��
	const int m_NumberMonster = 3;//��ͼ���--����
	const int m_NumberNPC = 8;//��ͼ���--NPC
	const int m_NumberUnlockedDoor = 9;//��ͼ���--û������
	const int m_NumberLockedDoor = 10;//��ͼ���--��������

	IplImage* m_Back0;//�հױ���
	IplImage* m_BackStart[2];//��ʼ����
	IplImage* m_BackMap;//��Ϸ����
	IplImage* m_Backt;//��������
	IplImage* m_ImgBit[3];//����ͼƬ
	IplImage* m_ImgUp[8];//�ϱ߿�ͼƬ
	IplImage* m_ImgLeft[3];//��߿�ͼƬͼƬ
	IplImage* m_ImgRight[3];//�ұ߿�ͼƬͼƬ
	IplImage* m_ImgDown[3];//�±߿�ͼƬͼƬ
	IplImage* m_ImgObstacle[3];//�ϰ���ͼƬ
	IplImage* m_ImgDoor[3];//��ͼƬ
	IplImage* m_TextLevelName[5];//�ؿ�����
	IplImage* m_ImgNPC;//NPCͼƬ
	IplImage* m_TextNumber[10];//����ͼƬ


	CChampion* m_Player;//���Ƶ�Ӣ��
	vector <CMonster* >m_Monsters;//����

public:
	CSystem();
	~CSystem();

	void Init();//ȫ����ʼ��
	void InitSave();//�浵�ظ�
	void Init_Map();//��ʼ����ͼ
	void RandMap();//������ɵ�ͼ
	void DrawMap();//���Ʋ�ͬ�ؿ��ĵ�ͼ
	void DrawRoomNum();//���Ʒ�������
	void ReMap();//���µ�ͼ
	void AlterMap(CvPoint pos,int num);//���ĵ�ͼ

	void CreateChampion();//����Ӣ��
	void DrawChampion();//��Ӣ��

	void CreateMonsters();//����Monster
	void DrawMonster();//��Monster
	void MonsterAutoMove();//�����Զ������ƶ�

	void RandAllPos();//����ȫ�����
	CvPoint RandPos();//��ȡ�������

	void Run();//����

	bool IsSpace(CvPoint next);//�յ��ж�
	bool IsOpenDoor(CvPoint next);//��һ���ж�
	CvPoint NextPos(char key, CvPoint now);//��ȡ��һ������
	char GetAutoMoveDir(CMonster* p);//��ȡ�����Զ��ƶ��ķ���
	char GetAutoMoveDirY(CMonster* p);//������ȡ�����Զ��ƶ��ķ���
	bool IsTouch(CMonster* p);//�ж�������ĸ������Ƿ���Ӣ��

	void NextRoom();//������һ��
	void Win();//ʤ��
};

