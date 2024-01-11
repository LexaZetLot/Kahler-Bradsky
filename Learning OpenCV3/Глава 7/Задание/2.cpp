#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    int size[1] = { 20 };
    cv::Mat arr(1, size, CV_32F);
    cv::Mat arr1(1, size, CV_32F);
    cv::Mat arr2(1, size, CV_8UC1);
    cv::Mat arr3(1, size, CV_8UC3);
    cv::RNG rng = cv::theRNG();
    rng.fill(arr, cv::RNG::UNIFORM, 0.0, 1.0);
    rng.fill(arr1, cv::RNG::NORMAL, 0.0, 1.0);
    rng.fill(arr2, cv::RNG::UNIFORM, 0, 255);
    rng.fill(arr3, cv::RNG::UNIFORM, 0, 255);
    std::cout << arr << std::endl << arr1 << std::endl << arr2 << std::endl << arr3;

    return 0;
}