#pragma once
class CSystem
{
protected:
	int m_Level;//关卡
	int m_Map[8][8];//地图
	const int m_MapSize = 6;//地图大小
	IplImage* m_Back0;//空白背景
	IplImage* m_BackStart;//开始界面
	IplImage* m_BackMap;//游戏界面

public:
	CSystem();
	~CSystem();
	void Init_Map();
	void DrawMap();
};

