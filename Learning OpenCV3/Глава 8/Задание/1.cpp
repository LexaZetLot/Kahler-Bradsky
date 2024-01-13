#include <opencv2/opencv.hpp>

using namespace std;

int main(void)
{
	cv::VideoCapture cap;
	cv::Mat full;
	cv::Mat mat1;
	cv::Mat mat2;
	cv::Mat mat3;
	cv::Mat gray_mat;
	cv::Mat canny_mat;
	std::vector <cv::Mat> arr;
	cap.open(0);

	cv::namedWindow("1", 1);

	for (;;)
	{
		cap >> mat1;

		cv::cvtColor(mat1, gray_mat, cv::COLOR_BGR2GRAY);
		arr.push_back(gray_mat);
		arr.push_back(gray_mat);
		arr.push_back(gray_mat);
		cv::merge(arr, mat2);
		arr.clear();


		cv::Canny(gray_mat, canny_mat, 0, 350);
		arr.push_back(canny_mat);
		arr.push_back(canny_mat);
		arr.push_back(canny_mat);
		cv::merge(arr, mat3);
		arr.clear();


		arr.push_back(mat1);
		arr.push_back(mat2);
		arr.push_back(mat3);
		cv::hconcat(arr, full);
		arr.clear();
		cv::putText(full, "Normal", cv::Point(5, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(full, "Monochrome", cv::Point(5 + mat1.cols, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(full, "Canny", cv::Point(5 + mat1.cols * 2, 30), cv::FONT_HERSHEY_TRIPLEX, 1.0, cv::Scalar(254.0, 254.0, 254.0));
		cv::imshow("1", full);

		if ((char)cv::waitKey(33) == 27)
			break;
	}
}