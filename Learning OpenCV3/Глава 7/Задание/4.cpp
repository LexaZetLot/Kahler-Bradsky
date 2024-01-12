#include <opencv2/opencv.hpp>

int main(void)
{
	float arr[2][3] = { {1, 1, 0}, {1, -1, 1} };
	int size[2] = { 2, 3 };
	cv::SVD svd = cv::SVD();
	cv::Mat mat(cv::Size(2, 3), CV_32F, arr);
	cv::Mat U;
	cv::Mat W;
	cv::Mat Vt;

	svd.compute(mat, U, W, Vt);

	return 0;
}