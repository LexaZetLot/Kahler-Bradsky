#include <opencv2/opencv.hpp>
#include <iostream>

int main(void)
{
    cv::Matx <float, 3, 3> a = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };
    cv::Vec <float, 3> b = { 1, 2, 3 };
    std::cout << a * b << '\n';
    std::cout << a * (cv::Matx <float, 3, 1>)b;
    return 0;
}