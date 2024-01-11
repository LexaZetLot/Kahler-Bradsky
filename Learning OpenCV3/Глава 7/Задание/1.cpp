#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    cv::RNG rng = cv::theRNG();
    cout << (float)rng << endl;
    cout << (float)rng << endl;
    cout << (float)rng << endl;
    cout << (double)rng.gaussian(1.0) << endl;
    cout << (double)rng.gaussian(1.0) << endl;
    cout << (double)rng.gaussian(1.0) << endl;
    cout << (int)((uint8_t)rng) << endl;
    cout << (int)((uint8_t)rng) << endl;
    cout << (int)((uint8_t)rng) << endl;
    return 0;
}