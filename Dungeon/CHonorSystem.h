#pragma once

class CHonorSystem
{
public:
	CHonorSystem();
	~CHonorSystem();
	int m_HonorHealthG;//生命值等级
	int m_HonorManaG;//生命值等级
	int m_HonorDamageG;//攻击力等级
	int m_HonorArmorG;//防御力等级
	IplImage* m_HonorMenu;//荣誉界面图片

	static void HonRun(IplImage* back);//运行
	void DrawMenu();
};

