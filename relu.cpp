#ifndef _RELU_H_
#define _RELU_H_
#include"Matrix.h"

vector<vector<vector<float>>>& relu(vector<vector<vector<float>>>& pic)
{
	int i,j,k;
	for(k=0;k<pic.size();k++)
	{
		for(i=0;i<pic[0].size();i++)
		{
			for(j=0;j<pic[0][0].size();j++)
			{
				pic[k][i][j]=max(0.0f,pic[k][i][j]);
			}
		}
	}
	return pic;
}

#endif
