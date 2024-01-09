#include <opencv2/opencv.hpp>

int main(void)
{
    int size[2] = { 210, 210 };
    cv::Mat mat(2, size, 0);
    cv::Mat mat1(2, size, 0);
    int color = 40;
    int start1 = 0;
    int start2 = 200;
    int end1 = 210;
    int end2 = 10;
    mat = 0;
    mat1 = 20;
    cv::namedWindow("1", 1);
    mat.setTo(20, mat1);
    while (color != 260)
    {
        mat1 = color;
        for (int i = 0; i < end2; i++)
            for (int j = 0; j < 210; j++)
                mat1.at<unsigned char>(i, j) = 0;
        for (int i = 0; i < 210; i++)
            for (int j = 0; j < end2; j++)
                mat1.at<unsigned char>(i, j) = 0;
        for (int i = start2; i < end1; i++)
            for (int j = 0; j < 210; j++)
                mat1.at<unsigned char>(i, j) = 0;
        for (int i = 0; i < 210; i++)
            for (int j = start2; j < end1; j++)
                mat1.at<unsigned char>(i, j) = 0;
        start1 += 10;
        start2 -= 10;
        end2 += 10;
        mat.setTo(color, mat1);
        color += 20;
    }

    cv::imshow("1", mat);
    cv::waitKey(INT_MAX);

    return 0;
}