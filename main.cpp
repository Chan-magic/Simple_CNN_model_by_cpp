#include"conv.cpp"
#include"relu.cpp"
#include"pool.cpp"
#include"normalization.cpp"
#include"flatten.cpp"
#include"connection.cpp"
#include<opencv2/opencv.hpp>
#include <cmath>
using namespace cv;

void print(vector<vector<vector<float>>>& vec)
{
	int i, j, k;
	for (i = 0; i < vec.size(); i++)
	{
		for (j = 0; j < vec[0].size(); j++)
		{
			for (k = 0; k < vec[0][0].size(); k++)
			{
				cout << vec[i][j][k]  << endl;
			}
			//cout << endl;
		}
	}
}

void print(vector<float>& vec)
{
	int i;
	for (i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

void softmax(float output[2]) {
	float max_val = std::max(output[0], output[1]); // 找到最大值以提高数值稳定性
	float exp_sum = 0.0f;

	// 计算指数和
	for (int i = 0; i < 2; ++i) {
		output[i] = std::exp(output[i] - max_val);
		exp_sum += output[i];
	}

	// 计算概率
	for (int i = 0; i < 2; ++i) {
		output[i] /= exp_sum;
	}
}

void fully_connected(const std::vector<float>& input, const fc_param& param, float* output) {
	for (int o = 0; o < param.out_features; ++o) {
		output[o] = 0.0f; // 初始化输出
		for (int i = 0; i < param.in_features; ++i) {
			// 计算矩阵乘法：output[o] += weight[o][i] * input[i]
			output[o] += param.p_weight[o * param.in_features + i] * input[i];
		}
		// 加上偏置
		output[o] += param.p_bias[o];
	}
}

int main()
{
	Mat image = imread("pic3.jpg");
	int row = image.rows; // 图片的行数
	int col = image.cols; // 图片的列数
	int channel = image.channels(); // 图片的通道数（RGB为3）
	vector<vector<vector<float>>> pic(channel,vector<vector<float>>(row,vector<float>(col)));
	//for (int i = 0; i < row; ++i) 
	//{
	//	for (int j = 0; j < col; ++j) 
	//	{
	//		for (int k = 0; k < channel; ++k)
	//		{
	//			pic[k][i][j] = static_cast<float>(image.at<cv::Vec3b>(i, j)[k]);
	//		}
	//	}
	//}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			Vec3b pixel = image.at<Vec3b>(r, c);
			// 将BGR通道按顺序存储为B、G、R
			pic[0][r][c] = pixel[0]; // B通道
			pic[1][r][c] = pixel[1]; // G通道
			pic[2][r][c] = pixel[2]; // R通道
		}
	}
	normalization(pic);
	vector<vector<vector<float>>> pic1=conv(pic, conv_params[0]);	
	relu(pic1);
	vector<vector<vector<float>>> pic1_=pool(pic1,2);
	//print(pic1_);
	//normalization(pic1_);

	vector<vector<vector<float>>> pic2 = conv(pic1_, conv_params[1]);
	relu(pic2);
	vector<vector<vector<float>>> pic2_ = pool(pic2, 2);
	//print(pic2_);
	//normalization(pic2_);

	vector<vector<vector<float>>> pic3 = conv(pic2_, conv_params[2]);
	relu(pic3);
	//print(pic3);
	vector<float> vec = flatten(pic3);
	//print(vec);
	//vector<float> ans = connection(vec, fc_params[0]);
	//cout << ans[0] << endl << ans[1] << endl;

	float output[2] = { 0.0f };
	fully_connected(vec, fc_params[0], output);
	softmax(output);
	std::cout << "FC Output: [" << output[0] << ", " << output[1] << "]" << std::endl;

	return 0;
}
//namedWindow("666");
//imshow("666", img);
//waitKey(1000);