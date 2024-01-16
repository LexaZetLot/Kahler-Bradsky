#include <opencv2/opencv.hpp>
#include <math.h>

int g_x;
int g_y;
int g_position = 0;
int g_flag_position = 0;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void TrackbarSlide(int pos, void*);

int main(void)
{
	std::vector<cv::Point> arr_point;
	std::vector<cv::Mat> arr_mat;
	cv::Mat mat = cv::Mat(cv::Size(800, 800), CV_8UC3);
	cv::Point start;
	cv::Point end;
	char ch;
	cv::namedWindow("1");

	cv::createTrackbar("Position", "1", &g_position, 3, TrackbarSlide);
	cv::imshow("1", mat);
	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		cv::setTrackbarPos("Position", "1", g_flag_position);
		switch (g_flag_position)
		{
		case 0:
			if (flag_mouse == 1)
			{
				start = cv::Point(g_x, g_y);
				flag_mouse = 0;
			}
			else if (flag_mouse == 2)
			{
				arr_mat.push_back(mat.clone());
				end = cv::Point(g_x, g_y);
				cv::line(mat, start, end, cv::Scalar(254.0, 254.0, 254.0), 6);
				flag_mouse = 0;
				cv::imshow("1", mat);
			}
			else if (flag_mouse == 3)
				flag_mouse = 0;
			break;
		case 1:
			if (flag_mouse == 1)
			{
				start = cv::Point(g_x, g_y);
				flag_mouse = 0;
			}
			else if (flag_mouse == 2)
			{
				arr_mat.push_back(mat.clone());
				end = cv::Point(g_x, g_y);
				cv::circle(mat, start, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), cv::Scalar(254.0, 254.0, 254.0), 6);
				flag_mouse = 0;
				cv::imshow("1", mat);
			}
			else if (flag_mouse == 3)
				flag_mouse = 0;
			break;
		case 2:
			if (flag_mouse == 1)
			{
				start = cv::Point(g_x, g_y);
				flag_mouse = 0;
			}
			else if (flag_mouse == 2)
			{
				arr_mat.push_back(mat.clone());
				end = cv::Point(g_x, g_y);
				cv::ellipse(mat, start, cv::Size(abs(start.x - end.x), abs(start.y - end.y)), 0.0, 0.0, 360.0, cv::Scalar(254.0, 254.0, 254.0), 6);
				flag_mouse = 0;
				cv::imshow("1", mat);
			}
			else if (flag_mouse == 3)
				flag_mouse = 0;
			break;
		case 3:
			if (flag_mouse == 1)
			{
				start = cv::Point(g_x, g_y);
				arr_point.push_back(start);
				flag_mouse = 0;
			}
			else if (flag_mouse == 2)
				flag_mouse = 0;
			else if (flag_mouse == 3)
			{
				arr_mat.push_back(mat.clone());
				end = cv::Point(g_x, g_y);
				cv::fillConvexPoly(mat, arr_point.data(), 6, cv::Scalar(254.0, 254.0, 254.0));
				flag_mouse = 0;
				arr_point.clear();
				cv::imshow("1", mat);
			}
			break;
		}
		ch = (char)cv::waitKey(10);
		if (ch == 27)
			break;
		else if (ch == 'z')
		{
			mat = arr_mat.back();
			arr_mat.pop_back();
			cv::imshow("1", mat);
		}
	}
	return 0;
}

void TrackbarSlide(int pos, void*)
{
	g_flag_position = pos;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	g_x = x;
	g_y = y;
	if (event == cv::EVENT_LBUTTONDOWN)
		flag_mouse++;
	else if (event == cv::EVENT_LBUTTONUP)
		flag_mouse += 2;
	else if (event == cv::EVENT_RBUTTONDOWN)
		flag_mouse += 3;
}