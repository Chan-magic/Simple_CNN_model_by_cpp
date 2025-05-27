#ifndef _POOL_CPP_
#define _POOL_CPP_
#include"matrix.h"

vector<vector<vector<float>>> pool(vector<vector<vector<float>>>& pic,int param)
{
	int row=pic[0].size()/param,col=pic[0][0].size()/param;
	vector<vector<vector<float>>> vec(pic.size(),vector<vector<float>>(row,vector<float>(col,-10000.0f)));
	int i,j,k,s,t;
	for(k=0;k<pic.size();k++)
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				for(s=0;s<param;s++)
				{
					for(t=0;t<param;t++)
					{
						vec[k][i][j]=max(vec[k][i][j],pic[k][i*param+s][j*param+t]);
					}
				}
			}
		}
	}
	return vec;
}

#endif
