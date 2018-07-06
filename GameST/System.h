#pragma once
#include "stdafx.h"
#include"Bomb.h"
#include<vector>
using namespace std;
class System
{
protected:
	vector <Bomb* > m_vect;//Õ¨µ¯Êý×é
public:
	System();
	~System();
	void CreateBomb(int x,int y);
	void ReBomb();
	void ReMap();

	int m_Map[18][24];//µØÍ¼
	int m_Mapx;
	int m_Mapy;
	IplImage* back0;//²ÝÆº±³¾°
	IplImage* backcreate;//µØÍ¼±³¾°
};

