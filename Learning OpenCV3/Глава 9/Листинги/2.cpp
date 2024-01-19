#include <opencv2/opencv.hpp>

// Объявляем функцию обратного вызова для обработки событий мыши
void my_mouse_callback(

    int event, int x, int y, int flags, void* param
);
cv::Rect box;
bool drawing_box = false;

// Программа для рисования прямокгольника внутри изображения
void draw_box(cv::Mat& img, cv::Rect box)
{
    cv::rectangle(
        img,
        box.tl(),
        box.br(),
        cv::Scalar(0x00, 0x00, 0xff)    /* красный */
    );
}

void help()
{
    std::cout << "Example 9-2. Toy program for using a mouse to draw boxes on the screen" <<
        "\n\nshows how to use a mouse to draw regions in an image. Esc to quit\n" << std::endl;
}
int main() {
    help();
    box = cv::Rect(-1, -1, 0, 0);
    cv::Mat image(200, 200, CV_8UC3), temp;
    image.copyTo(temp);

    box = cv::Rect(-1, -1, 0, 0);
    image = cv::Scalar::all(0);

    cv::namedWindow("Box Example");

    // Самый важный момент - установка функции обратного вызова.
    // Обратите внимание, что в аргументе 'param' передается указатель
    // на изображение с которым мы работаем, чтобы функция знала,
    // какое изображение изменять.
    cv::setMouseCallback(
        "Box Example",
        my_mouse_callback,
        (void*)&image
    );
    // Главный цикл. Копирует рабочее изображение во временное и,
    // если пользователь рисует, помещает текущий прямоугольник
    // во временное изображение. Показываем временное изображение,
    // ждем нажатие клавиши в течении 15 мс и повторяем
    for (;;)
    {
        image.copyTo(temp);
        if (drawing_box) draw_box(temp, box);
        cv::imshow("Box Example", temp);
        if (cv::waitKey(15) == 27) break;
    }
    return 0;
}

// Это функция обратного вызова. Когда пользователь нажимает левую
// кнопку, начинаем рисовать прямоугольник. Когда пользователь
// отпускает кнопку, добавляем прямоугольник в текущее
// изображение. Когда пользователь буксирует мышь с нажатой кнопкой,
// изменяем размер прямоугольника.
void my_mouse_callback(
    int event, int x, int y, int flags, void* param)
{
    cv::Mat& image = *(cv::Mat*)param;
    switch (event) {
    case cv::EVENT_MOUSEMOVE:
    {
        if (drawing_box)
        {
            box.width = x - box.x;
            box.height = y - box.y;
        }
    }
    break;
    case cv::EVENT_LBUTTONDOWN:
    {
        drawing_box = true;
        box = cv::Rect(x, y, 0, 0);
    }
    break;
    case cv::EVENT_LBUTTONUP: {
        drawing_box = false;
        if (box.width < 0)
        {

            box.x += box.width;
            box.width *= -1;
        }
        if (box.height < 0)
        {
            box.y += box.height;
            box.height *= -1;
        }
        draw_box(image, box);
    }
                            break;
    }
}