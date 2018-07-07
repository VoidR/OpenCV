#pragma once
class CChampion
{
protected:
public:
	CChampion();
	~CChampion();
	int m_iRow;//纵向坐标
	int m_iCol;//横向坐标
	int m_Health;//生命值
	int m_Mana;//法力值
	int m_Damage;//伤害
	int m_Armor;//护甲

	IplImage* m_Face;//脸部图片
	IplImage* m_Body;//身体图片
	IplImage* m_Weapon;//武器图片
	IplImage* m_Minor;//盾牌图片
	IplImage* m_Frame;//边框图片

	int GetFaceRow();//计算面部纵向像素坐标
	int GetFaceCol();//计算面部横向像素坐标
	int GetBodyRow();//计算身体纵向像素坐标
	int GetBodyCol();//计算身体横向像素坐标
	int GetWeaponRow();//计算面部纵向像素坐标
	int GetWeaponCol();//计算面部横向像素坐标
	int GetMinorRow();//计算身体纵向像素坐标
	int GetMinorCol();//计算身体横向像素坐标
	int GetFrameRow();//计算身体纵向像素坐标
	int GetFrameCol();//计算身体横向像素坐标

	void Move(char key);//移动
};

