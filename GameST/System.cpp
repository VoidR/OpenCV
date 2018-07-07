#include "stdafx.h"
#include "System.h"


System::System()
{
	m_back0 = cvLoadImage("Pic\\back1.jpg");
	m_backcreate = cvCloneImage(m_back0);
	m_backt = cvCloneImage(m_backcreate);
	m_robot = new CRobot;
	m_player1 = new CBaoBao;
	m_Mapx = 16;
	m_Mapy = 22;
	ifstream in;
	in.open("map.txt");
	if (in.is_open())
	{
		for (int i = 0; i <= m_Mapx + 1; i++)
		{
			for (int j = 0; j <= m_Mapy + 1; j++)
				in >> m_Map[i][j];
		}
		in.close();
	}
	else
	{
		cout << "µØÍ¼´ò¿ª´íÎó." << endl;
	}
	ReMap();
}


System::~System()
{
	//cvReleaseImage(&back0);
	//cvReleaseImage(&backcreate);
	cvReleaseImage(&m_back0);
	cvDestroyAllWindows();
}

void System::CreateBomb(int x, int y)
{
	Bomb* p = new Bomb(x, y);
	m_vect.push_back(p);
}


void System::ReBomb()
{
	for (int i = 0; i < (int)m_vect.size(); i++)
	{
		if (m_vect[i]->Rebomb(m_backcreate))
		{
			m_vect.erase(m_vect.begin() + i);
		}
	}
	
}

void System::ReMap()
{
	cvCopy(m_back0, m_backcreate);
	char str_obstacle[] = "Pic\\obstacle0.jpg";
	char str_stone[] = "Pic\\stone0.jpg";
	for (int i = 1; i <= m_Mapx; i++)
	{
		for (int j = 1; j <= m_Mapy; j++)
		{
			if (m_Map[i][j] >= 4)
			{
				str_stone[9] = '0' + m_Map[i][j] - 3;
				Tools::Draw2Back(m_backcreate, str_stone, (i - 1) * 40, (j - 1) * 40, 'W');
			}
			else if (m_Map[i][j] > 0)
			{
				str_obstacle[12] = '0' + m_Map[i][j];
				Tools::Draw2Back(m_backcreate, str_obstacle, (i - 1) * 40, (j - 1) * 40, 'W');
			}
		}
	}
	ReBomb();
}

void System::Show()
{
	//m_robot->Draw2Back(m_backt);
	//m_player1->Draw2Back(m_backt);
	//cvShowImage("Face", m_backt);
}

bool System::IsSpace(int x, int y)
{
	if (m_Map[x][y] == -1)
		return true;
	else 
		return false;
}

bool System::IsWalk(CPlayer * p, char key)
{
	int x = 0, y = 0;
	if (key == 'w')
	{
		x = abs(p->m_PosX - p->m_Speed) / 40 + 1;
		y = p->m_PosY / 40 + 1;
	}
	else if (key == 'a')
	{
		x = p->m_PosX / 40 + 1;
		y = abs(p->m_PosY - p->m_Speed) / 40 + 1;
	}
	else if (key == 's')
	{
		x = (p->m_PosX + p->m_Speed) / 40 + 1;
		y = p->m_PosY / 40 + 1;
	}
	else if (key == 'd')
	{
		x = p->m_PosX / 40 + 1;
		y = (p->m_PosY + p->m_Speed) / 40 + 1;
	}
	
	if (IsSpace(x, y))
		return true;
	else
		return false;
}

void System::Run()
{
	while(1)
	{
		char key = cvWaitKey(500);
		//char key = ' ';
		if (key == '0')	break;
		else if (key == ' ')
		{
			CreateBomb(m_player1->m_PosX, m_player1->m_PosY);
		}
		if (IsWalk(m_player1, key))
			m_player1->Move(key);
		m_robot->Move(key);

		ReMap();
		cvCopy(m_backcreate, m_backt);
		m_player1->Draw2Back(m_backt);
		m_robot->Draw2Back(m_backt);
		cvShowImage("Face", m_backt);
	}
}
