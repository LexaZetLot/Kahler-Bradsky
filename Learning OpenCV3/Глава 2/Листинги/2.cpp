#include <opencv2/highgui/highgui.hpp> 

using namespace cv;

int main(int argc, char** argv)
{

	Mat img = cv::imread("Screenshot_1.png", -1);

	if (img.empty()) return -1;

	namedWindow("Example1", WINDOW_AUTOSIZE);
	imshow("Example1", img);
	waitKey(0);

	destroyWindow("Example1");
}