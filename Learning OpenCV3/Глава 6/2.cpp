#include <opencv2/opencv.hpp>
#include <iostream>

int main(void)
{
    cv::Mat mat = cv::imread("test4.jpeg");
    cv::Mat buf[3];

    cv::split(mat, buf);
    for (int i = 0; i < mat.size().height; i++)
        for (int j = 0; j < mat.size().width; j++)
            mat.at<cv::Vec3b>(i, j) = cv::Vec3b(buf[0].at<uchar>(i, j), buf[0].at<uchar>(i, j), buf[0].at<uchar>(i, j));

    cv::putText(mat, "hdafhj", cv::Point(300, 300), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(0, 54.0, 123.0));

    cv::namedWindow("1", 1);

    cv::imshow("1", mat);

    cv::waitKey(INT_MAX);

    return 0;
}