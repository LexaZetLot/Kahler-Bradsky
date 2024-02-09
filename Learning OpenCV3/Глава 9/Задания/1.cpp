#include <opencv2/core/matx.hpp>
#include <opencv2/opencv.hpp>

cv::Rect box;
bool drawing_box = false;
void copyfoto (cv::Mat mat, cv::Mat foto, int num);
void my_mouse_callback(int event, int x, int y, int flags, void* param);
void draw_box(cv::Mat& img, cv::Rect box);
int main (void)
{
    box = cv::Rect(-1, -1, 0, 0);
    cv::Mat mat = cv::Mat(cv::Size(600, 600), CV_8UC3), buf;
    cv::Mat foto1 = cv::imread ("test1.jpg");
    cv::Mat foto2 = cv::imread ("test2.jpg");
    cv::Mat foto3 = cv::imread ("test3.jpg");
    cv::Mat foto4 = cv::imread ("test4.jpg");
    copyfoto (mat, foto1, 0);
    copyfoto (mat, foto2, 1);
    copyfoto (mat, foto3, 2);
    copyfoto (mat, foto4, 3);
    cv::namedWindow("1");
    mat.copyTo(buf);
    cv::setMouseCallback("1", my_mouse_callback,(void*)&mat);


    for (;;)
    {
        mat.copyTo(buf);
        if (drawing_box) draw_box(buf, box);
        cv::imshow("1", buf);
        if (cv::waitKey(33) == 27)
            break;
    }
    return 0;
}

auto who_end{ [] (int num, char ch) {
    switch (ch)
    {
    case 'x':
        switch (num)
        {
        case 0:
        case 2:
            return 300;
        case 1:
        case 3: 
            return 599;
        }
    case 'y':
        switch (num) 
        {
        case 0:
        case 1:
            return 300;
        case 2:
        case 3:
            return 599;
        }
    }
    return 0;
}};

auto who_begin{[] (int num, char ch) {
    switch (ch)
    {
    case 'x':
        switch (num)
        {
        case 0:
        case 2:
            return 0;   
        case 1:
        case 3:
            return 300;
        }
    case 'y':
        switch (num)
        {
        case 0:
        case 1:
            return 0;
        case 2:
        case 3:
            return 300;
        }
    }
    return 0;
}};
void copyfoto (cv::Mat mat, cv::Mat foto, int num)
{
    std::cout << who_begin (num, 'x') << std::endl;
    for (int i = who_begin(num, 'x'), fi = 0; i < who_end(num, 'x'); i++, fi++)
        for (int j = who_begin(num, 'y'), fj = 0; j <  who_end(num, 'y'); j++, fj++)
            mat.at<cv::Vec3b>(i, j) = foto.at<cv::Vec3b>(fi, fj);
}

void draw_box(cv::Mat& img, cv::Rect box)
{
    cv::rectangle(img, box.tl(), box.br(), cv::Scalar(0x00, 0x00, 0xff));
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
    cv::Mat& image = *(cv::Mat*)param;
    switch (event)
    {
    case cv::EVENT_MOUSEMOVE:
        if (drawing_box)
        {
                box.width = x - box.x;
                box.height = y - box.y;
        }
        break;
    case cv::EVENT_LBUTTONDOWN:

        drawing_box = true;
        box = cv::Rect(x, y, 0, 0);
        break;
    case cv::EVENT_LBUTTONUP:
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
        break;
    }
}
