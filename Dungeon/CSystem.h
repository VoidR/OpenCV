#pragma once
#include "CChampion.h"

class CSystem
{
protected:
	bool m_IsSave;//是否有存档
	int m_Level;//关卡
	int m_Room;//房间
	int m_Map[8][8];//地图
	const int m_MapSize = 6;//地图大小

	IplImage* m_Back0;//空白背景
	IplImage* m_BackStart[2];//开始界面
	IplImage* m_BackMap;//游戏界面
	IplImage* m_Backt;//操作界面
	IplImage* m_ImgBit[3];//方块图片
	IplImage* m_ImgUp[8];//上边框图片
	IplImage* m_ImgLeft[3];//左边框图片图片
	IplImage* m_ImgRight[3];//右边框图片图片
	IplImage* m_ImgDown[3];//下边框图片图片
	IplImage* m_ImgVillage[4];//村庄图片
	IplImage* m_ImgJungle[4];//丛林图片
	IplImage* m_ImgDoor[3];//门图片
	IplImage* m_TextLevelName[5];//关卡名字


	CChampion* m_Player;//控制的英雄

public:
	CSystem();
	~CSystem();

	void Init();//全部初始化
	void InitSave();//存档回复
	void Init_Map();//初始化地图
	void RandMap();//随机生成地图
	void DrawMap();//绘制不同关卡的地图
	void ReMap();//更新地图

	void CreateChampion();//创建英雄
	void DrawChampion();//画英雄

	void Run();//
	bool IsSpace(char key, int x, int y);
};

