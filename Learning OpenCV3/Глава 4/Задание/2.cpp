#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	int size[2] = { 800, 800 };
	cv::Mat mat(2, size, 0);
	cv::Mat mat_float(2, size, CV_32F);
	cv::namedWindow("1", 6);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			mat.at<uchar>(i, j) = rand() % 255;
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			if (j == 0 && i == 0)
				mat_float.at<float>(0, 0) = mat.at<uchar>(0, 0);
			else if (i == 0)
				mat_float.at<float>(i, j) = mat.at<uchar>(i, j) + mat_float.at<float>(0, j - 1);
			else if (j == 0)
				mat_float.at<float>(i, j) = mat.at<uchar>(i, j) + mat_float.at<float>(i - 1, 0);
			else
				mat_float.at<float>(i, j) = mat.at<uchar>(i, j) + mat_float.at<float>(i - 1, j) + mat_float.at<float>(i, j - 1);

	cv::imshow("1", mat_float);
	char ch = cv::waitKey(INT_MAX);
	cv::destroyWindow("1");
	return 0;
}