#pragma once
#include "CRole.h"
#include "CChampion.h"
#include "CMonster.h"
#include "CHonorSystem.h"
using namespace std;
class CSystem
{
protected:
	bool m_IsSave;//是否有存档
	int m_Level;//关卡
	int m_Room;//房间
	int m_EventNum;//事件序号
	int m_TipsNum;//小提示序号
	int m_TipsShift;//小提示切换
	CMonster* m_FaceMonster;//面对的怪物
	int m_MonstersNum;//房间中怪物数量
	int m_MonstersKind[4];//怪物种类
	int m_MonstersPosx[4];//怪物坐标
	int m_MonstersPosy[4];//怪物坐标
	int m_Map[8][8];//地图
	const int m_MapSize = 6;//地图大小
	int m_Honor;//荣誉值

	const int m_NumberRoad = 0;//地图标记--通路
	const int m_NumberObstacle = 1;//地图标记--障碍物
	const int m_NumberChampion = 2;//地图标记--英雄
	const int m_NumberMonster = 3;//地图标记--怪物
	const int m_NumberVat = 4;//地图标记--木桶
	const int m_NumberRecover = 5;//地图标记--回血卷轴
	const int m_NumberPurse = 6;//地图标记--钱袋
	const int m_NumberKey = 7;//地图标记--钥匙
	const int m_NumberNPC = 8;//地图标记--NPC
	const int m_NumberUnlockedDoor = 9;//地图标记--没锁的门
	const int m_NumberLockedDoor = 10;//地图标记--带锁的门

	IplImage* m_Movie[6];//开场动画
	IplImage* m_Back0[2];//空白背景
	IplImage* m_BackStart[2];//开始界面
	IplImage* m_BackMap;//游戏界面
	IplImage* m_Backt;//操作界面
	IplImage* m_ImgBit[3];//方块图片
	IplImage* m_ImgUp[8];//上边框图片
	IplImage* m_ImgLeft[3];//左边框图片图片
	IplImage* m_ImgRight[3];//右边框图片图片
	IplImage* m_ImgDown[3];//下边框图片图片
	IplImage* m_ImgObstacle[8];//障碍物图片
	IplImage* m_ImgDoor[3];//门图片
	IplImage* m_ImgKey;//钥匙图片
	IplImage* m_ImgVat;//木桶图片
	IplImage* m_ImgVatpis[4];//木桶碎片图片
	IplImage* m_ImgRecover;//回血卷轴图片
	IplImage* m_ImgPurse;//钱袋图片
	IplImage* m_TextLevelName[5];//关卡名字
	IplImage* m_ImgNPC;//NPC图片
	IplImage* m_TextNumber[10];//数字图片
	IplImage* m_ImgBlockRed;//可攻击的红色边框
	IplImage* m_ImgBlockGreen;//可移动的绿色边框
	IplImage* m_TextNoKey;//没有钥匙
	IplImage* m_TextTips[3];//小提示图片
	IplImage* m_ImgTipClean;//刷新小提示
	IplImage* m_ImgAttack;//攻击动画
	IplImage* m_ImgDleteLoad;//删除存档界面
	IplImage* m_ImgDead;//死亡界面
	IplImage* m_TextRe;//回血卷轴图鉴图片
	IplImage* m_TextPur;//钱袋图鉴
	IplImage* m_TextKey;//钥匙图鉴
	IplImage* m_TextClean;//图鉴清空

	CChampion* m_Player;//控制的英雄
	vector <CMonster* >m_Monsters;//怪物

	int m_HonorGrade[4];//荣誉等级
	int m_HonorCost[4];//荣誉花费
	IplImage* m_ImgHonorMenu;//荣誉界面图片
	IplImage* m_ImgBackt;//荣誉界面背景图片
	IplImage* m_ImgHonorAdd;//升级图片
	IplImage* m_ImgHonorFull;//满级图片
	IplImage* m_ImgHonorNot;//荣誉不足图片

public:
	CSystem();
	~CSystem();

	void Init();//全部初始化
	void InitSave();//存档回复
	void StartMovie();//开场动画
	void Init_Map();//初始化地图
	void RandMap();//随机生成地图
	void DrawMap();//绘制不同关卡的地图
	void DrawRoomNum();//绘制房间数字
	void DrawMonsterText();//绘制怪物图鉴
	void DrawHonor();//绘制荣誉值
	void ReMap();//更新地图
	void AlterMap(CvPoint pos,int num);//更改地图
	void DrawEvent();//绘制事件
	void InitStatus();//初始化地图标记
	void ReTips();//更新小提示
	void OpenVat(CvPoint pos);//打破木桶
	void AttackEffects(CvPoint obj, int num);//攻击动画

	void DrawHonorMenu();//绘制荣誉商店界面
	void HonorSystem();//荣耀系统

	void CreateChampion();//创建英雄
	void DrawChampion();//画英雄
	void ChampionMove(char key);//英雄移动
	void ChampionAttack(CvPoint next);//攻击怪物

	void CreateMonsters();//创建Monster
	void CreateMonstersLoading();//加载Monster
	void DrawMonster();//画Monster
	void MonsterAutoMove();//怪物自动靠近移动
	void MonsterAttack(CMonster* monster);//攻击英雄
	void InitMonsterAttack();//初始化攻击标记
	CMonster* GetMonster(CvPoint pos);//获取目标怪物的坐标



	void RandAllPos();//坐标全部随机
	CvPoint RandPos();//获取随机坐标

	void Begin();//开始
	void Run();//运行
	void Save();//保存
	void Load();//加载存档
	bool LoadDelte();//删除存档

	bool IsDead(CRole* role);//死亡判定
	bool IsSpace(CvPoint next);//空地判定
	CvPoint NextPos(char key, CvPoint now);//获取下一步坐标
	CvPoint GetDoorPos();//找到门的坐标
	char GetAutoMoveDir(CMonster* p);//获取怪物自动移动的方向
	char GetAutoMoveDirY(CMonster* p);//辅助获取怪物自动移动的方向
	bool IsTouch(CMonster* p);//判定怪物的四个方向是否有英雄

	void NextRoom();//进入下一关
	void GoHome();//返回村庄
	void Win();//胜利
	void Dead();//死亡
	void Lose();//失败
};