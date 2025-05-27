#ifndef _FLATTEN_CPP_
#define _FLATTEN_CPP_
#include"Matrix.h"

vector<float> flatten(vector<vector<vector<float>>>& pic)
{
	int i,j,k;
	vector<float> vec(pic.size()*pic[0].size()*pic[0][0].size(),0.0f);
	for(k=0;k<pic.size();k++)
	{
		for(i=0;i<pic[0].size();i++)
		{
			for(j=0;j<pic[0][0].size();j++)
			{
				vec[k*pic[0][0].size()*pic[0].size()+i*pic[0][0].size()+j]=pic[k][i][j];
			}
		}
	}
	return vec;
}



#endif
