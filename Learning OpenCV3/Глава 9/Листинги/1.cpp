#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
	// Создание окон, указав в качестве его имени имя файла
	cv::namedWindow("1", 1);

	// Загрузить изображение из указанного файла 
	cv::Mat img = cv::imread("test1.jpg");

	// Показать изображения в именованном окне
	cv::imshow("1", img);

	// Ждать, пока пользователь не нажмет клавишу Esc
	while (true)
		if (cv::waitKey(100) == 27) break;

	// прибраться за собой
	cv::destroyWindow("1");
	exit(0);
}