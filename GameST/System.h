#pragma once
#include "stdafx.h"
#include<vector>
using namespace std;
class System
{
protected:
	vector <Bomb* > m_vect;//炸弹数组
public:
	System();
	~System();
	void CreateBomb(int x,int y);
	void ReBomb();
	void ReMap();
	void Show();
	bool IsSpace(int x, int y);
	bool IsWalk(CPlayer* p, char key);
	void Run();

	int m_Map[18][24];//地图
	int m_Mapx;
	int m_Mapy;
	IplImage* m_back0;//草坪背景
	IplImage* m_backt;//运行时用作处理的背景
	IplImage* m_backcreate;//地图背景

	CPlayer* m_robot;//机器人
	CPlayer* m_player1;//玩家
};

