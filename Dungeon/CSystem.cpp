#include  "stdafx.h"
#include  "CSystem.h"

CSystem::CSystem()
{
	m_Level = 1;
	m_Room = 1;

	//基础背景
	m_Back0 = cvLoadImage("Pic\\back0.png");
	m_BackMap = cvCloneImage(m_Back0);
	m_Backt = cvCloneImage(m_BackMap);

	//开始界面
	m_BackStart[0] = cvLoadImage("Pic\\start0.png");
	m_BackStart[1] = cvLoadImage("Pic\\start1.png");

	//村庄
	m_ImgVillage[2] = cvLoadImage("Pic\\block102.png");
	m_ImgVillage[3] = cvLoadImage("Pic\\block103.png");

	//门 
	m_ImgDoor[1] = cvLoadImage("Pic\\block101.png");
	m_ImgDoor[0] = cvLoadImage("Pic\\block100.png");

	//关卡名字
	m_TextLevelName[0] = cvLoadImage("Pic\\rtext0.png");
	m_TextLevelName[1] = cvLoadImage("Pic\\rtext1.png");

	//方块
	m_ImgBit[0] = cvLoadImage("Pic\\map010.png");
	m_ImgBit[1] = cvLoadImage("Pic\\map010.png");

	//上边框
	m_ImgUp[0] = cvLoadImage("Pic\\map104.png");
	m_ImgUp[1] = cvLoadImage("Pic\\map108.png");
	m_ImgUp[2] = cvLoadImage("Pic\\map119.png");
	m_ImgUp[3] = cvLoadImage("Pic\\map129.png");

	//左边框
	m_ImgLeft[0]= cvLoadImage("Pic\\map107.png");
	m_ImgLeft[1] = cvLoadImage("Pic\\map109.png");

	//右边框
	m_ImgRight[0] = cvLoadImage("Pic\\map106.png");
	m_ImgRight[1] = cvLoadImage("Pic\\map110.png");

	//下边框
	m_ImgDown[0] = cvLoadImage("Pic\\map105.png");
	m_ImgDown[1] = cvLoadImage("Pic\\map111.png");

	//窗口
	cvNamedWindow("Dungeon", 1);
}


CSystem::~CSystem()
{
}

void CSystem::Init()
{
	Init_Map();
	CreateChampion();
}

void CSystem::InitSave()
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
		for (int i = 0; i <= m_MapSize + 1; i++)
			for (int j = 0; j <= m_MapSize + 1; j++)
				in >> m_Map[i][j];
		in.close();
	}
	else
	{
		cout << "地图文件打开失败。" << endl;
	}
	DrawMap();
}

void CSystem::RandMap()
{

	for(int i=0;i<=m_MapSize+1;i++)
		for (int j = 0; j <= m_MapSize + 1; j++)
		{
			if (j == 0 || j == 0 || i == m_MapSize + 1 || j == m_MapSize + 1)
				m_Map[i][j] = -1;
			else m_Map[i][j] = 0;
		}

	//生成1~2个障碍
	for (int i = 0; i < 1 + rand() % 2; i++)
		m_Map[1 + rand() % 5][1 + rand() % 5] = 3;

	//生成带锁的门
	m_Map[1 + rand() % 5][1 + rand() % 5] = 10;
}

void CSystem::DrawMap()
{
	cvCopy(m_Back0, m_BackMap);

	//CTools::Draw2Back(m_BackMap, top, 0, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgUp[m_Room], 62, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgLeft[m_Level], 62 + m_ImgUp[m_Room]->height, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgRight[m_Level], 62 + m_ImgUp[m_Room]->height, m_BackMap->width - m_ImgRight[m_Level]->width, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgDown[m_Level], 62 + m_ImgUp[m_Room]->height + m_ImgLeft[m_Level]->height, 0, 'N');

	for (int i = 1; i <= m_MapSize; i++)
		for (int j = 1; j <= m_MapSize; j++)
		{
			//printf("%d%c", m_Map[i][j], (j == m_MapSize) ? '\n' : ' ');
			int x = 62 + m_ImgUp[m_Room]->height + (i - 1) * m_ImgBit[m_Level]->height - 10, y = 7 + (j - 1) * m_ImgBit[m_Level]->width;
			CTools::Draw2BackTrans(m_BackMap, m_ImgBit[m_Level], x, y);
			if (m_Map[i][j] == 2)//花丛
				CTools::Draw2Back(m_BackMap, m_ImgVillage[2], x, y, 'R');
			else if (m_Map[i][j] == 3)//NPC
				CTools::Draw2Back(m_BackMap, m_ImgVillage[3], x, y, 'R');
			else if (m_Map[i][j] == 9)//门
				CTools::Draw2Back(m_BackMap, m_ImgDoor[0], x, y, 'R');
			else if (m_Map[i][j] == 10)//上锁的门
				CTools::Draw2Back(m_BackMap, m_ImgDoor[1], x, y, 'R');
		}
	cvCopy(m_BackMap, m_Backt);
	cvShowImage("Dungeon", m_Backt);
}

void CSystem::ReMap()
{
	//英雄位置更新
	DrawChampion();

	cvShowImage("Dungeon", m_Backt);
}

void CSystem::CreateChampion()
{
	m_Player = new CKnight;
	//cvShowImage("1", m_Player->m_Face);
}

void CSystem::DrawChampion()
{
	CTools::Draw2Back(m_Backt, m_Player->m_Face, m_Player->GetFaceRow(), m_Player->GetFaceCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Body, m_Player->GetBodyRow(), m_Player->GetBodyCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Weapon, m_Player->GetWeaponRow(), m_Player->GetWeaponCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Minor, m_Player->GetMinorRow(), m_Player->GetMinorCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Frame, m_Player->GetFrameRow(), m_Player->GetFrameCol(), 'R');
}

void CSystem::Run()
{
	while (1)
	{
		char key = waitKey(40);
		cout << key;
		if ((key == 'w' || key == 'a' || key == 's' || key == 'd') &&IsSpace(key, m_Player->m_iRow, m_Player->m_iCol))
			m_Player->Move(key);
		cvCopy(m_BackMap, m_Backt);
		ReMap();
	}
}

bool CSystem::IsSpace(char key, int x, int y)
{
	cout <<key<<" "<< x << "," << y << " ";
	switch (key)
	{
	case 'w':
		x--;
		break;
	case 'a':
		y--;
		break;
	case's':
		x++;
		break;
	case'd':
		y++;
		break;
	default:
		break;
	}
	cout << x << "," << y << " "<< m_Map[x][y]<<"  ";
	if (m_Map[x][y] == 0)
	{
		cout << 'y' << endl;
		return true;
	}
	else
	{
		cout << 'n' << endl;
		return false;
	}
}

