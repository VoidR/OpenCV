#pragma once
class CRole
{
public:
	CRole();
	~CRole();
	CvPoint m_Pos;//坐标
	int m_Health;//生命值
	int m_Damage;//伤害
	int m_Armor;//护甲

	int m_BasicHealth;//基础生命值
	int m_BasicDamage;//基础伤害
	int m_BasicArmor;//基础护甲

	IplImage* m_Body;//身体图片

	virtual int GetBodyRow() = 0;//计算身体纵向像素坐标
	virtual int GetBodyCol() = 0;//计算身体横向像素坐标
	virtual int GetBlockRow() = 0;//计算边框纵向像素坐标
	virtual int GetBlockCol() = 0;//计算边框横向像素坐标

	void Move(char key);//移动
	void RePos(CvPoint next);//修改坐标
	int Hurt(int damage);//受到伤害
};

