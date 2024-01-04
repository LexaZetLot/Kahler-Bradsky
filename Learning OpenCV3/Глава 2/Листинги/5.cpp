#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("Screenshot_1.png", -1);

	// ������� ��������� ���� ��� ������ ��������
	// � ��������� �����������.
	//
	cv::namedWindow("Example 2_5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example 2_5-out", cv::WINDOW_AUTOSIZE);

	// ���������� ������� �����������
	cv::imshow("Example 2_5-in", image);

	// ������� ������ ��� �������� ������������� �����������
	cv::Mat out;

	// ����������
	// (����������: ����� ������������ GaussianBlur(), blur(), medianBlur()
	// ��� bilateralFilter().)
	//
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	// ���������� ���������� ����������� � ���� ������
	cv::imshow("Example 2_5-out", out);

	// ���� ������� �������, ���� ������������ �������������
	cv::waitKey(0);
}