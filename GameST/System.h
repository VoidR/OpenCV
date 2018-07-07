#pragma once
#include "stdafx.h"
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
	void Show();
	bool IsSpace(int x, int y);
	bool IsWalk(CPlayer* p, char key);
	void Run();

	int m_Map[18][24];//��ͼ
	int m_Mapx;
	int m_Mapy;
	IplImage* m_back0;//��ƺ����
	IplImage* m_backt;//����ʱ��������ı���
	IplImage* m_backcreate;//��ͼ����

	CPlayer* m_robot;//������
	CPlayer* m_player1;//���
};

