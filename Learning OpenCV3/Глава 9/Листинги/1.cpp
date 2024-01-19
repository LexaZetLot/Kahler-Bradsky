#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
	// �������� ����, ������ � �������� ��� ����� ��� �����
	cv::namedWindow("1", 1);

	// ��������� ����������� �� ���������� ����� 
	cv::Mat img = cv::imread("test1.jpg");

	// �������� ����������� � ����������� ����
	cv::imshow("1", img);

	// �����, ���� ������������ �� ������ ������� Esc
	while (true)
		if (cv::waitKey(100) == 27) break;

	// ���������� �� �����
	cv::destroyWindow("1");
	exit(0);
}