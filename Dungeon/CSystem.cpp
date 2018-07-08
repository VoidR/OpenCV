#include  "stdafx.h"
#include  "CSystem.h"

CSystem::CSystem()
{
	m_Level = 0;
	m_Room = 0;

	
	//��������
	m_Back0 = cvLoadImage("Pic\\back0.png");
	m_BackMap = cvCloneImage(m_Back0);
	m_Backt = cvCloneImage(m_BackMap);

	//��ʼ����
	m_BackStart[0] = cvLoadImage("Pic\\start0.png");//�޴浵
	m_BackStart[1] = cvLoadImage("Pic\\start1.png");//�д浵

	//��ׯ
	//m_ImgVillage[2] = cvLoadImage("Pic\\block102.png");//

	//NPC
	m_ImgNPC = cvLoadImage("Pic\\block103.png");

	//�� 
	m_ImgDoor[1] = cvLoadImage("Pic\\block101.png");//��������
	m_ImgDoor[0] = cvLoadImage("Pic\\block100.png");//û������

	//�ؿ�����
	m_TextLevelName[0] = cvLoadImage("Pic\\rtext0.png");//����
	m_TextLevelName[1] = cvLoadImage("Pic\\rtext1.png");//�������

	//����
	m_ImgBit[0] = cvLoadImage("Pic\\map010.png");//���䷽��
	m_ImgBit[1] = cvLoadImage("Pic\\map010.png");//���ַ���
	m_ImgBit[2] = cvLoadImage("Pic\\map131.png");//ĹѨ����

	//�ϰ���
	m_ImgObstacle[0] = cvLoadImage("Pic\\block102.png");//�����ϰ���
	m_ImgObstacle[1] = cvLoadImage("Pic\\block139.png");//�����ϰ���
	m_ImgObstacle[2] = cvLoadImage("Pic\\block140.png");

	//�ϱ߿�
	m_ImgUp[0] = cvLoadImage("Pic\\map104.png");
	m_ImgUp[1] = cvLoadImage("Pic\\map108.png");
	m_ImgUp[2] = cvLoadImage("Pic\\map119.png");
	m_ImgUp[3] = cvLoadImage("Pic\\map129.png");
	m_ImgUp[4] = cvLoadImage("Pic\\map120.png");
	m_ImgUp[5] = cvLoadImage("Pic\\map121.png");
	m_ImgUp[6] = cvLoadImage("Pic\\map122.png");
	m_ImgUp[7] = cvLoadImage("Pic\\map123.png");

	//��߿�
	m_ImgLeft[0]= cvLoadImage("Pic\\map107.png");
	m_ImgLeft[1] = cvLoadImage("Pic\\map109.png");
	m_ImgLeft[2] = cvLoadImage("Pic\\map103.png");

	//�ұ߿�
	m_ImgRight[0] = cvLoadImage("Pic\\map106.png");
	m_ImgRight[1] = cvLoadImage("Pic\\map110.png");
	m_ImgRight[2] = cvLoadImage("Pic\\map102.png");

	//�±߿�
	m_ImgDown[0] = cvLoadImage("Pic\\map105.png");
	m_ImgDown[1] = cvLoadImage("Pic\\map111.png");
	m_ImgDown[2] = cvLoadImage("Pic\\map101.png");

	//�ؿ�����
	m_TextLevelName[0] = cvLoadImage("Pic\\rtext0.png");
	m_TextLevelName[1] = cvLoadImage("Pic\\rtext1.png");
	m_TextLevelName[2] = cvLoadImage("Pic\\rtext2.png");

	//����
	cvNamedWindow("Dungeon", 1);

	//����ͼƬ
	char str[] = "Pic\\text0c.png";
	for (int i = 0; i < 10; i++)
	{
		str[8] = '0' + i;
		m_TextNumber[i] = cvLoadImage(str);
	}
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
		cout << "��ͼ�ļ���ʧ�ܡ�" << endl;
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

	//����1~2���ϰ�
	for (int i = 0; i < 1 + rand() % 2; i++)
		m_Map[1 + rand() % 5][1 + rand() % 5] = m_NumberObstacle;

	//���ɴ�������
	m_Map[1 + rand() % 5][1 + rand() % 5] = m_NumberUnlockedDoor;
}

void CSystem::DrawMap()
{
	cvCopy(m_Back0, m_BackMap);

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
			if (m_Map[i][j] == m_NumberObstacle)//�ϰ���
				CTools::Draw2Back(m_BackMap, m_ImgObstacle[m_Level], x, y, 'R');
			else if (m_Map[i][j] == m_NumberNPC)//NPC
				CTools::Draw2Back(m_BackMap, m_ImgNPC, x, y, 'R');
			else if (m_Map[i][j] == m_NumberUnlockedDoor)//��
				CTools::Draw2Back(m_BackMap, m_ImgDoor[0], x, y, 'R');
			else if (m_Map[i][j] == m_NumberLockedDoor)//��������
				CTools::Draw2Back(m_BackMap, m_ImgDoor[1], x, y, 'R');
		}
	DrawRoomNum();
	cvCopy(m_BackMap, m_Backt);
}

void CSystem::DrawRoomNum()
{
	int left = 1, right = 1;//�ֺ���������
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

void CSystem::ReMap()
{
	//��ͼ����
	DrawMap();

	//Ӣ��λ�ø���
	DrawChampion();

	//����λ�ø���
	DrawMonster();

	cvShowImage("Dungeon", m_Backt);
}

void CSystem::AlterMap(CvPoint pos, int num)
{
	m_Map[pos.x][pos.y] = num;
}

void CSystem::CreateChampion()
{
	m_Player = new CKnight(RandPos());
	AlterMap(m_Player->m_Pos, m_NumberChampion);
	//cvShowImage("1", m_Player->m_Face);
}

void CSystem::DrawChampion()
{
	CTools::Draw2Back(m_Backt, m_Player->m_Face, m_Player->GetFaceRow(), m_Player->GetFaceCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Body, m_Player->GetBodyRow(), m_Player->GetBodyCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Weapon, m_Player->GetWeaponRow(), m_Player->GetWeaponCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Minor, m_Player->GetMinorRow(), m_Player->GetMinorCol(), 'R');
	CTools::Draw2Back(m_Backt, m_Player->m_Block, m_Player->GetBlockRow(), m_Player->GetBlockCol(), 'R');
}

void CSystem::RandAllPos()
{
	m_Player->RePos(RandPos());
	AlterMap(m_Player->m_Pos, m_NumberChampion);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
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
	vector<CMonster*>().swap(m_Monsters);//����ڴ�
	if (m_Level == 0)	return;
	m_NumMonsters = 2 + rand() % 3;
	CMonster * p=NULL;
	for (int i = 0; i < m_NumMonsters; i++)
	{
		int t = rand() % 3;
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
		m_Monsters.push_back(p);
	}

}

void CSystem::DrawMonster()
{
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		CTools::Draw2Back(m_Backt, m_Monsters[i]->m_Block, m_Monsters[i]->GetBlockRow(), m_Monsters[i]->GetBlockCol(), 'R');
		CTools::Draw2Back(m_Backt, m_Monsters[i]->m_Body, m_Monsters[i]->GetBodyRow(), m_Monsters[i]->GetBodyCol(), 'R');
		AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
	}
}

void CSystem::MonsterAutoMove()
{
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		//if (IsTouch(m_Monsters[i]))	continue;
		char key = GetAutoMoveDir(m_Monsters[i]);
		if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		{
			AlterMap(m_Monsters[i]->m_Pos, m_NumberRoad);
			m_Monsters[i]->Move(key);
			AlterMap(m_Monsters[i]->m_Pos, m_NumberMonster);
		}
	}
}

void CSystem::Run()
{
	while (1)
	{
		char key = waitKey(40);
		//cout << key;
		if ((key == 'w' || key == 'a' || key == 's' || key == 'd'))
		{
			if (IsSpace(NextPos(key, m_Player->m_Pos)))
			{
				AlterMap(m_Player->m_Pos, m_NumberRoad);
				m_Player->Move(key);
				AlterMap(m_Player->m_Pos, m_NumberChampion);
				MonsterAutoMove();
			}
			else if (IsOpenDoor(NextPos(key, m_Player->m_Pos)))
				NextRoom();
		}
		cvCopy(m_BackMap, m_Backt);
		ReMap();
	}
}

bool CSystem::IsSpace(CvPoint next)
{
	if (m_Map[next.x][next.y] == 0)
		return true;
	else
		return false;
}

bool CSystem::IsOpenDoor(CvPoint next)
{
	if (m_Map[next.x][next.y] == 9)
		return true;
	else
		return false;
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

char CSystem::GetAutoMoveDir(CMonster * p)
{
	if (p->m_Pos.y == m_Player->m_Pos.y)//�����·�
	{
		if(GetAutoMoveDirY(p)!='a')
			return GetAutoMoveDirY(p);
	}
	else if (p->m_Pos.y > m_Player->m_Pos.y)//���ҷ�
	{
		if (IsSpace(NextPos('a', p->m_Pos)))//����ͨ·
			return 'a';
		else if (GetAutoMoveDirY(p) != 'a')//�󷽲���ͨ·�����ݷ���
			return GetAutoMoveDirY(p);
	}
	else if (p->m_Pos.y < m_Player->m_Pos.y)//����
	{
		if (IsSpace(NextPos('d', p->m_Pos)))//�ҷ���ͨ·
			return 'd';
		else if (GetAutoMoveDirY(p) != 'a')//�ҷ�����ͨ·�����ݷ���
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
	if (p->m_Pos.x > m_Player->m_Pos.x)//���·�
	{
		if (IsSpace(NextPos('w', p->m_Pos)))//�Ϸ���ͨ·
			return 'w';
	}
	else if (p->m_Pos.x < m_Player->m_Pos.x)//���Ϸ�
	{
		if (IsSpace(NextPos('s', p->m_Pos)))//�·���ͨ·
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
}


void CSystem::Win()
{
	m_Level = 0;
	m_Room = 0;
}

