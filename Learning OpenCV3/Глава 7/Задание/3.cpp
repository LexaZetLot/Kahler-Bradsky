 #include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    int size1[1] = { 3 };
    int size[1] = { 100 };
    int mean[3] = { 120, 32, 128 };
    cv::Mat arr(1, size, CV_8UC1);
    cv::RNG rng = cv::theRNG();

    for (int i = 0; i < size[0]; i++)
        arr.at<cv::Vec3b>(i) = cv::Vec3b(rng.uniform(64, 192), rng.uniform(64, 192), rng.uniform(0, 255));
    cv::PCA pca(arr, cv::Mat(), cv::PCA::DATA_AS_ROW, 0);
    cout << arr;

    return 0;
}