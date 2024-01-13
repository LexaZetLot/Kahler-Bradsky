#include <opencv2/opencv.hpp>

using namespace std;

int g_x;
int g_y;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void form_str(std::string& str, cv::Vec3b vec);

int main(void)
{
	cv::VideoCapture cap;
	cv::Mat full;
	cv::Mat full_buf;
	cv::Mat mat1;
	cv::Mat mat2;
	cv::Mat mat3;
	cv::Mat gray_mat;
	cv::Mat canny_mat;
	cv::Vec3b vec;
	std::string str;
	std::vector <cv::Mat> arr;
	cap.open(0);

	cv::namedWindow("1", 1);

	for (;;)
	{
		cap >> mat1;
		cv::setMouseCallback("1", CallBackFunc, NULL);

		cv::cvtColor(mat1, gray_mat, cv::COLOR_BGR2GRAY);
		arr.push_back(gray_mat);
		arr.push_back(gray_mat);
		arr.push_back(gray_mat);
		cv::merge(arr, mat2);
		arr.clear();


		cv::Canny(gray_mat, canny_mat, 0, 350);
		arr.push_back(canny_mat);
		arr.push_back(canny_mat);
		arr.push_back(canny_mat);
		cv::merge(arr, mat3);
		arr.clear();


		arr.push_back(mat1);
		arr.push_back(mat2);
		arr.push_back(mat3);
		cv::hconcat(arr, full);
		arr.clear();
		cv::putText(full, "Normal", cv::Point(5, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(full, "Monochrome", cv::Point(5 + mat1.cols, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(full, "Canny", cv::Point(5 + mat1.cols * 2, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));

		if (flag_mouse == 1)
		{
			vec = full.at<cv::Vec3b>(g_x, g_y);
			form_str(str, vec);
			full.copyTo(full_buf);
			cv::putText(full, str, cv::Point(g_x, g_y), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(0.0, 128.0, 0.0));
			cv::imshow("1", full);
			full_buf.copyTo(full);
			cv::waitKey(1000);
			flag_mouse = 0;

		}
		else
			cv::imshow("1", full);

		if ((char)cv::waitKey(33) == 27)
			break;
	}
	return 0;
}

void form_str(std::string& str, cv::Vec3b vec)
{
	str.clear();
	char st[6];
	snprintf(st, sizeof(st), "%u, ", vec[0]);
	str += st;
	snprintf(st, sizeof(st), "%u, ", vec[1]);
	str += st;
	snprintf(st, sizeof(st), "%u", vec[2]);
	str += st;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	g_x = x;
	g_y = y;
	if (event == cv::EVENT_LBUTTONDOWN)
		flag_mouse++;
}