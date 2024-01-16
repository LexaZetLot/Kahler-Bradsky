#include <opencv2/opencv.hpp>

cv::VideoCapture g_vid;
int g_slider_position = 0;
int g_paus = 0;
int g_flag_paus = 0;
void onTrackbarSlide(int pos, void*)
{
	g_vid.set(cv::CAP_PROP_POS_FRAMES, pos);
}
void pausTrackbarSlide(int pos, void*)
{
	if (pos == 0)
		g_flag_paus = 0;
	else
		g_flag_paus = 1;
}
int main(void)
{
	cv::Mat mat;
	g_vid.open("test1.mkv");
	cv::namedWindow("1", cv::WINDOW_AUTOSIZE);

	cv::createTrackbar("Position", "1", &g_slider_position, (int)g_vid.get(cv::CAP_PROP_FRAME_COUNT), onTrackbarSlide);
	cv::createTrackbar("Position1", "1", &g_paus, 1, pausTrackbarSlide);
	for (;;)
	{
		if (g_flag_paus == 1)
		{
			g_vid >> mat;

			cv::imshow("1", mat);
		}
		int current_pos = (int)g_vid.get(cv::CAP_PROP_POS_FRAMES);
		cv::setTrackbarPos("Position", "1", current_pos);
		cv::setTrackbarPos("Position1", "1", g_flag_paus);
		if ((char)cv::waitKey(10) == 27)
			break;

	}
	return 0;
}

