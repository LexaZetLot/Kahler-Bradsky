#include <opencv2/opencv.hpp>
#include <math.h>

int g_x;
int g_y;
int g_position = 0;
int g_position_1 = 0;
int g_flag_position = 0;
int g_flag_position_1 = 0;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void TrackbarSlide(int pos, void*);
void TrackbarSlidebit(int pos, void*);


int main(void)
{
	std::vector<cv::Point> arr_point;
	std::vector<cv::Mat> arr_mat;
	cv::Mat mat = cv::Mat(cv::Size(800, 800), CV_8UC3);
	cv::Mat mat_bufer = cv::Mat(cv::Size(800, 800), CV_8UC3);
	cv::Point start;
	cv::Point end;
	char ch;
	cv::namedWindow("1");

	cv::createTrackbar("Position", "1", &g_position, 3, TrackbarSlide);
	cv::createTrackbar("Position1", "1", &g_position_1, 3, TrackbarSlidebit);
	cv::imshow("1", mat);
	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		cv::setTrackbarPos("Position", "1", g_flag_position);
		cv::setTrackbarPos("Position1", "1", g_flag_position_1);

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
				switch (g_flag_position_1)
				{
				case 0:
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::line(mat, start, end, cv::Scalar(254.0, 254.0, 254.0), 6);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 1:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::line(mat_bufer, start, end, cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_and(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 2:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::line(mat_bufer, start, end, cv::Scalar(254.0, 254.0, 0.0), 6);
					cv::bitwise_or(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 3:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::line(mat_bufer, start, end, cv::Scalar(254.0, 254.0, 0.0), 6);
					cv::bitwise_xor(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				}
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
				switch (g_flag_position_1)
				{
				case 0:
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::circle(mat, start, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), cv::Scalar(254.0, 254.0, 254.0), 6);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 1:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::circle(mat_bufer, start, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_and(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 2:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::circle(mat_bufer, start, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_or(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 3:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::circle(mat_bufer, start, sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)), cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_xor(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				}
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
				switch (g_flag_position_1)
				{
				case 0:
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::ellipse(mat, start, cv::Size(abs(start.x - end.x), abs(start.y - end.y)), 0.0, 0.0, 360.0, cv::Scalar(254.0, 254.0, 254.0), 6);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 1:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::ellipse(mat_bufer, start, cv::Size(abs(start.x - end.x), abs(start.y - end.y)), 0.0, 0.0, 360.0, cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_and(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 2:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::ellipse(mat_bufer, start, cv::Size(abs(start.x - end.x), abs(start.y - end.y)), 0.0, 0.0, 360.0, cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_or(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				case 3:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::ellipse(mat_bufer, start, cv::Size(abs(start.x - end.x), abs(start.y - end.y)), 0.0, 0.0, 360.0, cv::Scalar(254.0, 254.0, 254.0), 6);
					cv::bitwise_xor(mat, mat_bufer, mat);
					flag_mouse = 0;
					cv::imshow("1", mat);
					break;
				}
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
				switch (g_flag_position_1)
				{
				case 0:
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::fillConvexPoly(mat, arr_point.data(), 6, cv::Scalar(254.0, 254.0, 254.0));
					flag_mouse = 0;
					arr_point.clear();
					cv::imshow("1", mat);
					break;
				case 1:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::fillConvexPoly(mat_bufer, arr_point.data(), 6, cv::Scalar(254.0, 254.0, 254.0));
					cv::bitwise_and(mat, mat_bufer, mat);
					flag_mouse = 0;
					arr_point.clear();
					cv::imshow("1", mat);
					break;
				case 2:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::fillConvexPoly(mat_bufer, arr_point.data(), 6, cv::Scalar(254.0, 254.0, 254.0));
					cv::bitwise_or(mat, mat_bufer, mat);
					flag_mouse = 0;
					arr_point.clear();
					cv::imshow("1", mat);
					break;
				case 3:
					mat_bufer = mat.clone();
					arr_mat.push_back(mat.clone());
					arr_mat.push_back(mat.clone());
					end = cv::Point(g_x, g_y);
					cv::fillConvexPoly(mat_bufer, arr_point.data(), 6, cv::Scalar(254.0, 254.0, 254.0));
					cv::bitwise_xor(mat, mat_bufer, mat);
					flag_mouse = 0;
					arr_point.clear();
					cv::imshow("1", mat);
					break;
				}
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

void TrackbarSlidebit(int pos, void*)
{
	g_flag_position_1 = pos;
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