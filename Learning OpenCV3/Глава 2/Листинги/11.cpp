#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cv::namedWindow("Example 2-11", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

    // (Примечание: можно было бы захватывать данные с камеры,
    // если передать ее идентификатор в виде int.)
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
        if (bgr_frame.empty()) break;           // выходим, если больше ничего нет

        cv::imshow("Example 2-11", bgr_frame);

        cv::logPolar(
            bgr_frame,                          // Входной цветной кадр
            logpolar_frame,                     // Выходной кадр в лог-полярных координатах
            cv::Point2f(                        // Центр лог-полярных преобразований
                bgr_frame.cols / 2,             // Х
                bgr_frame.rows / 2              // Y
            ),
            40,                                 // Абсолютная величина (масштабный параметр)
            cv::WARP_FILL_OUTLIERS              // Заполнить выбросы нулями
        );

        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;

        char c = cv::waitKey(10);
        if (c == 27) break;                     // дать пользователю возможность выйти
    }

    capture.release();
}