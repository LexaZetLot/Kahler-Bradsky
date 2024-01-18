#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>

int g_x;
int g_y;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);

int main(void)
{
	int flag_clik = 0;
	char ch;
	int size = 1;
	std::vector<cv::Point2f> vec_point_f_in;
	std::vector<cv::Point2f> vec_point_f_ot;
	cv::Mat mat_in = cv::imread("test2.jpg");
	cv::Mat mat_ot;
	cv::Mat M;
	cv::namedWindow("1");
	cv::namedWindow("2");

	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		cv::imshow("1", mat_in);

		if (flag_mouse == 1 && flag_clik < 4)
		{
			vec_point_f_in.push_back(cv::Point2f(g_x, g_y));
			flag_clik++;
			flag_mouse = 0;
		}

		if (flag_clik == 4)
		{
			vec_point_f_ot.push_back(cv::Point2f(0, 0));
			vec_point_f_ot.push_back(cv::Point2f(0, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, 0));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			M = cv::getPerspectiveTransform(vec_point_f_in.data(), vec_point_f_ot.data());
			cv::warpPerspective(mat_in, mat_ot, M, cv::Size(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			cv::imshow("2", mat_ot);
			flag_clik = 0;
		}
		ch = (char)cv::waitKey(33);
		if (ch == 27)
			break;
		if (ch >= 48 && ch <= 57)
		{
			size = (int)ch - 48;
			ch = 0;
		}
		if (ch == 'z')
		{
			vec_point_f_ot.clear();
			vec_point_f_ot.push_back(cv::Point2f(0, 0));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, 0));
			vec_point_f_ot.push_back(cv::Point2f(0, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			M = cv::getPerspectiveTransform(vec_point_f_in.data(), vec_point_f_ot.data());
			cv::warpPerspective(mat_in, mat_ot, M, cv::Size(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			cv::imshow("2", mat_ot);
		}
		else if (ch == 'x')
		{
			vec_point_f_ot.clear();
			vec_point_f_ot.push_back(cv::Point2f(0, 0));
			vec_point_f_ot.push_back(cv::Point2f(0, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, 0));
			vec_point_f_ot.push_back(cv::Point2f(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			M = cv::getPerspectiveTransform(vec_point_f_in.data(), vec_point_f_ot.data());
			cv::warpPerspective(mat_in, mat_ot, M, cv::Size(sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[2].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[2].y), 2)) * size, sqrt(pow(abs(vec_point_f_in[0].x - vec_point_f_in[1].x), 2) + pow(abs(vec_point_f_in[0].y - vec_point_f_in[1].y), 2)) * size));
			cv::imshow("2", mat_ot);
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