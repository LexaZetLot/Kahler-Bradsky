#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int g_x;
int g_y;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    g_x = x;
    g_y = y;
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        flag_mouse = 1;
    }
    else if (event == cv::EVENT_RBUTTONDOWN)
        flag_mouse = 2;
}

int main(void)
{
    int i;
    int size[2] = {800, 800};
    cv::Mat mat (2, size, CV_8UC3);
    cv::Point point_start;
    cv::Point point_end;
    mat = cv::Scalar(0, 0, 0);
    cv::namedWindow("1", 1);

    for (;;)
    {
        cv::setMouseCallback("1", CallBackFunc, NULL);
        cv::imshow("1", mat);
        if (flag_mouse == 1)
        {
            point_start = cv::Point(g_x, g_y);
            flag_mouse = 0;
        }
        else if (flag_mouse == 2)
        {
            point_end = cv::Point(g_x, g_y);
            flag_mouse = 0;
            cv::line(mat, point_start, point_end, cv::Scalar(234.0, 54.0, 123.0));
            cv::LineIterator it(mat, point_start, point_end);
            for (i = 0; i < it.count; i++)
                it++;
            std::cout << i << std::endl;
        }
        
        char ch = (char)cv::waitKey(33);
        if (ch == 27)
            break;
    }
    return 0;
}