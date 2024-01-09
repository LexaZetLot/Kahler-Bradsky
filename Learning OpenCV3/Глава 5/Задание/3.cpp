#include <opencv2/opencv.hpp>

int main(void)
{
    int size[2] = { 100, 100 };
    cv::Mat mat(2, size, CV_8UC3);
    mat = 0;
    cv::namedWindow("1", 1);
    for (int i = 5; i < 21; i++)
        mat.at<cv::Vec3b>(i, 20) = cv::Vec3b(0.0, 128.0, 0.0);
    for (int i = 5; i < 21; i++)
        mat.at<cv::Vec3b>(i, 40) = cv::Vec3b(0.0, 128.0, 0.0);
    for (int i = 20; i < 41; i++)
        mat.at<cv::Vec3b>(5, i) = cv::Vec3b(0.0, 128.0, 0.0);
    for (int i = 20; i < 41; i++)
        mat.at<cv::Vec3b>(20, i) = cv::Vec3b(0.0, 128.0, 0.0);

    cv::imshow("1", mat);
    cv::waitKey(INT_MAX);

    return 0;
}