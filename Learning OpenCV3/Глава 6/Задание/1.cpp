#include <opencv2/opencv.hpp>
#include <iostream>

int main(void)
{
    int size[2] = { 800, 800 };
    cv::Mat mat(2, size, CV_8UC3);
    cv::Point arr[4] = { cv::Point(111, 111), cv::Point(120, 111), cv::Point(111, 120), cv::Point(120, 120) };
    mat = 0;

    cv::circle(mat, cv::Point(600, 600), 20, cv::Scalar(234.0, 54.0, 123.0), 3);
    cv::ellipse(mat, cv::Point(200, 200), cv::Size(50, 70), 0.0, 0.0, 0.0, cv::Scalar(234.0, 54.0, 123.0), 3);
    cv::fillConvexPoly(mat, arr, 4, cv::Scalar(234.0, 54.0, 123.0));
    cv::line(mat, cv::Point(500, 500), cv::Point(675, 467), cv::Scalar(234.0, 54.0, 123.0));
    cv::rectangle(mat, cv::Point(300, 300), cv::Point(350, 350), cv::Scalar(234.0, 54.0, 123.0));

    cv::namedWindow("1", 1);

    cv::imshow("1", mat);

    cv::waitKey(INT_MAX);

    return 0;
}