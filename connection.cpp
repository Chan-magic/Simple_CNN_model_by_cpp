#ifndef _CONNECTION_CPP_
#define _CONNECTION_CPP_
#include"Matrix.h"

//Matrix<float> connection(vector<float>& pic,fc_param& fc)
//{
//	Matrix<float> l(fc.out_features,fc.in_features);
//	Matrix<float> r(pic.size(),1);
//	int i,j;
//	for(i=0;i<pic.size();i++)
//	{
//		r[i][0]=pic[i];
//	}
//	for(i=0;i<fc.out_features;i++)
//	{
//		for(j=0;j<fc.in_features;j++)
//		{
//			l[i][j]=fc.p_weight[i*fc.in_features+j];
//		}
//	}
//	Matrix ans=l^r;
//	ans[0][0]+=fc.p_bias[0];
//	ans[1][0]+=fc.p_bias[1];
//	return ans;
//}

vector<float> connection(vector<float>& pic,fc_param& fc)
{
	vector<float> vec(2,0.0f);
	int i,j;
	for(i=0;i<pic.size();i++)
	{
		vec[0]+=(double)pic[i]*fc.p_bias[i];
	}
	//vec[0]+=fc.p_weight[0];
	for(i=0;i<pic.size();i++)
	{
		vec[1]+=(double)pic[i]*fc.p_bias[2048+i];
	}
	//vec[1]+=fc.p_weight[1];
	return vec;
}

#endif
