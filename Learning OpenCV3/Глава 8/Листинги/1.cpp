#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;


int main(void)
{
	cv::VideoCapture cap("test1.mkv");

	unsigned f = (unsigned)cap.get(cv::CAP_PROP_FOURCC);

	char fourcc[] = {
	  (char)f,							// First character is lowest bits
	  (char)(f >> 8),					// Next character is bits 8-15
	  (char)(f >> 16),					// Next character is bits 16-23
	  (char)(f >> 24),					// Last character is bits 24-31
	  '\0'								// and don't forget to terminate
	};

	cout << "FourCC for this video was: " << fourcc << endl;

	return 0;
}