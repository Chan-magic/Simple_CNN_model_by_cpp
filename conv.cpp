#ifndef _CONV_H_
#define _CONV_H_
#include"Matrix.h"

vector<vector<vector<float>>> convolution(vector<vector<vector<float>>>& other,int pad)
{
	vector<vector<vector<float>>>vec(other.size(),vector<vector<float>>(other[0].size()+pad*2,vector<float>(other[0][0].size()+pad*2,0.0f)));
	int i,j,l;
	for(l=0;l<vec.size();l++)
	{
		for(i=pad;i<vec[0].size()-pad;i++)
		{
			for(j=pad;j<vec[0][0].size()-pad;j++)
			{
				vec[l][i][j]=other[l][i-pad][j-pad];
			}
		}
	}
	return vec;
}

vector<vector<vector<float>>> conv(vector<vector<vector<float>>>& pic0,conv_param& con)
{
	vector<vector<vector<float>>> pic=convolution(pic0,con.pad);
	int row=(pic[0].size()-con.kernel_size)/con.stride+1,col=(pic[0][0].size()-con.kernel_size)/con.stride+1;
	vector<vector<vector<float>>> vec(con.out_channels,vector<vector<float>>(row,vector<float>(col, 0.0f)));
	int i,j,k,l,s,t;
	int k0=con.kernel_size*con.kernel_size*con.in_channels,l0=con.kernel_size*con.kernel_size;
	for(l=0;l<con.in_channels;l++)
	{
		for(k=0;k<con.out_channels;k++)
		{
			vector<vector<float>>kernel(con.kernel_size,vector<float>(con.kernel_size,0.0f));
			for(i=0;i<con.kernel_size;i++)
			{
				for(j=0;j<con.kernel_size;j++)
				{
					kernel[i][j]=con.p_weight[k*k0+l*l0+i*con.kernel_size+j];
				}
			}
			for(s=0;s<row;s++)
			{
				for(t=0;t<col;t++)
				{
					for(i=0;i<con.kernel_size;i++)
					{
						for(j=0;j<con.kernel_size;j++)
						{
							vec[k][s][t]+=kernel[i][j]*pic[l][s*con.stride+i][t*con.stride+j];
						}
					}
				}
			}
		}
	}
	for(k=0;k<con.out_channels;k++)
	{
		for(s=0;s<row;s++)
		{
			for(t=0;t<col;t++)
			{
				vec[k][s][t]+=con.p_bias[k];
			}
		}
	}
	return vec;
}

#endif
