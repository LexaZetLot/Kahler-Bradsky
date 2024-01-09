#include <opencv2/opencv.hpp>
#include "function.h"
#include <iostream>

int main(void)
{
	int size[2] = { MAX_SIZE_Y, MAX_SIZE_X };
	cv::Mat mat(2, size, 0);
	cv::namedWindow("1", 1);
	char c;
	for (;;)
	{
		cv::imshow("1", mat);
		char ch = cv::waitKey(INT_MAX);
		if (!print(mat, ch))
			break;
	}
	cv::destroyWindow("1");
	return 0;
}