// Fun.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//竖切
int main()
{
	Cut f;
	Resize s;
	char str[] = "player10.png";
	//f.heng(str, 3, 0);
	//f.shu(str, 1, 0);
	for (int i = 0; i <= 5; i++)
	{
		str[7] = '0' + i;
		s.size(str,i);
		//waitKey();
	}
	return 0;
}
 
