#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(void)
{
    cv::Mat mat;
    cv::VideoCapture video;
    char str[30];
    double fps;
    video.open(0);

    for (;;)
    {
        video >> mat;
        fps = video.get(cv::CAP_PROP_FPS);
        snprintf(str, sizeof(str), "%.2lf", fps);
        cv::putText(mat, str, cv::Point(50, 50), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(0.0, 0.0, 0.0));
        cv::imshow("1", mat);
        if ((char)cv::waitKey(33) == 27)
            break;
    }
    return 0;
}