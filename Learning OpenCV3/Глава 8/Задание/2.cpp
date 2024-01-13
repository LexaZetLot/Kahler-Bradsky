#include <opencv2/opencv.hpp>

using namespace std;

int g_x;
int g_y;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void form_str(std::string& str, cv::Vec3b vec);

int main(void)
{
	unsigned char b = 0;
	unsigned char g = 0;
	unsigned char r = 0;
	char st[5];
	std::string str;
	cv::Vec3b vec;
	cv::Mat mat = cv::imread("test1.jpg");
	cv::Mat mat_buf;
	cv::namedWindow("1", 1);


	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		if (flag_mouse == 1)
		{
			vec = mat.at<cv::Vec3b>(g_x, g_y);
			form_str(str, vec);
			mat.copyTo(mat_buf);
			cv::putText(mat, str, cv::Point(g_x, g_y), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(0.0, 0.0, 0.0));
			cv::imshow("1", mat);
			cv::waitKey(1000);
			mat_buf.copyTo(mat);
			flag_mouse = 0;
		}
		cv::imshow("1", mat);
		if ((char)cv::waitKey(33) == 27)
			break;
	}
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