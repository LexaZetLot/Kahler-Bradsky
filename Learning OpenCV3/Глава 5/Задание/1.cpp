#include <opencv2/opencv.hpp>

int main(void)
{
    int size[2] = { 100, 100 };
    cv::Mat mat(2, size, 0);
    mat = 0;
    cv::namedWindow("1", 1);
    cv::circle(mat, cv::Point(cv::Size(50, 50)), 20, cv::Scalar(254.0, 254.0), 1);
    cv::imshow("1", mat);
    cv::waitKey(INT_MAX);

    return 0;
}