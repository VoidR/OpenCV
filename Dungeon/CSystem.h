#pragma once
#include "CRole.h"
#include "CChampion.h"
#include "CMonster.h"
#include "CHonorSystem.h"
using namespace std;
class CSystem
{
protected:
	bool m_IsSave;//�Ƿ��д浵
	int m_Level;//�ؿ�
	int m_Room;//����
	int m_EventNum;//�¼����
	int m_TipsNum;//С��ʾ���
	int m_TipsShift;//С��ʾ�л�
	CMonster* m_FaceMonster;//��ԵĹ���
	int m_MonstersNum;//�����й�������
	int m_MonstersKind[4];//��������
	int m_MonstersPosx[4];//��������
	int m_MonstersPosy[4];//��������
	int m_Map[8][8];//��ͼ
	const int m_MapSize = 6;//��ͼ��С
	int m_Honor;//����ֵ

	const int m_NumberRoad = 0;//��ͼ���--ͨ·
	const int m_NumberObstacle = 1;//��ͼ���--�ϰ���
	const int m_NumberChampion = 2;//��ͼ���--Ӣ��
	const int m_NumberMonster = 3;//��ͼ���--����
	const int m_NumberVat = 4;//��ͼ���--ľͰ
	const int m_NumberRecover = 5;//��ͼ���--��Ѫ����
	const int m_NumberPurse = 6;//��ͼ���--Ǯ��
	const int m_NumberKey = 7;//��ͼ���--Կ��
	const int m_NumberNPC = 8;//��ͼ���--NPC
	const int m_NumberUnlockedDoor = 9;//��ͼ���--û������
	const int m_NumberLockedDoor = 10;//��ͼ���--��������

	IplImage* m_Movie[6];//��������
	IplImage* m_Back0[2];//�հױ���
	IplImage* m_BackStart[2];//��ʼ����
	IplImage* m_BackMap;//��Ϸ����
	IplImage* m_Backt;//��������
	IplImage* m_ImgBit[3];//����ͼƬ
	IplImage* m_ImgUp[8];//�ϱ߿�ͼƬ
	IplImage* m_ImgLeft[3];//��߿�ͼƬͼƬ
	IplImage* m_ImgRight[3];//�ұ߿�ͼƬͼƬ
	IplImage* m_ImgDown[3];//�±߿�ͼƬͼƬ
	IplImage* m_ImgObstacle[8];//�ϰ���ͼƬ
	IplImage* m_ImgDoor[3];//��ͼƬ
	IplImage* m_ImgKey;//Կ��ͼƬ
	IplImage* m_ImgVat;//ľͰͼƬ
	IplImage* m_ImgVatpis[4];//ľͰ��ƬͼƬ
	IplImage* m_ImgRecover;//��Ѫ����ͼƬ
	IplImage* m_ImgPurse;//Ǯ��ͼƬ
	IplImage* m_TextLevelName[5];//�ؿ�����
	IplImage* m_ImgNPC;//NPCͼƬ
	IplImage* m_TextNumber[10];//����ͼƬ
	IplImage* m_ImgBlockRed;//�ɹ����ĺ�ɫ�߿�
	IplImage* m_ImgBlockGreen;//���ƶ�����ɫ�߿�
	IplImage* m_TextNoKey;//û��Կ��
	IplImage* m_TextTips[3];//С��ʾͼƬ
	IplImage* m_ImgTipClean;//ˢ��С��ʾ
	IplImage* m_ImgAttack;//��������
	IplImage* m_ImgDleteLoad;//ɾ���浵����
	IplImage* m_ImgDead;//��������
	IplImage* m_TextRe;//��Ѫ����ͼ��ͼƬ
	IplImage* m_TextPur;//Ǯ��ͼ��
	IplImage* m_TextKey;//Կ��ͼ��
	IplImage* m_TextClean;//ͼ�����

	CChampion* m_Player;//���Ƶ�Ӣ��
	vector <CMonster* >m_Monsters;//����

	int m_HonorGrade[4];//�����ȼ�
	int m_HonorCost[4];//��������
	IplImage* m_ImgHonorMenu;//��������ͼƬ
	IplImage* m_ImgBackt;//�������汳��ͼƬ
	IplImage* m_ImgHonorAdd;//����ͼƬ
	IplImage* m_ImgHonorFull;//����ͼƬ
	IplImage* m_ImgHonorNot;//��������ͼƬ

public:
	CSystem();
	~CSystem();

	void Init();//ȫ����ʼ��
	void InitSave();//�浵�ظ�
	void StartMovie();//��������
	void Init_Map();//��ʼ����ͼ
	void RandMap();//������ɵ�ͼ
	void DrawMap();//���Ʋ�ͬ�ؿ��ĵ�ͼ
	void DrawRoomNum();//���Ʒ�������
	void DrawMonsterText();//���ƹ���ͼ��
	void DrawHonor();//��������ֵ
	void ReMap();//���µ�ͼ
	void AlterMap(CvPoint pos,int num);//���ĵ�ͼ
	void DrawEvent();//�����¼�
	void InitStatus();//��ʼ����ͼ���
	void ReTips();//����С��ʾ
	void OpenVat(CvPoint pos);//����ľͰ
	void AttackEffects(CvPoint obj, int num);//��������

	void DrawHonorMenu();//���������̵����
	void HonorSystem();//��ҫϵͳ

	void CreateChampion();//����Ӣ��
	void DrawChampion();//��Ӣ��
	void ChampionMove(char key);//Ӣ���ƶ�
	void ChampionAttack(CvPoint next);//��������

	void CreateMonsters();//����Monster
	void CreateMonstersLoading();//����Monster
	void DrawMonster();//��Monster
	void MonsterAutoMove();//�����Զ������ƶ�
	void MonsterAttack(CMonster* monster);//����Ӣ��
	void InitMonsterAttack();//��ʼ���������
	CMonster* GetMonster(CvPoint pos);//��ȡĿ����������



	void RandAllPos();//����ȫ�����
	CvPoint RandPos();//��ȡ�������

	void Begin();//��ʼ
	void Run();//����
	void Save();//����
	void Load();//���ش浵
	bool LoadDelte();//ɾ���浵

	bool IsDead(CRole* role);//�����ж�
	bool IsSpace(CvPoint next);//�յ��ж�
	CvPoint NextPos(char key, CvPoint now);//��ȡ��һ������
	CvPoint GetDoorPos();//�ҵ��ŵ�����
	char GetAutoMoveDir(CMonster* p);//��ȡ�����Զ��ƶ��ķ���
	char GetAutoMoveDirY(CMonster* p);//������ȡ�����Զ��ƶ��ķ���
	bool IsTouch(CMonster* p);//�ж�������ĸ������Ƿ���Ӣ��

	void NextRoom();//������һ��
	void GoHome();//���ش�ׯ
	void Win();//ʤ��
	void Dead();//����
	void Lose();//ʧ��
};