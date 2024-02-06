#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

// Использование ползунка для создания "переключателя".
// Эта переменная сделка глобальной, чтобы к ней можно было обратиться
// из любого места.
int g_switch_value = 1;
void switch_off_function() { cout << "Pause\n"; }; //YOU COULD DO MORE
void switch_on_function()  { cout << "Run\n"; };

// Это функция обратного вызова дял ползунка
void switch_callback( int position, void* )
{
    if( position == 0 )
        switch_off_function();
    else
        switch_on_function();
}

int main()
{
    cv::Mat frame; // для хранения кадра видео
    cv::VideoCapture g_capture;
    g_capture.open(0);

    // Присваивание имя главному окну
    cv::namedWindow( "Example", 1 );

    // Создаем ползунок. Присваиваем ему имя и передаем имя родительского окна.
    cv::createTrackbar("Switch", "Example", &g_switch_value, 1, switch_callback);

    // Этот цикл не дает программе выйти, пока
    // пользователь не нажмет клавишу Esc
    for(;;)
    {
        if( g_switch_value )
        {
            g_capture >> frame;
            if( frame.empty() ) break;
                cv::imshow( "Example", frame);
        }
        if( cv::waitKey(10)==27 )
            break;
    }
    return 0;
}

