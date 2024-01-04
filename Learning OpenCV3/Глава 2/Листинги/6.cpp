#include <opencv2/opencv.hpp>

int main(void)
{
	cv::Mat img1, img2;

	cv::namedWindow("Example 2_6-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example 2_6-out", cv::WINDOW_AUTOSIZE);

	img1 = cv::imread("Screenshot_1.png");
	cv::imshow("Example 2_6-in", img1);

	cv::pyrDown(img1, img2);
	cv::imshow("Example 2_6-out", img2);

	cv::waitKey(0);



	return 0;
}