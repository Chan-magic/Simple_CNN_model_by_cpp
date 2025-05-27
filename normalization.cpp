#ifndef _NORMALIZATION_CPP_
#define _NORMALIZATION_CPP_
#include"Matrix.h"

//vector<vector<vector<float>>>& normalization(vector<vector<vector<float>>>& vec,float param)
//{
//	int i,j,k;
//	for(k=0;k<vec.size();k++)
//	{
//		for(i=0;i<vec[0].size();i++)
//		{
//			for(j=0;j<vec[0][0].size();j++)
//			{
//				vec[k][i][j]/=param;
//			}
//		}
//	}
//	return vec;
//}

vector<vector<vector<float>>>& normalization(vector<vector<vector<float>>>& vec)
{
	int i,j,k;
	float maxn=-100000;
	for(k=0;k<vec.size();k++)
	{
		for(i=0;i<vec[0].size();i++)
		{
			for(j=0;j<vec[0][0].size();j++)
			{
				maxn=max(vec[k][i][j],maxn);
			}
		}
	}
	for(k=0;k<vec.size();k++)
	{
		for(i=0;i<vec[0].size();i++)
		{
			for(j=0;j<vec[0][0].size();j++)
			{
				vec[k][i][j]/=maxn;
			}
		}
	}
	return vec;
}


#endif
