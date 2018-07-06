#include "stdafx.h"
#include "System.h"


System::System()
{
	back0 = cvLoadImage("Pic\\back1.jpg");
	backcreate = cvCloneImage(back0);
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
		if (m_vect[i]->Rebomb(backcreate))
		{
			m_vect.erase(m_vect.begin() + i);
		}
	}
}

void System::ReMap()
{
	cvCopy(back0, backcreate);
	char str_obstacle[] = "Pic\\obstacle0.jpg";
	char str_stone[] = "Pic\\stone0.jpg";
	for (int i = 1; i <= m_Mapx; i++)
	{
		for (int j = 1; j <= m_Mapy; j++)
		{
			if (m_Map[i][j] >= 4)
			{
				str_stone[9] = '0' + m_Map[i][j] - 3;
				Tools::Draw2Back(backcreate, str_stone, (i - 1) * 40, (j - 1) * 40, 'W');
			}
			else if (m_Map[i][j] > 0)
			{
				str_obstacle[12] = '0' + m_Map[i][j];
				Tools::Draw2Back(backcreate, str_obstacle, (i - 1) * 40, (j - 1) * 40, 'W');
			}
		}
	}
	ReBomb();
}
