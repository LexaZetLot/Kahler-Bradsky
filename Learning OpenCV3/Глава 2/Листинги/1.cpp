#include <opencv2/opencv.hpp> // заголовок, подт€гивающий все функции OpenCV

int main(int argc, char** argv)
{

	cv::Mat img = cv::imread("Screenshot_1.png", -1);

	if (img.empty()) return -1;

	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example1", img);
	cv::waitKey(0);
	cv::destroyWindow("Example1");

	return 0;
}