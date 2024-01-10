#include <opencv2/opencv.hpp>
#include <iostream>

int main(void)
{
    cv::Mat test1 = cv::imread("test1.png");
    cv::Mat buf[3];
    double max, min;
    //cv::Mat test3 = cv::imread("test3.png");
    //cv::Mat test3 = cv::imread("test3.png");
    cv::split(test1, buf);
    cv::Mat green = cv::Mat(test1.size(), CV_8UC3);
    cv::Mat clone1 = cv::Mat(test1.size(), CV_8UC3);
    cv::Mat clone2 = cv::Mat(test1.size(), CV_8UC3);
    for (int i = 0; i < test1.size().height; i++)
        for (int j = 0; j < test1.size().width; j++)
            green.at<cv::Vec3b>(i, j) = cv::Vec3b(0, buf[1].at<unsigned char>(i, j), 0);
    green.copyTo(clone1);
    green.copyTo(clone2);
    cv::minMaxLoc(buf[1], &min, &max);

    for (int i = 0; i < test1.size().height; i++)
        for (int j = 0; j < test1.size().width; j++)
            clone1.at<cv::Vec3b>(i, j) = cv::Vec3b(0, (unsigned char)((max - min) / 2.0), 0);
    cv::namedWindow("1", 6);
    for (int i = 0; i < test1.size().height; i++)
        for (int j = 0; j < test1.size().width; j++)
            clone2.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 0);
    cv::compare(green, clone1, clone2, cv::CMP_GE);
    //cv::subtract(green, ((unsigned char)((max - min) / 2.0)) / 2, green, clone2);
    cv::imshow("1", clone1);
    std::cout << min << ' ' << max;
    cv::waitKey(INT_MAX);

    return 0;
}