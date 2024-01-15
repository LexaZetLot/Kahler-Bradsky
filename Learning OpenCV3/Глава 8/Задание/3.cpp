#include <opencv2/opencv.hpp>
#define X 1920
#define Y 1000

int g_x;
int g_y;
unsigned char flag_mouse = 0;


void CallBackFunc(int event, int x, int y, int flags, void* userdata);

int main(void)
{
	int flag_his = 0;
	cv::Mat mat = cv::imread("test1.jpg");
	cv::Mat buf_mat = cv::imread("test1.jpg");
	cv::Mat his = cv::Mat(cv::Size(X, Y), CV_8UC3);
	cv::Point start;
	cv::Point end;
	cv::namedWindow("1", 1);
	cv::namedWindow("2", 1);
	for (;;)
	{
		cv::setMouseCallback("1", CallBackFunc, NULL);
		cv::imshow("1", mat);
		cv::imshow("2", his);

		if (flag_mouse == 1)
		{
			buf_mat.copyTo(mat);
			start = cv::Point(g_x, g_y);
			mat.copyTo(buf_mat);
			flag_mouse = 0;
		}
		else if (flag_mouse == 2)
		{
			end = cv::Point(g_x, g_y);
			cv::rectangle(mat, start, end, cv::Scalar(0.0, 0.0, 0.0), 6);
			flag_mouse = 0;
			flag_his++;
			his = 0;
		}



		if (flag_his == 1)
		{
			int bh0_31 = 0;
			int bh32_63 = 0;
			int bh64_95 = 0;
			int bh96_127 = 0;
			int bh128_159 = 0;
			int bh160_191 = 0;
			int bh192_223 = 0;
			int bh224_255 = 0;
			int b0_31 = 0;
			int b32_63 = 0;
			int b64_95 = 0;
			int b96_127 = 0;
			int b128_159 = 0;
			int b160_191 = 0;
			int b192_223 = 0;
			int b224_255 = 0;

			int gh0_31 = 0;
			int gh32_63 = 0;
			int gh64_95 = 0;
			int gh96_127 = 0;
			int gh128_159 = 0;
			int gh160_191 = 0;
			int gh192_223 = 0;
			int gh224_255 = 0;
			int g0_31 = 0;
			int g32_63 = 0;
			int g64_95 = 0;
			int g96_127 = 0;
			int g128_159 = 0;
			int g160_191 = 0;
			int g192_223 = 0;
			int g224_255 = 0;

			int rh0_31 = 0;
			int rh32_63 = 0;
			int rh64_95 = 0;
			int rh96_127 = 0;
			int rh128_159 = 0;
			int rh160_191 = 0;
			int rh192_223 = 0;
			int rh224_255 = 0;
			int r0_31 = 0;
			int r32_63 = 0;
			int r64_95 = 0;
			int r96_127 = 0;
			int r128_159 = 0;
			int r160_191 = 0;
			int r192_223 = 0;
			int r224_255 = 0;

			for (int i = start.y; i < end.y; i++)
				for (int j = start.x; j < end.x; j++)
				{
					if (mat.at<cv::Vec3b>(i, j)[0] <= 31)
					{
						if (b0_31 < 10 && bh0_31 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh0_31, b0_31)[0] = 31;
							b0_31++;
							if (b0_31 == 10)
							{
								b0_31 = 0;
								bh0_31++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 63 && mat.at<cv::Vec3b>(i, j)[0] > 31)
					{
						if (b32_63 < 10 && bh32_63 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh32_63, b32_63 + 10)[0] = 63;
							b32_63++;
							if (b32_63 == 10)
							{
								b32_63 = 0;
								bh32_63++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 95 && mat.at<cv::Vec3b>(i, j)[0] > 63)
					{
						if (b64_95 < 10 && bh64_95 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh64_95, b64_95 + 20)[0] = 95;
							b64_95++;
							if (b64_95 == 10)
							{
								b64_95 = 0;
								bh64_95++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 127 && mat.at<cv::Vec3b>(i, j)[0] > 95)
					{
						if (b96_127 < 10 && bh96_127 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh96_127, b96_127 + 30)[0] = 127;
							b96_127++;
							if (b96_127 == 10)
							{
								b96_127 = 0;
								bh96_127++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 159 && mat.at<cv::Vec3b>(i, j)[0] > 127)
					{
						if (b128_159 < 10 && bh128_159 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh128_159, b128_159 + 40)[0] = 159;
							b128_159++;
							if (b128_159 == 10)
							{
								b128_159 = 0;
								bh128_159++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 191 && mat.at<cv::Vec3b>(i, j)[0] > 159)
					{
						if (b160_191 < 10 && bh160_191 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh160_191, b160_191 + 50)[0] = 191;
							b160_191++;
							if (b160_191 == 10)
							{
								b160_191 = 0;
								bh160_191++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 223 && mat.at<cv::Vec3b>(i, j)[0] > 191)
					{
						if (b192_223 < 10 && bh192_223 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh192_223, b192_223 + 60)[0] = 223;
							b192_223++;
							if (b192_223 == 10)
							{
								b192_223 = 0;
								bh192_223++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 255 && mat.at<cv::Vec3b>(i, j)[0] > 224)
					{
						if (b224_255 < 10 && bh224_255 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - bh224_255, b224_255 + 70)[0] = 254;
							b224_255++;
							if (b224_255 == 10)
							{
								b224_255 = 0;
								bh224_255++;
							}
						}
					}

					if (mat.at<cv::Vec3b>(i, j)[1] <= 31)
					{
						if (g0_31 < 10 && gh0_31 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh0_31, g0_31 + 80)[1] = 31;
							g0_31++;
							if (g0_31 == 10)
							{
								g0_31 = 0;
								gh0_31++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 63 && mat.at<cv::Vec3b>(i, j)[1] > 31)
					{
						if (g32_63 < 10 && gh32_63 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh32_63, g32_63 + 90)[1] = 63;
							g32_63++;
							if (g32_63 == 10)
							{
								g32_63 = 0;
								gh32_63++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 95 && mat.at<cv::Vec3b>(i, j)[1] > 63)
					{
						if (g64_95 < 10 && gh64_95 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh64_95, g64_95 + 100)[1] = 95;
							g64_95++;
							if (g64_95 == 10)
							{
								g64_95 = 0;
								gh64_95++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 127 && mat.at<cv::Vec3b>(i, j)[1] > 95)
					{
						if (g96_127 < 10 && gh96_127 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh96_127, g96_127 + 110)[1] = 127;
							g96_127++;
							if (g96_127 == 10)
							{
								g96_127 = 0;
								gh96_127++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 159 && mat.at<cv::Vec3b>(i, j)[1] > 127)
					{
						if (g128_159 < 10 && gh128_159 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh128_159, g128_159 + 120)[1] = 159;
							g128_159++;
							if (g128_159 == 10)
							{
								g128_159 = 0;
								gh128_159++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 191 && mat.at<cv::Vec3b>(i, j)[1] > 159)
					{
						if (g160_191 < 10 && gh160_191 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh160_191, g160_191 + 130)[1] = 191;
							g160_191++;
							if (g160_191 == 10)
							{
								g160_191 = 0;
								gh160_191++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 223 && mat.at<cv::Vec3b>(i, j)[1] > 191)
					{
						if (g192_223 < 10 && gh192_223 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh192_223, g192_223 + 140)[1] = 223;
							g192_223++;
							if (g192_223 == 10)
							{
								g192_223 = 0;
								gh192_223++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 255 && mat.at<cv::Vec3b>(i, j)[1] > 224)
					{
						if (g224_255 < 10 && gh224_255 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh224_255, g224_255 + 150)[1] = 254;
							g224_255++;
							if (g224_255 == 10)
							{
								g224_255 = 0;
								gh224_255++;
							}
						}
					}


					if (mat.at<cv::Vec3b>(i, j)[1] <= 31)
					{
						if (g0_31 < 10 && gh0_31 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh0_31, g0_31 + 80)[1] = 31;
							g0_31++;
							if (g0_31 == 10)
							{
								g0_31 = 0;
								gh0_31++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 63 && mat.at<cv::Vec3b>(i, j)[1] > 31)
					{
						if (g32_63 < 10 && gh32_63 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh32_63, g32_63 + 90)[1] = 63;
							g32_63++;
							if (g32_63 == 10)
							{
								g32_63 = 0;
								gh32_63++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 95 && mat.at<cv::Vec3b>(i, j)[1] > 63)
					{
						if (g64_95 < 10 && gh64_95 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh64_95, g64_95 + 100)[1] = 95;
							g64_95++;
							if (g64_95 == 10)
							{
								g64_95 = 0;
								gh64_95++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[0] <= 127 && mat.at<cv::Vec3b>(i, j)[1] > 95)
					{
						if (g96_127 < 10 && gh96_127 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh96_127, g96_127 + 110)[1] = 127;
							g96_127++;
							if (g96_127 == 10)
							{
								g96_127 = 0;
								gh96_127++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 159 && mat.at<cv::Vec3b>(i, j)[1] > 127)
					{
						if (g128_159 < 10 && gh128_159 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh128_159, g128_159 + 120)[1] = 159;
							g128_159++;
							if (g128_159 == 10)
							{
								g128_159 = 0;
								gh128_159++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 191 && mat.at<cv::Vec3b>(i, j)[1] > 159)
					{
						if (g160_191 < 10 && gh160_191 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh160_191, g160_191 + 130)[1] = 191;
							g160_191++;
							if (g160_191 == 10)
							{
								g160_191 = 0;
								gh160_191++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 223 && mat.at<cv::Vec3b>(i, j)[1] > 191)
					{
						if (g192_223 < 10 && gh192_223 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh192_223, g192_223 + 140)[1] = 223;
							g192_223++;
							if (g192_223 == 10)
							{
								g192_223 = 0;
								gh192_223++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[1] <= 255 && mat.at<cv::Vec3b>(i, j)[1] > 224)
					{
						if (g224_255 < 10 && gh224_255 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - gh224_255, g224_255 + 150)[1] = 254;
							g224_255++;
							if (g224_255 == 10)
							{
								g224_255 = 0;
								gh224_255++;
							}
						}
					}

					if (mat.at<cv::Vec3b>(i, j)[2] <= 31)
					{
						if (r0_31 < 10 && rh0_31 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh0_31, r0_31 + 160)[2] = 31;
							r0_31++;
							if (r0_31 == 10)
							{
								r0_31 = 0;
								rh0_31++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 63 && mat.at<cv::Vec3b>(i, j)[2] > 31)
					{
						if (r32_63 < 10 && rh32_63 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh32_63, r32_63 + 170)[2] = 63;
							r32_63++;
							if (r32_63 == 10)
							{
								r32_63 = 0;
								rh32_63++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 95 && mat.at<cv::Vec3b>(i, j)[2] > 63)
					{
						if (r64_95 < 10 && rh64_95 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh64_95, r64_95 + 180)[2] = 95;
							r64_95++;
							if (r64_95 == 10)
							{
								r64_95 = 0;
								rh64_95++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 127 && mat.at<cv::Vec3b>(i, j)[2] > 95)
					{
						if (r96_127 < 10 && rh96_127 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh96_127, r96_127 + 190)[2] = 127;
							r96_127++;
							if (r96_127 == 10)
							{
								r96_127 = 0;
								rh96_127++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 159 && mat.at<cv::Vec3b>(i, j)[2] > 127)
					{
						if (r128_159 < 10 && rh128_159 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh128_159, r128_159 + 200)[2] = 159;
							r128_159++;
							if (r128_159 == 10)
							{
								r128_159 = 0;
								rh128_159++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 191 && mat.at<cv::Vec3b>(i, j)[2] > 159)
					{
						if (r160_191 < 10 && rh160_191 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh160_191, r160_191 + 210)[2] = 191;
							r160_191++;
							if (r160_191 == 10)
							{
								r160_191 = 0;
								rh160_191++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 223 && mat.at<cv::Vec3b>(i, j)[2] > 191)
					{
						if (r192_223 < 10 && rh192_223 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh192_223, r192_223 + 220)[2] = 223;
							r192_223++;
							if (r192_223 == 10)
							{
								r192_223 = 0;
								rh192_223++;
							}
						}
					}
					else if (mat.at<cv::Vec3b>(i, j)[2] <= 255 && mat.at<cv::Vec3b>(i, j)[2] > 224)
					{
						if (r224_255 < 10 && rh224_255 < (Y - 1))
						{
							his.at<cv::Vec3d>(Y - 1 - rh224_255, r224_255 + 230)[2] = 254;
							r224_255++;
							if (r224_255 == 10)
							{
								r224_255 = 0;
								rh224_255++;
							}
						}
					}
				}
			flag_his = 0;
		}

		cv::putText(his, "0", cv::Point(0, 999), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "500", cv::Point(0, 949), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "1000", cv::Point(0, 899), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "1500", cv::Point(0, 849), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "2000", cv::Point(0, 799), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "2500", cv::Point(0, 749), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "3000", cv::Point(0, 699), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "3500", cv::Point(0, 649), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "4000", cv::Point(0, 599), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "4500", cv::Point(0, 549), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "5000", cv::Point(0, 499), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "5500", cv::Point(0, 449), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "6000", cv::Point(0, 399), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "6500", cv::Point(0, 349), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "7000", cv::Point(0, 299), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "7500", cv::Point(0, 249), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "8000", cv::Point(0, 199), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "8500", cv::Point(0, 149), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "9000", cv::Point(0, 99), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));
		cv::putText(his, "9500", cv::Point(0, 49), cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(254.0, 254.0, 254.0));

		if ((char)cv::waitKey(33) == 27)
			break;
	}
	return 0;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	g_x = x;
	g_y = y;
	if (event == cv::EVENT_LBUTTONDOWN)
		flag_mouse++;
	else if (event == cv::EVENT_LBUTTONUP)
		flag_mouse += 2;
}