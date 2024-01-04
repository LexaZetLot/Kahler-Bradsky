#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cv::namedWindow("Example 2-11", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

    // (����������: ����� ���� �� ����������� ������ � ������,
    // ���� �������� �� ������������� � ���� int.)
    cv::VideoCapture capture("The.Rookie.S01E01.1080p.rus.LostFilm.TV.mkv");
    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open("1.mkv", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;
    for (;;)
    {
        capture >> bgr_frame;
        if (bgr_frame.empty()) break;           // �������, ���� ������ ������ ���

        cv::imshow("Example 2-11", bgr_frame);

        cv::logPolar(
            bgr_frame,                          // ������� ������� ����
            logpolar_frame,                     // �������� ���� � ���-�������� �����������
            cv::Point2f(                        // ����� ���-�������� ��������������
                bgr_frame.cols / 2,             // �
                bgr_frame.rows / 2              // Y
            ),
            40,                                 // ���������� �������� (���������� ��������)
            cv::WARP_FILL_OUTLIERS              // ��������� ������� ������
        );

        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;

        char c = cv::waitKey(10);
        if (c == 27) break;                     // ���� ������������ ����������� �����
    }

    capture.release();
}