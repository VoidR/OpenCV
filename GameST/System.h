#pragma once
#include "stdafx.h"
#include"Bomb.h"
#include<vector>
using namespace std;
class System
{
protected:
	vector <Bomb* > m_vect;//ը������
public:
	System();
	~System();
	void CreateBomb(int x,int y);
	void ReBomb();
	void ReMap();

	int m_Map[18][24];//��ͼ
	int m_Mapx;
	int m_Mapy;
	IplImage* back0;//��ƺ����
	IplImage* backcreate;//��ͼ����
};

