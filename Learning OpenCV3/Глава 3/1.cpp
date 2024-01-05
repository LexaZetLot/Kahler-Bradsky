#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>

int main(void)
{
    srand(cv::getTickCount());
    float a = -1.3232f;
    cv::Point2f b(2.3, 2.7);
    std::cout << (int)fabs(a) << ' ' << ceil(fabs(a)) << ' ' << floor(fabs(a)) << '\n';
    std::cout << rand() << ' ' << rand() << ' ' << rand() << '\n';
    std::cout << b << ' ';
    b = (cv::Point)b;
    std::cout << b << ' ';
    b = (cv::Point2f)b;
    std::cout << b << ' ';
    return 0;
}