#pragma once

class CHonorSystem
{
public:
	CHonorSystem();
	~CHonorSystem();
	int m_HonorHealthG;//����ֵ�ȼ�
	int m_HonorManaG;//����ֵ�ȼ�
	int m_HonorDamageG;//�������ȼ�
	int m_HonorArmorG;//�������ȼ�
	IplImage* m_HonorMenu;//��������ͼƬ

	static void HonRun(IplImage* back);//����
	void DrawMenu();
};

