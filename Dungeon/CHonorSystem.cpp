#include "stdafx.h"
#include "CHonorSystem.h"


CHonorSystem::CHonorSystem()
{
	m_HonorHealthG = 0;
	m_HonorManaG = 0;
	m_HonorDamageG = 0;
	m_HonorArmorG = 0;
	m_HonorMenu = cvLoadImage("Pic\\honro.png");
}


CHonorSystem::~CHonorSystem()
{
}

void CHonorSystem::HonRun(IplImage* back)
{
}

void CHonorSystem::DrawMenu()
{
}
