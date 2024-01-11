#include <opencv2/opencv.hpp>
#include <vector>

int g_x;
int g_y;
unsigned char point_flag = 0;
unsigned char flag_mouse = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    g_x = x;
    g_y = y;
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        flag_mouse = 1;
        point_flag++;
    }
    else if (event == cv::EVENT_RBUTTONDOWN)
        flag_mouse = 2;
}

int main(void)
{
    int size[2] = { 800, 800 };
    cv::Mat mat(2, size, CV_8UC3);
    cv::Point point_start;
    cv::Point point_end;
    std::vector<cv::Point> buf_point;
    mat = cv::Scalar(0, 0, 0);
    cv::namedWindow("1", 1);

    for (;;)
    {
        cv::setMouseCallback("1", CallBackFunc, NULL);
        cv::imshow("1", mat);
        if (flag_mouse == 1)
        {
            buf_point.push_back(cv::Point(g_x, g_y));
            flag_mouse = 0;
        }
        else if (flag_mouse == 2)
        {
            buf_point.push_back(cv::Point(g_x, g_y));
            flag_mouse = 0;
            for (int i = 0; i + 1 < buf_point.size(); i++)
                cv::line(mat, buf_point[i], buf_point[i + 1], cv::Scalar(234.0, 54.0, 123.0));
        }

        char ch = (char)cv::waitKey(33);
        if (ch == 27)
            break;
        else if (ch == 'z' && buf_point.size() > 1)
        {
            cv::line(mat, buf_point[buf_point.size() - 1], buf_point[buf_point.size() - 2], cv::Scalar(0.0, 0.0, 0.0));
            buf_point.pop_back();
        }
    }
    return 0;
}