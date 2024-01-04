#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(void)
{
	cv::namedWindow("Example 2_3", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open("The.Rookie.S01E01.1080p.rus.LostFilm.TV.mkv");

	cv::Mat frame;
	for (;;)
	{
		cap >> frame;
		if (frame.empty()) break;				// фильм кончился
		cv::imshow("Example 2_3", frame);
		if ((char)cv::waitKey(33) >= 0) break;
	}
	return 0;
}