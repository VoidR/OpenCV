#include "stdafx.h"
#include "CSystem.h"


CSystem::CSystem()
{
	m_Level = 0;
	m_Back0 = cvCreateImage(CvSize(360, 600), IPL_DEPTH_8U, 3);
	
	for(int i=0;i<600;i++)
		for (int j = 0; j < 360; j++)
		{
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3) = 7;
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3 + 1) = 7;
			CV_IMAGE_ELEM(m_Back0, uchar, i, j * 3 + 2) = 7;
		}
	/*
	IplImage* top = cvLoadImage("Pic\\image001.png");
	CTools::Draw2Back(m_Back0, top, 40, 69, 'W');
	cvShowImage("Dungeon", m_Back0);
	waitKey();*/
}


CSystem::~CSystem()
{
}

void CSystem::Init_Map()
{
	char mapstr[] = "map0.txt";
	mapstr[3] = '0' + m_Level;
	ifstream in;
	in.open(mapstr);
	if(in.is_open())
	{ 
		for (int i = 1; i <= m_MapSize; i++)
			for (int j = 1; j <= m_MapSize; j++)
				in >> m_Map[i][j];
	}
	else
	{
		cout << "地图文件打开失败。" << endl;
	}
	DrawMap();
}

void CSystem::DrawMap()
{
	IplImage* bit = cvLoadImage("Pic\\map010.png");
	IplImage* zuo = cvLoadImage("Pic\\map107.png");
	IplImage* you = cvLoadImage("Pic\\map106.png");
	IplImage* shang = cvLoadImage("Pic\\map104.png");
	IplImage* xia = cvLoadImage("Pic\\map105.png");
	IplImage* top = cvLoadImage("Pic\\image037.png");

	for (int i = 1; i <= m_MapSize; i++)
		for (int j = 1; j <= m_MapSize; j++)
			//CTools::Draw2Back(m_Back0, bit, 150 + (i - 1) * bit->height, 9+(j - 1) * bit->width, 'N');
	CTools::Draw2Back(m_Back0, top, 0, 0, 'N');
	CTools::Draw2Back(m_Back0, shang, 62, 0, 'W');
	//CTools::Draw2Back(m_Back0, zuo, 150, 0, 'W');
	CTools::Draw2Back(m_Back0, you, 150, 360-you->width, 'W');
	CTools::Draw2Back(m_Back0, xia, 150 + zuo->height, 0, 'W');
	cvShowImage("Dungeon", m_Back0);
	waitKey();
}
