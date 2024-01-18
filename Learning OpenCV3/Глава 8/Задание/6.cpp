#include <opencv2/opencv.hpp>
#include <iostream>

int g_x;
int g_y;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);


int main(void)
{
	char ch;
	std::vector <cv::Mat> arr_mat;
	std::string str;
	cv::Mat mat(cv::Size(800, 800), CV_8UC3);
	cv::namedWindow("1");

	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		cv::imshow("1", mat);

		if (flag_mouse == 1)
		{
			arr_mat.push_back(mat.clone());
			cv::line(mat, cv::Point(g_x, g_y), cv::Point(g_x, g_y), cv::Scalar(254.0, 254.0, 254.0), 6);
			std::cin >> str;
			cv::putText(mat, str, cv::Point(g_x + 2, g_y - 5), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
			flag_mouse = 0;
		}
		ch = (char)cv::waitKey(33);
		if (ch == 27)
			break;
		else if (ch == 8)
		{
			mat = arr_mat.back();
			arr_mat.pop_back();
		}
	}

	return 0;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	g_x = x;
	g_y = y;
	if (event == cv::EVENT_LBUTTONDOWN)
		flag_mouse++;
}