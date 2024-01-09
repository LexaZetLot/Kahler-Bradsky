// alphablend <imageA> <image B> <x> <y> <<alpha> <beta>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
    cv::Mat src1 = cv::imread(argv[1], 1);
    cv::Mat src2 = cv::imread(argv[2], 1);

    int from_w = src1.size().width;
    int from_h = src1.size().height;
    int to_w = src2.size().width;
    int to_h = src2.size().height;

    if (argc == 9 && !src1.empty() && !src2.empty())
    {
        int x = atoi(argv[3]);
        int y = atoi(argv[4]);
        int w = atoi(argv[5]);
        int h = atoi(argv[6]);
        double alpha = (double)atof(argv[7]);
        double beta = (double)atof(argv[8]);

        cv::Mat roi1(src1, cv::Rect(0, 0, from_w - 1, from_h - 1));
        cv::Mat roi2(src2, cv::Rect(x, y, from_w - 1, from_h - 1));

        cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi2);

        cv::namedWindow("Alpha Blend", 1);
        cv::imshow("Alpha Blend", src2);
        cv::waitKey(0);
    }
    return 0;
}