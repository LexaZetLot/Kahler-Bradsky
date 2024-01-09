#include "function.h"

static int g_x = 0;
static int g_y = 0;

bool print(cv::Mat& mat, const char ch)
{
	switch (ch)
	{
	case '1':
		return print_numbers(mat, one_arr);
	case '2':
		return print_numbers(mat, two_arr);
	case '3':
		return print_numbers(mat, three_arr);
	case '4':
		return print_numbers(mat, four_arr);
	case '5':
		return print_numbers(mat, five_arr);
	case '6':
		return print_numbers(mat, six_arr);
	case '7':
		return print_numbers(mat, seven_arr);
	case '8':
		return print_numbers(mat, eight_arr);
	case '9':
		return print_numbers(mat, nine_arr);
	case '0':
		return print_numbers(mat, zero_arr);
	case ' ':
		return print_numbers(mat, space_arr);
	case 's':
		wipe_back(mat);
		if (MAX_SIZE_X / X_SIZE == g_x + 1)
		{
			print_back(mat);
			return true;
		}
		g_x++;
		print_back(mat);
		return true;
	case 'w':
		wipe_back(mat);
		if (!g_x)
		{
			print_back(mat);
			return true;
		}
		g_x--;
		print_back(mat);
		return true;
	case 'd':
		wipe_back(mat);
		if (MAX_SIZE_Y / Y_SIZE == g_y + 1)
		{
			if (MAX_SIZE_X / X_SIZE == g_x + 1)
			{
				print_back(mat);
				return true;
			}
			g_y = 0;
			g_x++;
			print_back(mat);
			return true;
		}
		g_y++;
		print_back(mat);
		return true;
	case 'a':
		wipe_back(mat);
		if (!g_y)
		{
			print_back(mat);
			return true;
		}
		g_y--;
		print_back(mat);
		return true;
	}
	return false;
}

void wipe_back(cv::Mat& mat)
{
	for (int i = X_SIZE * g_x; i < X_SIZE + (X_SIZE * g_x); i++)
		for (int j = Y_SIZE * g_y; j < Y_SIZE + (Y_SIZE * g_y); j++)
			if (mat.at<unsigned char>(i, j) == 254 / 2)
				mat.at<unsigned char>(i, j) = 0;
}

void print_back(cv::Mat& mat)
{
	for (int i = X_SIZE * g_x; i < X_SIZE + (X_SIZE * g_x); i++)
		for (int j = Y_SIZE * g_y; j < Y_SIZE + (Y_SIZE * g_y); j++)
			if (mat.at<unsigned char>(i, j) != 254)
				mat.at<unsigned char>(i, j) = 254 / 2;
}

bool print_numbers(cv::Mat& mat, const unsigned char* number_arr)
{
	for (int i = X_SIZE * g_x; i < X_SIZE + (X_SIZE * g_x); i++)
		for (int j = Y_SIZE * g_y; j < Y_SIZE + (Y_SIZE * g_y); j++)
			mat.at<unsigned char>(i, j) = number_arr[Y_SIZE * (i - (X_SIZE * g_x)) + (j - (Y_SIZE * g_y))];
	g_y++;
	if (MAX_SIZE_Y / Y_SIZE > g_y)
	{
		print_back(mat);
		return true;
	}
	else if (MAX_SIZE_Y / Y_SIZE == g_y)
	{
		g_x++;
		g_y = 0;
		print_back(mat);
		return true;
	}
	else
		return false;
}