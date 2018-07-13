#include  "stdafx.h"
#include  "CSystem.h"

CSystem::CSystem()
{
	m_Level = 0;
	m_Room = 0;
	m_EventNum = 0;
	m_TipsNum = 0;
	m_TipsShift = 100; 
	m_Honor = 0;
	
	//基础背景
	m_Back0[0] = cvLoadImage("Pic\\back0.png");
	m_Back0[1] = cvLoadImage("Pic\\back1.png");
	m_BackMap = cvCloneImage(m_Back0[0]);
	m_Backt = cvCloneImage(m_BackMap);
	m_ImgBackt= cvCloneImage(m_Backt);

	//开始界面
	m_BackStart[0] = cvLoadImage("Pic\\start0.png");//无存档
	m_BackStart[1] = cvLoadImage("Pic\\start1.png");//有存档

	//村庄
	//m_ImgVillage[2] = cvLoadImage("Pic\\block102.png");//

	//NPC
	m_ImgNPC = cvLoadImage("Pic\\block103.png");

	//门 
	m_ImgDoor[1] = cvLoadImage("Pic\\block101.png");//上锁的门
	m_ImgDoor[0] = cvLoadImage("Pic\\block100.png");//没锁的门

	//关卡名字
	m_TextLevelName[0] = cvLoadImage("Pic\\rtext0.png");//村落
	m_TextLevelName[1] = cvLoadImage("Pic\\rtext1.png");//迷雾丛林

	//方块
	m_ImgBit[0] = cvLoadImage("Pic\\map010.png");//村落方格
	m_ImgBit[1] = cvLoadImage("Pic\\map010.png");//丛林方格
	m_ImgBit[2] = cvLoadImage("Pic\\map131.png");//墓穴方格

	//障碍物
	m_ImgObstacle[0] = cvLoadImage("Pic\\block102.png");//村落障碍物
	m_ImgObstacle[1] = cvLoadImage("Pic\\block139.png");//丛林障碍物1
	m_ImgObstacle[2] = cvLoadImage("Pic\\block144.png");//丛林障碍物2
	m_ImgObstacle[3] = cvLoadImage("Pic\\block144.png");//丛林障碍物3
	m_ImgObstacle[4] = cvLoadImage("Pic\\block151.png");//墓穴障碍物1
	m_ImgObstacle[5] = cvLoadImage("Pic\\block140.png");//墓穴障碍物2
	m_ImgObstacle[6] = cvLoadImage("Pic\\block150.png");//墓穴障碍物3
	m_ImgObstacle[7] = cvLoadImage("Pic\\block154.png");//墓穴障碍物4

	//上边框
	m_ImgUp[0] = cvLoadImage("Pic\\map104.png");
	m_ImgUp[1] = cvLoadImage("Pic\\map108.png");
	m_ImgUp[2] = cvLoadImage("Pic\\map119.png");
	m_ImgUp[3] = cvLoadImage("Pic\\map129.png");
	m_ImgUp[4] = cvLoadImage("Pic\\map120.png");
	m_ImgUp[5] = cvLoadImage("Pic\\map121.png");
	m_ImgUp[6] = cvLoadImage("Pic\\map122.png");
	m_ImgUp[7] = cvLoadImage("Pic\\map123.png");

	//左边框
	m_ImgLeft[0]= cvLoadImage("Pic\\map107.png");
	m_ImgLeft[1] = cvLoadImage("Pic\\map109.png");
	m_ImgLeft[2] = cvLoadImage("Pic\\map103.png");

	//右边框
	m_ImgRight[0] = cvLoadImage("Pic\\map106.png");
	m_ImgRight[1] = cvLoadImage("Pic\\map110.png");
	m_ImgRight[2] = cvLoadImage("Pic\\map102.png");

	//下边框
	m_ImgDown[0] = cvLoadImage("Pic\\map105.png");
	m_ImgDown[1] = cvLoadImage("Pic\\map111.png");
	m_ImgDown[2] = cvLoadImage("Pic\\map101.png");

	//关卡名字
	m_TextLevelName[0] = cvLoadImage("Pic\\rtext0.png");
	m_TextLevelName[1] = cvLoadImage("Pic\\rtext1.png");
	m_TextLevelName[2] = cvLoadImage("Pic\\rtext2.png");

	//窗口
	cvNamedWindow("Dungeon", 1);

	//开场电影
	char str2[] = "Pic\\movie0.png";
	for (int i = 0; i < 6; i++)
	{
		str2[9] = '0' + i;
		m_Movie[i] = cvLoadImage(str2);
	}
	

	//数字图片
	char str[] = "Pic\\text0c.png";
	for (int i = 0; i < 10; i++)
	{
		str[8] = '0' + i;
		m_TextNumber[i] = cvLoadImage(str);
	}

	//小提示图片
	char str1[] = "Pic\\tip0.png";
	for (int i = 0; i < 3; i++)
	{
		str1[7] = '0' + i;
		m_TextTips[i] = cvLoadImage(str1);
	}
	m_ImgTipClean = cvLoadImage("Pic\\tipclean.png");

	//边框图片
	m_ImgBlockRed = cvLoadImage("Pic\\imageRed.png");
	m_ImgBlockGreen = cvLoadImage("Pic\\imageGreen.png");

	m_TextNoKey= cvLoadImage("Pic\\rtext088.png");
	m_ImgKey = cvLoadImage("Pic\\imgkey.png");
	m_ImgRecover = cvLoadImage("Pic\\block1000.png");
	m_ImgPurse = cvLoadImage("Pic\\block1001.png");
	m_ImgAttack= cvLoadImage("Pic\\image045.png");
	m_ImgDleteLoad = cvLoadImage("Pic\\imagedelte.png");
	m_ImgDead = cvLoadImage("Pic\\imagedead.png");

	//木桶
	m_ImgVat = cvLoadImage("Pic\\block131.png");
	m_ImgVatpis[0]= cvLoadImage("Pic\\image146.png");
	m_ImgVatpis[1] = cvLoadImage("Pic\\image147.png");
	m_ImgVatpis[2] = cvLoadImage("Pic\\image148.png");
	m_ImgVatpis[3] = cvLoadImage("Pic\\image149.png");

	//图鉴
	m_TextRe = cvLoadImage("Pic\\block102t.png");
	m_TextPur = cvLoadImage("Pic\\block137t.png");
	m_TextKey = cvLoadImage("Pic\\rtext139.png");
	m_TextClean = cvLoadImage("Pic\\clean.png");

	//荣誉系统
	for (int i = 0; i < 4; i++)
	{
		m_HonorGrade[i] = 0;
		m_HonorCost[i] = 9;
	}
	m_ImgHonorMenu = cvLoadImage("Pic\\honro.png");
	m_ImgHonorAdd = cvLoadImage("Pic\\1\\image072.png");
	m_ImgHonorNot = cvLoadImage("Pic\\not1.png");
	m_ImgHonorFull = cvLoadImage("Pic\\not2.png");
}


CSystem::~CSystem()
{
}

void CSystem::Init()
{
	Init_Map();
	CreateChampion();
	CreateMonsters();
}

void CSystem::InitSave()
{
}

void CSystem::StartMovie()
{
	for (int i = 0; i<m_Backt->height; i++)
		for (int j = 0; j < m_Backt->width; j++)
		{
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3 + 1) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3 + 2) / 2;
		}
	char key = '0';
	for (int i = 0; i < 6; i++)
	{
		CTools::Draw2Back(m_ImgBackt, m_Movie[i], 181, 60, 'a');
		cvShowImage("Dungeon", m_ImgBackt);
		while ((key = waitKey()) == 'q')	break;
	}
}

void CSystem::Init_Map()
{
	ifstream in;
	in.open("map0.txt");
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
	if (m_Level == 0)
	{
		Init_Map();
		return;
	}
	for(int i=0;i<=m_MapSize+1;i++)
		for (int j = 0; j <= m_MapSize + 1; j++)
		{
			//printf("%d%c", m_Map[i][j], (j == m_MapSize) ? '\n' : ' ');
			if (i == 0 || j == 0 || i == m_MapSize + 1 || j == m_MapSize + 1)
				m_Map[i][j] = -1;
			else m_Map[i][j] = m_NumberRoad;
		}

	CvPoint pos;
	//生成1~2个障碍
	for (int i = 0; i < 1 + rand() % 2; i++)
	{
		pos = RandPos();
		m_Map[pos.x][pos.y] = m_NumberObstacle;
	}
		
	//生成木桶
	pos = RandPos();
	m_Map[pos.x][pos.y] = m_NumberVat;

	//生成带锁的门
	pos = RandPos();
	m_Map[pos.x][pos.y] = m_NumberLockedDoor;
}

void CSystem::DrawMap()
{
	//CTools::Draw2Back(m_BackMap, top, 0, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgUp[m_Room], 62, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgLeft[m_Level], 62 + m_ImgUp[m_Room]->height, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgRight[m_Level], 62 + m_ImgUp[m_Room]->height, m_BackMap->width - m_ImgRight[m_Level]->width, 'N');
	CTools::Draw2Back(m_BackMap, m_ImgDown[m_Level], 62 + m_ImgUp[m_Room]->height + m_ImgLeft[m_Level]->height, 0, 'N');
	CTools::Draw2Back(m_BackMap, m_TextLevelName[m_Level], 10, (m_Level == 0) ? 12 : 0, 'R');

	for (int i = 1; i <= m_MapSize; i++)
		for (int j = 1; j <= m_MapSize; j++)
		{
			//printf("%d%c", m_Map[i][j], (j == m_MapSize) ? '\n' : ' ');
			int x = 62 + m_ImgUp[m_Room]->height + (i - 1) * m_ImgBit[m_Level]->height - 10, y = 7 + (j - 1) * m_ImgBit[m_Level]->width;
			CTools::Draw2BackTrans(m_BackMap, m_ImgBit[m_Level], x, y);
			if (m_Map[i][j] == m_NumberObstacle)//障碍物
				CTools::Draw2Back(m_BackMap, m_ImgObstacle[m_Room], x, y, 'R');
			else if (m_Map[i][j] == m_NumberNPC)//NPC
				CTools::Draw2Back(m_BackMap, m_ImgNPC, x, y, 'R');
			else if (m_Map[i][j] == m_NumberKey)//钥匙
				CTools::Draw2Back(m_BackMap, m_ImgKey, 140 + (i - 1) * 58 + (58 - 14) / 2, 7 + (j - 1) * 58 + (58 - 26) / 2, 'R');
			else if (m_Map[i][j] == m_NumberVat)//木桶
				CTools::Draw2Back(m_BackMap, m_ImgVat, 140 + (i - 1) * 58 + (58 - 48) / 2, 7 + (j - 1) * 58 + (58 - 30) / 2, 'R');
			else if (m_Map[i][j] == m_NumberRecover)//回血卷轴
				CTools::Draw2Back(m_BackMap, m_ImgRecover, 140 + (i - 1) * 58 + (58 - 42) / 2, 7 + (j - 1) * 58 + (58 - 46) / 2, 'R');
			else if (m_Map[i][j] == m_NumberPurse)//钱袋
				CTools::Draw2Back(m_BackMap, m_ImgPurse, 140 + (i - 1) * 58 + (58 - 36) / 2, 7 + (j - 1) * 58 + (58 - 26) / 2, 'R');
			else if (m_Map[i][j] == m_NumberUnlockedDoor)//门
				CTools::Draw2Back(m_BackMap, m_ImgDoor[0], x, y, 'R');
			else if (m_Map[i][j] == m_NumberLockedDoor)//上锁的门
				CTools::Draw2Back(m_BackMap, m_ImgDoor[1], x, y, 'R');
		}
	DrawRoomNum();
	cvCopy(m_BackMap, m_Backt);
}

void CSystem::DrawRoomNum()
{
	int left = 1, right = 1;//分号左右数字
	if (m_Level == 0)
	{
		left = 1;
		right = 1;
	}
	else if (m_Level == 1)
	{
		left = m_Room;
		right = 3;
	}
	else if (m_Level == 2)
	{
		left = m_Room - 3;
		right = 4;
	}
	CTools::Draw2Back(m_BackMap, m_TextNumber[left], 30, 9, 'R');
	CTools::Draw2Back(m_BackMap, m_TextNumber[right], 30, 39, 'R');
}

void CSystem::DrawMonsterText()
{
	if(m_FaceMonster)
		CTools::Draw2Back(m_Backt, m_FaceMonster->m_Text , 555, 225, 'R');
}

void CSystem::DrawHonor()
{
	if (m_Honor)
	{
		int len = 0;
		int honort = m_Honor;
		while (honort) { len++; honort /= 10; }
		honort = m_Honor;
		for (int i = 0; len; i++)
		{
			int t = pow(10, len - 1);
			int num = honort / t;
			CTools::Draw2Back(m_Backt, m_TextNumber[num], 6, 70 + i * 6, 'R');
			honort = honort % t;
			len--;
		}
	}
	else if (m_Honor == 0)
	{
		CTools::Draw2Back(m_Backt, m_TextNumber[0], 6, 70, 'R');
	}
}

void CSystem::ReMap()
{

	//刷新小提示
	ReTips();

	if (m_Room == 0)
	cvCopy(m_Back0[0], m_BackMap);
	else
	cvCopy(m_Back0[1], m_BackMap);

	//地图更新
	DrawMap();

	// 绘制事件
	DrawEvent();

	//绘制荣耀
	DrawHonor();

	//绘制图鉴
	DrawMonsterText();

	//英雄位置更新
	DrawChampion();

	//怪物位置更新
	DrawMonster();


	cvShowImage("Dungeon", m_Backt);
}

void CSystem::AlterMap(CvPoint pos, int num)
{
	m_Map[pos.x][pos.y] = num;
}

void CSystem::DrawEvent()
{
	switch (m_EventNum)
	{
	case 5:
		CTools::Draw2Back(m_Backt, m_TextClean, 557, 5, 'R');
		CTools::Draw2Back(m_Backt, m_TextRe, 557, 5, 'R');
		break;
	case 6:
		CTools::Draw2Back(m_Backt, m_TextClean, 557, 5, 'R');
		CTools::Draw2Back(m_Backt, m_TextPur, 557, 5, 'R');
		break;
	case 7:
		CTools::Draw2Back(m_Backt, m_TextClean, 557, 5, 'R');
		CTools::Draw2Back(m_Backt, m_TextKey, 557, 5, 'R');
		break;
	case 10:
		CTools::Draw2Back(m_Backt, m_TextNoKey, 27, 60, 'R');
		break;
	}
}

void CSystem::InitStatus()
{
	InitMonsterAttack();
	m_EventNum = 0;
}

void CSystem::ReTips()
{
	m_TipsShift++;
	if (m_TipsShift >= 40)
	{
		if (m_Room == 0)
		{
			CTools::Draw2Back(m_Back0[0], m_ImgTipClean, 612, 66, 'N');
			CTools::Draw2Back(m_Back0[0], m_TextTips[m_TipsNum], 619, 66, 'R');
		}
		else
		{
			CTools::Draw2Back(m_Back0[1], m_ImgTipClean, 612, 66, 'N');
			CTools::Draw2Back(m_Back0[1], m_TextTips[m_TipsNum], 619, 66, 'R');
		}
		m_TipsShift = 0;
		m_TipsNum = (m_TipsNum + 1) % 3;
	}
}

void CSystem::OpenVat(CvPoint pos)
{
	int randt = rand() % 5;
	if(randt==0)
		AlterMap(pos, m_NumberPurse);
	else AlterMap(pos, m_NumberRecover);
	ReMap();
	CTools::Draw2Back(m_Backt, m_ImgVatpis[0], 140 + (pos.x - 1) * 58 - 10, 7 + (pos.y - 1) * 58 + 4, 'R');
	CTools::Draw2Back(m_Backt, m_ImgVatpis[1], 140 + (pos.x - 1) * 58 - 10, 7 + (pos.y - 1) * 58 + 42, 'R');
	CTools::Draw2Back(m_Backt, m_ImgVatpis[2], 140 + (pos.x - 1) * 58 + 30, 7 + (pos.y - 1) * 58 + 4, 'R');
	CTools::Draw2Back(m_Backt, m_ImgVatpis[3], 140 + (pos.x - 1) * 58 + 30, 7 + (pos.y - 1) * 58 + 42, 'R');
	cvShowImage("Dungeon", m_Backt); 
	cvWaitKey(300);
}

void CSystem::AttackEffects(CvPoint obj, int num)
{
	CTools::Draw2Back(m_Backt,m_ImgAttack, 150+obj.x*58-58, 7+ obj.y * 58 - 58, 'R');
	if (num)
	{
		int len = 0;
		int numt = num;
		while (numt) { len++; numt /= 10; }
		numt = num;
		for (int i = 0; len; i++)
		{
			int t = pow(10, len - 1);
			int num = numt / t;
			CTools::Draw2Back(m_Backt, m_TextNumber[num], 150 + obj.x * 58 - 58 + 13, 7 + obj.y * 58 - 58 + i * 6 + 18, 'R');
			numt = numt % t;
			len--;
		}
	}
	else if (num == 0)
	{
		CTools::Draw2Back(m_Backt, m_TextNumber[0], 150 + obj.x * 58 - 58 + 13, 7 + obj.y * 58 - 58 + 18, 'R');
	}
	cvShowImage("Dungeon", m_Backt);
	waitKey(250);
}

void CSystem::DrawHonorMenu()
{
	ReMap();
	for(int i=0;i<m_Backt->height;i++)
		for (int j = 0; j < m_Backt->width; j++)
		{
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3) = CV_IMAGE_ELEM(m_Backt, uchar, i, j * 3) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(m_Backt, uchar, i, j * 3 + 1) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(m_Backt, uchar, i, j * 3 + 2) / 2;
		}
	CTools::Draw2Back(m_ImgBackt, m_ImgHonorMenu, 110, 60, 'a');
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < m_HonorGrade[i]; j++)
			CTools::Draw2Back(m_ImgBackt, m_ImgHonorAdd, 110 + 105 + 60 * i, 60 + 7 + 10 * j, 'R');
	if (m_Honor)
	{
		int len = 0;
		int honort = m_Honor;
		while (honort) { len++; honort /= 10; }
		honort = m_Honor;
		for (int i = 0; len; i++)
		{
			int t = pow(10, len - 1);
			int num = honort / t;
			CTools::Draw2Back(m_ImgBackt, m_TextNumber[num], 110 + 53, 60 + 85 + i * 6, 'R');
			honort = honort % t;
			len--;
		}
	}
	else if (m_Honor == 0)
	{
		CTools::Draw2Back(m_ImgBackt, m_TextNumber[0], 110+53, 60+85, 'R');
	}
	for (int i = 0; i < 4; i++)
	{
		int temp = m_HonorCost[i];
		if (temp)
		{
			int len = 0;
			int honort = temp;
			while (honort) { len++; honort /= 10; }
			honort = temp;
			for (int j = 0; len; j++)
			{
				int t = pow(10, len - 1);
				int num = honort / t;
				CTools::Draw2Back(m_ImgBackt, m_TextNumber[num], 200 + 60 * i, 215 + 6 * j, 'R');
				honort = honort % t;
				len--;
			}
		}
	}
	cvShowImage("Dungeon", m_ImgBackt);
}

void CSystem::HonorSystem()
{
	while (1)
	{
		DrawHonorMenu();
		char key = waitKey(20);
		if (key == '1' || key == '3' || key == '2' || key == '4')
		{
			if (m_Honor >= m_HonorCost[key - '1'])
			{
				if (m_HonorGrade[key - '1'] < 18)
				{
					m_HonorCost[key - '1'] += 5 + m_HonorGrade[key - '1'];
					m_HonorGrade[key - '1']++;
					m_Honor -= m_HonorCost[key - '1'];
					m_Player->ReProperty(m_HonorGrade);
				}
				else
				{
					CTools::Draw2Back(m_ImgBackt, m_ImgHonorFull, 110 + 139, 60 + 35, 'a');
					cvShowImage("Dungeon", m_ImgBackt);
					waitKey();
				}
			}
			else
			{
				CTools::Draw2Back(m_ImgBackt, m_ImgHonorNot, 110 + 139, 60 + 35, 'a');
				cvShowImage("Dungeon", m_ImgBackt);
				waitKey();
			}
		}
		else if (key == 'q')
			break;
	}
}

void CSystem::CreateChampion()
{
	m_Player = new CKnight(RandPos());
	AlterMap(m_Player->m_Pos, m_NumberChampion);
	m_Player->ReProperty(m_HonorGrade);
	//cvShowImage("1", m_Player->m_Face);
}

void CSystem::DrawChampion()
{
	CTools::Draw2Back(m_Backt, m_Player->m_Face, m_Player->GetFaceRow(), m_Player->GetFaceCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Body, m_Player->GetBodyRow(), m_Player->GetBodyCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Weapon, m_Player->GetWeaponRow(), m_Player->GetWeaponCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Minor, m_Player->GetMinorRow(), m_Player->GetMinorCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Block, m_Player->GetBlockRow(), m_Player->GetBlockCol(), 'R');

	int num = 0;
	num = m_Player->m_Health;
	for (int i = 0; num; i++)//绘制生命值
	{
		int temp = num % 10;
		CTools::Draw2Back(m_Backt, m_TextNumber[temp], 140 + (m_Player->m_Pos.x - 1) * 58 + 5, 54 + (m_Player->m_Pos.y - 1) * 58 - i * 5, 'R');
		num /= 10;
	}
	num = m_Player->m_Damage;
	for (int i = 0; num; i++)//绘制攻击力
	{
		int temp = num % 10;
		CTools::Draw2Back(m_Backt, m_TextNumber[temp], 140 + (m_Player->m_Pos.x - 1) * 58 + 43, 15 + (m_Player->m_Pos.y - 1) * 58 - i * 5, 'R');
		num /= 10;
	}
	num = m_Player->m_Armor;
	for (int i = 0; num; i++)//绘制护甲
	{
		int temp = num % 10;
		CTools::Draw2Back(m_Backt, m_TextNumber[temp], 140 + (m_Player->m_Pos.x - 1) * 58 + 43, 53 + (m_Player->m_Pos.y - 1) * 58 - i * 5, 'R');
		num /= 10;
	}
	num = m_Player->m_Mana;
	for (int i = 0; num; i++)//绘制魔力值
	{
		int temp = num % 10;
		CTools::Draw2Back(m_Backt, m_TextNumber[temp], 140 + (m_Player->m_Pos.x - 1) * 58 + 5, 16 + (m_Player->m_Pos.y - 1) * 58 - i * 5, 'R');
		num /= 10;
	}


	if (m_Map[m_Player->m_Pos.x - 1][m_Player->m_Pos.y] == 0)
		CTools::Draw2Back(m_Backt, m_ImgBlockGreen, 140 + (m_Player->m_Pos.x - 2) * 58 + 3, (m_Player->m_Pos.y - 1) * 58 + 10, 'B');
	if (m_Map[m_Player->m_Pos.x][m_Player->m_Pos.y - 1] == 0)
		CTools::Draw2Back(m_Backt, m_ImgBlockGreen, 140 + (m_Player->m_Pos.x - 1) * 58 + 3, (m_Player->m_Pos.y - 2) * 58 + 10, 'B');
	if (m_Map[m_Player->m_Pos.x + 1][m_Player->m_Pos.y] == 0)
		CTools::Draw2Back(m_Backt, m_ImgBlockGreen, 140 + (m_Player->m_Pos.x) * 58 + 3, (m_Player->m_Pos.y - 1) * 58 + 10, 'B');
	if (m_Map[m_Player->m_Pos.x][m_Player->m_Pos.y + 1] == 0)
		CTools::Draw2Back(m_Backt, m_ImgBlockGreen, 140 + (m_Player->m_Pos.x - 1) * 58 + 3, (m_Player->m_Pos.y) * 58 + 10, 'B');
}

void CSystem::ChampionMove(char key)
{
	AlterMap(m_Player->m_Pos, m_NumberRoad);
	m_Player->Move(key);
	AlterMap(m_Player->m_Pos, m_NumberChampion);
	ReMap();
}

void CSystem::RandAllPos()
{
	//AlterMap(m_Player->m_Pos, m_NumberRoad);
	m_Player->RePos(RandPos());
	AlterMap(m_Player->m_Pos, m_NumberChampion);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		AlterMap(m_Monsters[i]->m_Pos, m_NumberRoad);
		m_Monsters[i]->RePos(RandPos());
		AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
	}
}

CvPoint CSystem::RandPos()
{
	int x = 0, y = 0;
	while (m_Map[x][y] != 0)
	{
		x = rand() % 6 + 1;
		y = rand() % 6 + 1;
	}
	CvPoint pos(x, y);
	return pos;
}

void CSystem::CreateMonsters()
{
	m_Monsters.clear();
	vector<CMonster*>().swap(m_Monsters);//清空内存
	if (m_Level == 0)	return;
	m_MonstersNum = 2 + rand() % 3;
	CMonster * p=NULL;
	for (int i = 0; i < m_MonstersNum; i++)
	{
		m_MonstersKind[i] = 0;
		if (i == 0 && m_Room == 3)
			p = new CLord(RandPos());
		else if (i == 0 && m_Room == 7)
			p = new CDragon(RandPos());
		else
		{
			int t = rand() % 3;
			m_MonstersKind[i] = t;
			switch (t)
			{
			case 0:
				p = new CSlime(RandPos());
				break;
			case 1:
				p = new CGoblinbow(RandPos());
				break;
			case 2:
				p = new CMurloc(RandPos());
				break;
			}
		}
		p->ReProperty(m_Room);
		if (i == 0)
			p->m_Key = 1;
		else
			p->m_Key = 0;
		if (m_Room <= 3)
		{
			if (i == 0 && m_Room == 3)
				p->m_HonorOut = 12;
			else if (i == 0)
				p->m_HonorOut = 7;
			else
				p->m_HonorOut = 5;
		}
		else if (m_Room <= 7)
		{
			if (i == 0 && m_Room == 7)
				p->m_HonorOut = 20;
			else if (i == 0)
				p->m_HonorOut = 10;
			else
				p->m_HonorOut = 8;
		}
		m_Monsters.push_back(p);
		AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
	}

}

void CSystem::CreateMonstersLoading()
{
	m_Monsters.clear();
	vector<CMonster*>().swap(m_Monsters);//清空内存
	if (m_Level == 0)	return;
	CMonster * p = NULL;
	for (int i = 0; i < m_MonstersNum; i++)
	{
		CvPoint pos;
		pos.x = m_MonstersPosx[i];
		pos.y = m_MonstersPosy[i];
		if (i == 0 && m_Room == 3)
			p = new CLord(pos);
		else if (i == 0 && m_Room == 7)
			p = new CDragon(pos);
		else
		{
			int t = m_MonstersKind[i];
			switch (t)
			{
			case 0:
				p = new CSlime(pos);
				break;
			case 1:
				p = new CGoblinbow(pos);
				break;
			case 2:
				p = new CMurloc(pos);
				break;
			}
		}
		p->ReProperty(m_Room);
		if (i == 0)
			p->m_Key = 1;
		else
			p->m_Key = 0;
		if (m_Room <= 3)
		{
			if (i == 0 && m_Room == 3)
				p->m_HonorOut = 12;
			else if (i == 0)
				p->m_HonorOut = 7;
			else
				p->m_HonorOut = 5;
		}
		else if (m_Room <= 7)
		{
			if (i == 0 && m_Room == 7)
				p->m_HonorOut = 20;
			else if (i == 0)
				p->m_HonorOut = 10;
			else
				p->m_HonorOut = 8;
		}
		m_Monsters.push_back(p);
		AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
	}
}

void CSystem::DrawMonster()
{
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if(IsTouch(m_Monsters[i]))
			CTools::Draw2Back(m_Backt, m_Monsters[i]->m_BlockKeyR[m_Monsters[i]->m_Key], m_Monsters[i]->GetBlockRow(), m_Monsters[i]->GetBlockCol(), 'R');
		else 
			CTools::Draw2Back(m_Backt, m_Monsters[i]->m_BlockKey[m_Monsters[i]->m_Key], m_Monsters[i]->GetBlockRow(), m_Monsters[i]->GetBlockCol(), 'R');
		CTools::Draw2Back(m_Backt, m_Monsters[i]->m_Body, m_Monsters[i]->GetBodyRow(), m_Monsters[i]->GetBodyCol(), 'R');
		int num = 0;
		num = m_Monsters[i]->m_Health;
		for (int t = 0; num;)//绘制生命值
		{
			CTools::Draw2Back(m_Backt, m_TextNumber[num % 10], 140 + (m_Monsters[i]->m_Pos.x - 1) * 58 + 7, 55 + (m_Monsters[i]->m_Pos.y - 1) * 58 - t++ * 5, 'R');
			num /= 10;
		}
		num = m_Monsters[i]->m_Damage;
		for (int t = 0; num;)//绘制攻击力
		{
			CTools::Draw2Back(m_Backt, m_TextNumber[num % 10], 140 + (m_Monsters[i]->m_Pos.x - 1) * 58 + 44, 17 + (m_Monsters[i]->m_Pos.y - 1) * 58 - t++ * 5, 'R');
			num /= 10;
		}
		num = m_Monsters[i]->m_Armor;
		for (int t = 0; num;)//绘制护甲
		{
			CTools::Draw2Back(m_Backt, m_TextNumber[num % 10], 140 + (m_Monsters[i]->m_Pos.x - 1) * 58 + 44, 55 + (m_Monsters[i]->m_Pos.y - 1) * 58 - t++ * 5, 'R');
			num /= 10;
		}
	}
}

void CSystem::MonsterAutoMove()
{
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (m_Monsters[i]->m_IsAttack == 1)
			continue;
		if (IsTouch(m_Monsters[i]))
		{
			MonsterAttack(m_Monsters[i]);
			continue;
		}
		char key = GetAutoMoveDir(m_Monsters[i]);
		if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		{
			AlterMap(m_Monsters[i]->m_Pos, m_NumberRoad);
			m_Monsters[i]->Move(key);
			AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
		}
	}
}

void CSystem::MonsterAttack(CMonster * monster)
{
	AttackEffects(m_Player->m_Pos, m_Player->Hurt(monster->m_Damage));
	if (IsDead(m_Player))
	{
		AlterMap(m_Player->m_Pos, m_NumberRoad);
		Lose();
	}
	monster->m_IsAttack = 1;
}

void CSystem::InitMonsterAttack()
{
	for (int i = 0; i < m_Monsters.size(); i++)
		m_Monsters[i]->m_IsAttack = 0;
}

CMonster * CSystem::GetMonster(CvPoint pos)
{
	int i = 0;
	while (m_Monsters[i]->m_Pos.x != pos.x || m_Monsters[i]->m_Pos.y != pos.y) { i++; }
	return m_Monsters[i];
}


void CSystem::Begin()
{
	ifstream in;
	in.open("data.txt");
	Init();
	if (in.is_open())
	{
		int t;
		in >> t;
		if (t == 1)
		{
			cvShowImage("Dungeon", m_BackStart[1]);
			while (1)
			{
				char key = waitKey(10);
				if (key == 'q')
				{
					Load();
					break;
				}
				else if (key == 'e')
				{
					if (LoadDelte())
					{
						StartMovie();
						break;
					}
					cvShowImage("Dungeon", m_BackStart[1]);
				}
			}
		}
		else
		{
			cvShowImage("Dungeon", m_BackStart[0]); 
			while (1)
			{
				char key = waitKey(10);
				if (key == 'q')
				{
					StartMovie();
					break;
				}
					
			}
		}
		in.close();
	}
	else
	{
		cout << "存档文件打开失败。" << endl;
	}
}

void CSystem::Run()
{
	while (1)
	{
		char key = waitKey(40);
		if (key == 'q'&&m_Room != 0)
			GoHome();
		else if ((key == 'w' || key == 'a' || key == 's' || key == 'd'))
		{
			InitStatus();
			CvPoint next = NextPos(key, m_Player->m_Pos);
			if (m_Map[next.x][next.y] == 0)
			{
				ChampionMove(key);
				MonsterAutoMove();
			}
			else if (m_Map[next.x][next.y] == 3)
			{
				ChampionAttack(next);
				MonsterAutoMove();
			}
			else if (m_Map[next.x][next.y] == 4)
			{
				OpenVat(next);
			}
			else if (m_Map[next.x][next.y] == 5)
			{
				m_Player->Recover(); 
				AlterMap(next, m_NumberRoad);
				ChampionMove(key);
				MonsterAutoMove();
				m_EventNum = 5;
			}
			else if (m_Map[next.x][next.y] == 6)
			{
				m_Honor += 10 + m_Room;
				AlterMap(next, m_NumberRoad);
				ChampionMove(key);
				MonsterAutoMove();
				m_EventNum = 6;
			}
			else if (m_Map[next.x][next.y] == 7)
			{
				AlterMap(next, m_NumberRoad);
				ChampionMove(key);
				MonsterAutoMove();
				m_EventNum = 7;
				AlterMap(GetDoorPos(), m_NumberUnlockedDoor);
			}
			else if (m_Map[next.x][next.y] == 8)
			{
				HonorSystem();
			}
			else if (m_Map[next.x][next.y] == 9)
			{
				NextRoom();
			}
			else if (m_Map[next.x][next.y] == 10)
			{
				m_EventNum = 10;
			}
		}
		ReMap();
	}
}

void CSystem::Save()
{
	ofstream out;
	out.open("data.txt");
	if (out.is_open())
	{
		out << 1 << endl;
		out << m_Room << " " << m_Level << endl;
		for (int i = 0; i <= m_MapSize + 1; i++)
			for (int j = 0; j <= m_MapSize + 1; j++)
				out << m_Map[i][j] << " ";
		out <<endl<< m_Honor<< endl;
		for (int i = 0; i < 4; i++)
			out << m_HonorGrade[i] << " ";
		for (int i = 0; i < 4; i++)
			out << m_HonorCost[i] << " ";
		out << endl << m_MonstersNum << endl;
		for (int i = 0; i < m_MonstersNum; i++)
		{
			out << m_MonstersKind[i] << " ";
		}
		for (int i = 0; i < m_MonstersNum; i++)
		{
			out << m_Monsters[i]->m_Pos.x << " ";
		}
		for (int i = 0; i < m_MonstersNum; i++)
		{
			out << m_Monsters[i]->m_Pos.y << " ";
		}
		out << m_Player->m_Pos.x << " " << m_Player->m_Pos.y << endl;
		out.close();
	}
	else
	{
		cout << "存档文件打开失败。" << endl;
	}
}

void CSystem::Load()
{
	ifstream in;
	in.open("data.txt");
	if (in.is_open())
	{
		int t;
		in >> t;
		in >> m_Room >> m_Level;
		for (int i = 0; i <= m_MapSize + 1; i++)
			for (int j = 0; j <= m_MapSize + 1; j++)
				in >> m_Map[i][j];
		in >> m_Honor;
		for (int i = 0; i < 4; i++)
			in >> m_HonorGrade[i];
		for (int i = 0; i < 4; i++)
			in >> m_HonorCost[i];
		m_Player->ReProperty(m_HonorGrade);
		in >> m_MonstersNum;
		for (int i = 0; i < m_MonstersNum; i++)
		{
			in >> m_MonstersKind[i];
		}
		for (int i = 0; i < m_MonstersNum; i++)
		{
			in >> m_MonstersPosx[i];
		}
		for (int i = 0; i < m_MonstersNum; i++)
		{
			in >> m_MonstersPosy[i];
		}
		CreateMonstersLoading();
		in >> m_Player->m_Pos.x >> m_Player->m_Pos.y;
		in.close();
	}
	else
	{
		cout << "存档文件打开失败。" << endl;
	}
}

bool CSystem::LoadDelte()
{
	for (int i = 0; i<m_Backt->height; i++)
		for (int j = 0; j < m_Backt->width; j++)
		{
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3 + 1) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(m_BackStart[1], uchar, i, j * 3 + 2) / 2;
		}
	CTools::Draw2Back(m_ImgBackt,m_ImgDleteLoad, 181, 60, 'a');
	cvShowImage("Dungeon", m_ImgBackt);
	while (1)
	{
		char key = waitKey(10);
		if (key == 'q')
		{
			ofstream out;
			out.open("data.txt");
			if (out.is_open())
			{
				out << 0 << endl;
				out.close();
			}
			else
			{
				cout << "存档文件打开失败。" << endl;
			}
			return true;
		}
		else if (key == 'e')
			return false;

	}
}

bool CSystem::IsDead(CRole * role)
{
	if (role->m_Health <= 0)
		return true;
	return false;
}

bool CSystem::IsSpace(CvPoint next)
{
	if (m_Map[next.x][next.y] == m_NumberRoad)
		return true;
	else
		return false;
}

void CSystem::ChampionAttack(CvPoint next)
{
	int i = 0;
	while (m_Monsters[i]->m_Pos.x != next.x || m_Monsters[i]->m_Pos.y != next.y) { i++; }
	AttackEffects(m_Monsters[i]->m_Pos, m_Monsters[i]->Hurt(m_Player->m_Damage));
	if (IsDead(m_Monsters[i]))
	{
		m_Honor += m_Monsters[i]->m_HonorOut;
		m_FaceMonster = NULL;
		if (m_Monsters[i]->m_Key == 1)
			AlterMap(m_Monsters[i]->m_Pos, m_NumberKey);
		else
			AlterMap(m_Monsters[i]->m_Pos, m_NumberRoad);
		m_Monsters.erase(m_Monsters.begin() + i);
	}
	else
	{
		m_FaceMonster = GetMonster(next);
		MonsterAttack(m_Monsters[i]);
	}
}

CvPoint CSystem::NextPos(char key , CvPoint now)
{
	switch (key)
	{
	case 'w':
		now.x--;
		break;
	case 'a':
		now.y--;
		break;
	case's':
		now.x++;
		break;
	case'd':
		now.y++;
		break;
	default:
		break;
	}
	CvPoint p = now;
	return p;
}

CvPoint CSystem::GetDoorPos()
{
	CvPoint pos(0,0);

	for (int i = 1; i <= m_MapSize; i++)
		for (int j = 1; j <= m_MapSize; j++)
		{
			if (m_Map[i][j] == 10)
			{
				pos.x = i;
				pos.y = j;
				break;
			}
		}
	return pos;
}

char CSystem::GetAutoMoveDir(CMonster * p)
{
	if (p->m_Pos.y == m_Player->m_Pos.y)//在上下方
	{
		if(GetAutoMoveDirY(p)!='a')
			return GetAutoMoveDirY(p);
	}
	else if (p->m_Pos.y > m_Player->m_Pos.y)//在右方
	{
		if (IsSpace(NextPos('a', p->m_Pos)))//左方是通路
			return 'a';
		else if (GetAutoMoveDirY(p) != 'a')//左方不是通路，看纵方向
			return GetAutoMoveDirY(p);
	}
	else if (p->m_Pos.y < m_Player->m_Pos.y)//在左方
	{
		if (IsSpace(NextPos('d', p->m_Pos)))//右方是通路
			return 'd';
		else if (GetAutoMoveDirY(p) != 'a')//右方不是通路，看纵方向
			return GetAutoMoveDirY(p);
	}
	if(IsSpace(NextPos('w', p->m_Pos)))
		return 'w';
	else if (IsSpace(NextPos('s', p->m_Pos)))
		return 's';
	return 'n';
}

char CSystem::GetAutoMoveDirY(CMonster * p)
{
	if (p->m_Pos.x > m_Player->m_Pos.x)//在下方
	{
		if (IsSpace(NextPos('w', p->m_Pos)))//上方是通路
			return 'w';
	}
	else if (p->m_Pos.x < m_Player->m_Pos.x)//在上方
	{
		if (IsSpace(NextPos('s', p->m_Pos)))//下方是通路
			return 's';
	}
	return 'a';
}

bool CSystem::IsTouch(CMonster * p)
{
	if (m_Map[p->m_Pos.x - 1][p->m_Pos.y] == m_NumberChampion || m_Map[p->m_Pos.x + 1][p->m_Pos.y] == m_NumberChampion
		|| m_Map[p->m_Pos.x][p->m_Pos.y - 1] == m_NumberChampion || m_Map[p->m_Pos.x][p->m_Pos.y + 1] == m_NumberChampion)
		return true;
	else return false;
}


void CSystem::NextRoom()
{
	m_Room++;
	if (m_Room == 0)
		m_Level = 0;
	else if (m_Room >= 1 && m_Room <= 3)
		m_Level = 1;
	else if (m_Room >= 4 && m_Room <= 7)
		m_Level = 2;
	else if(m_Room>7)
		Win();
	RandMap();
	CreateMonsters();
	RandAllPos();
	Save();
}

void CSystem::GoHome()
{
	m_Level = 0;
	m_Room = 0;
	m_Player->ReMAX();
	m_TipsShift = 100;
	m_FaceMonster = NULL;
	m_Monsters.clear();
	vector<CMonster*>().swap(m_Monsters);//清空内存
	RandMap();
	RandAllPos();
	ReMap();
}


void CSystem::Win()
{
	m_Level = 0;
	m_Room = 0;
	
	GoHome();
}

void CSystem::Dead()
{
	cvCopy(m_Backt, m_ImgBackt);
	for (int i = 0; i<m_Backt->height; i++)
		for (int j = 0; j < m_Backt->width; j++)
		{
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3) = CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 1) = CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 1) / 2;
			CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 2) = CV_IMAGE_ELEM(m_ImgBackt, uchar, i, j * 3 + 2) / 2;
		}
	CTools::Draw2Back(m_ImgBackt, m_ImgDead, 181, 60, 'a');
	cvShowImage("Dungeon", m_ImgBackt);
	while (1)
	{
		char key = waitKey(10);
		if (key == 'q')
			break;

	}
}

void CSystem::Lose()
{
	Dead();
	m_Level = 0;
	m_Room = 0;
	m_Player->ReMAX();
	m_FaceMonster = NULL;
	m_Monsters.clear();
	vector<CMonster*>().swap(m_Monsters);//清空内存
	RandMap();
	ReMap();
}
