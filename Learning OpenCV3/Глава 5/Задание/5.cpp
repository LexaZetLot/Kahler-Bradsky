#include <opencv2/opencv.hpp>

int main(void)
{
    cv::Mat test1 = cv::imread("test1.png");
    cv::Mat test2 = cv::imread("test2.png");
    cv::Mat test3 = cv::imread("test3.png");
    cv::Mat roi_t2(test2, cv::Rect(5, 10, 20, 30));
    cv::Mat roi_t3(test3, cv::Rect(50, 60, 20, 30));

    cv::bitwise_not(roi_t2, roi_t2);
    cv::bitwise_not(roi_t3, roi_t3);
    cv::addWeighted(roi_t2, 1.0, roi_t3, 1.0, 0.0, roi_t2);
    cv::addWeighted(test1, 1.0, test2, 1.0, 0.0, test1);

    cv::namedWindow("1", 6);

    cv::imshow("1", test1);

    cv::waitKey(INT_MAX);

    return 0;
}