#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
	int irow=16+2;
	int icol=900/40+2;
	int MAP[18][24];
	for(int i=0;i<=irow-1;i++)
	{
		for(int j=0;j<=23;j++)
		{
			if(i==0||i==17||j==0||j==23)
				MAP[i][j]=0;
			else MAP[i][j]=-1;
		}
		int a=1;
	}
	ofstream out;
	out.open("map.txt");
	if (out.is_open())
	{
		for(int i=0;i<=17;i++)
	 	{
	 		for(int j=0;j<=23;j++)
				out<<MAP[i][j]<<"\t";
			out<<endl;
		}
		out.close();
	}
	
	return 0;
}
