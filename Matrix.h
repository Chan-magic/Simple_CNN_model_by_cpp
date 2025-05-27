#ifndef _MATRIX_H_
#define _MATRIX_H_
#include"face_binary_cls.cpp"
#include<iostream>
#include<vector>
#include<set>
using namespace std;

template<typename T>
class Matrix//矩阵类
{
public:
	int row;//行
	int col;//列
	vector<vector<T>> matrix;//矩阵本体
private:
	void checkshape(const Matrix<T>& other)const//检查是否可运算函数
	{
		if(row!=other.row||col!=other.col)
		throw std::runtime_error("errow");//矩阵加减数乘不匹配
	}
	void checkindex(const Matrix<T>& other)const//检查是否可运算函数
	{
		if(col!=other.row)
		throw std::runtime_error("errow");//矩阵乘法不匹配
	}
public:
	Matrix(const vector<vector<T>>& matrix0) :matrix(matrix0)//传入二维数组的构造函数
	{
		row=matrix.size();col=matrix[0].size();
		for(int i=1;i<row;i++)
		{
			if(matrix[i].size()!=col)throw std::runtime_error("矩阵不对");
		}
	}
	Matrix(const int& row0,const int& col0):row(row0),col(col0){matrix = vector<vector<T>>(row, vector<T>(col));}//传入行和列的构造函数
	Matrix() { row = 0; col = 0;matrix = vector<vector<T>>(row, vector<T>(col));}//默认构造函数
	vector<T>& operator[](const int& i) //快速访问  对象[i][j]
	{
		return matrix[i];
	}
	void display()//全打印
	{
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	Matrix<T> operator+(const Matrix& other)const//加法重载
	{
		checkshape(other);
		Matrix<T>temp(row,col);
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				temp.matrix[i][j]=matrix[i][j]+other.matrix[i][j];
			}
		}
		return temp;
	}
	Matrix<T> operator-(const Matrix& other)const//减法重载
	{
		checkshape(other);
		Matrix<T>temp(row,col);
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				temp.matrix[i][j]=matrix[i][j]-other.matrix[i][j];
			}
		}
		return temp;
	}
/*	Matrix<T> operator*(const Matrix& other)const//矩阵对应元素相乘返回矩阵
	{
		checkshape(other);
		Matrix<T>temp(row,col);
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				temp.matrix[i][j]=matrix[i][j]*other.matrix[i][j];
			}
		}
		return temp;
	}
*/
	long long operator*(const Matrix& other)const//矩阵对应元素相乘返回总和(卷积和结果)
	{
		checkshape(other);
		long long ans=0;
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				ans+=matrix[i][j]*other.matrix[i][j];
			}
		}
		return ans;
	}
	Matrix<T> operator^(const Matrix& other)const//矩阵乘法
	{
		checkindex(other);
		Matrix<T>temp(row,other.col);
		int i,j,k;
		for(i=0;i<temp.row;i++)
		{
			for(j=0;j<temp.col;j++)
			{
				for(k=0;k<col;k++)
				{
					temp.matrix[i][j]+=matrix[i][k]*other.matrix[k][j];
				}
			}
		}
		return temp;
	}
	Matrix<T> operator*(const double& other)const//矩阵在左数乘
	{
		Matrix<T>temp(row,col);
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				temp.matrix[i][j]=matrix[i][j]*other;
			}
		}
		return temp;
	}
};
template<typename T>
Matrix<T> operator*(const double& a,const Matrix<T>& other)//矩阵在右数乘
{
	Matrix<T>temp(other.row,other.col);
	int i,j;
	for(i=0;i<other.row;i++)
	{
		for(j=0;j<other.col;j++)
		{
			temp.matrix[i][j]=other.matrix[i][j]*a;
		}
	}
	return temp;
}

//int main()
//{
//	vector<vector<double>>arr={
//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
//	};
//	vector<vector<int>>arr1={
//		{1,2,3},
//		{4,5,6},
//	};
//	Matrix<double> test(arr);
//	Matrix<int> t1(arr1);
//	//Matrix<double> te=2.1*test;
//	//te.display();
//	Matrix<int> aaa;
//	cout<<test[2][2];
//	
//	return 0;
//}
#endif
