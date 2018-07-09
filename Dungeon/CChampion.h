#pragma once
#include "CRole.h"
class CChampion :
	public CRole
{
protected:
public:
	CChampion();
	~CChampion();

	int m_Mana;//法力值 英雄特有

	IplImage* m_Face;//脸部图片
	IplImage* m_Weapon;//武器图片
	IplImage* m_Minor;//盾牌图片
	IplImage* m_Block;//边框图片

	int GetFaceRow();//计算面部纵向像素坐标
	int GetFaceCol();//计算面部横向像素坐标
	int GetBodyRow();//计算面部纵向像素坐标
	int GetBodyCol();//计算面部横向像素坐标
	int GetWeaponRow();//计算武器纵向像素坐标
	int GetWeaponCol();//计算武器横向像素坐标
	int GetMinorRow();//计算盾牌纵向像素坐标
	int GetMinorCol();//计算盾牌横向像素坐标
	int GetBlockRow();//计算边框纵向像素坐标
	int GetBlockCol();//计算边框横向像素坐标

};

