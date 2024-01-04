#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("Screenshot_1.png", -1);

	// Создаем несколько окон для показа входного
	// и выходного изображения.
	//
	cv::namedWindow("Example 2_5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example 2_5-out", cv::WINDOW_AUTOSIZE);

	// Показываем входное изображение
	cv::imshow("Example 2_5-in", image);

	// Создаем объект для хранения сглаживаемого изображения
	cv::Mat out;

	// Сглаживаем
	// (Примечание: можно использовать GaussianBlur(), blur(), medianBlur()
	// или bilateralFilter().)
	//
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	// Показываем сглаженное изображение в окне вывода
	cv::imshow("Example 2_5-out", out);

	// Ждем нажатия клавиши, окна уничтожается автоматически
	cv::waitKey(0);
}