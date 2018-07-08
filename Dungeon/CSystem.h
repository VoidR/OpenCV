#pragma once
#include "CRole.h"
#include "CChampion.h"
#include "CMonster.h"
using namespace std;
class CSystem
{
protected:
	bool m_IsSave;//是否有存档
	int m_Level;//关卡
	int m_Room;//房间
	int m_NumMonsters;//房间中怪物数量
	int m_Map[8][8];//地图
	const int m_MapSize = 6;//地图大小

	const int m_NumberRoad = 0;//地图标记--通路
	const int m_NumberObstacle = 1;//地图标记--障碍物
	const int m_NumberChampion = 2;//地图标记--英雄
	const int m_NumberMonster = 3;//地图标记--怪物
	const int m_NumberNPC = 8;//地图标记--NPC
	const int m_NumberUnlockedDoor = 9;//地图标记--没锁的门
	const int m_NumberLockedDoor = 10;//地图标记--带锁的门

	IplImage* m_Back0;//空白背景
	IplImage* m_BackStart[2];//开始界面
	IplImage* m_BackMap;//游戏界面
	IplImage* m_Backt;//操作界面
	IplImage* m_ImgBit[3];//方块图片
	IplImage* m_ImgUp[8];//上边框图片
	IplImage* m_ImgLeft[3];//左边框图片图片
	IplImage* m_ImgRight[3];//右边框图片图片
	IplImage* m_ImgDown[3];//下边框图片图片
	IplImage* m_ImgObstacle[3];//障碍物图片
	IplImage* m_ImgDoor[3];//门图片
	IplImage* m_TextLevelName[5];//关卡名字
	IplImage* m_ImgNPC;//NPC图片
	IplImage* m_TextNumber[10];//数字图片


	CChampion* m_Player;//控制的英雄
	vector <CMonster* >m_Monsters;//怪物

public:
	CSystem();
	~CSystem();

	void Init();//全部初始化
	void InitSave();//存档回复
	void Init_Map();//初始化地图
	void RandMap();//随机生成地图
	void DrawMap();//绘制不同关卡的地图
	void DrawRoomNum();//绘制房间数字
	void ReMap();//更新地图
	void AlterMap(CvPoint pos,int num);//更改地图

	void CreateChampion();//创建英雄
	void DrawChampion();//画英雄

	void CreateMonsters();//创建Monster
	void DrawMonster();//画Monster
	void MonsterAutoMove();//怪物自动靠近移动

	void RandAllPos();//坐标全部随机
	CvPoint RandPos();//获取随机坐标

	void Run();//运行

	bool IsSpace(CvPoint next);//空地判定
	bool IsOpenDoor(CvPoint next);//下一关判定
	CvPoint NextPos(char key, CvPoint now);//获取下一步坐标
	char GetAutoMoveDir(CMonster* p);//获取怪物自动移动的方向
	char GetAutoMoveDirY(CMonster* p);//辅助获取怪物自动移动的方向
	bool IsTouch(CMonster* p);//判定怪物的四个方向是否有英雄

	void NextRoom();//进入下一关
	void Win();//胜利
};

