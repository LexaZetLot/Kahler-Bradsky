#ifndef FUNCTION_H
#define FUNCTION_H
#include <opencv2/opencv.hpp>
#include "numbers.h"
#include <climits>

void wipe_back(cv::Mat& mat);
void print_back(cv::Mat& mat);
bool print(cv::Mat& mat, const char ch);
bool print_numbers(cv::Mat& mat, const unsigned char* number_arr);

#endif
