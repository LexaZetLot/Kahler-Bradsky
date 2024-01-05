#include <opencv2/opencv.hpp>
#include <iostream>

int main(void)
{
    cv::Matx33f a = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };
    cv::Vec3f b = { 1, 2, 3 };
    std::cout << a * b;
    return 0;
}