#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::namedWindow("Example 2_10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(0);				// ������� ������ ������

	if (!cap.isOpened())		// ������ ����?
	{
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;
	for (;;)
	{
		cap >> frame;
		if (frame.empty()) break;
		cv::imshow("Example 2_10", frame);
		if ((char)cv::waitKey(33) >= 0) break;
	}
	return 0;

}