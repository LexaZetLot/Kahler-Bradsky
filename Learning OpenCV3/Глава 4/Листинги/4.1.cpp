#include <opencv2/opencv.hpp>

int main(void)
{
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1);

    cv::RNG rng;
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.f, 1.f);

    const cv::Mat* arrays[] = { &n_mat, 0 };
    cv::Mat my_planes[1];
    cv::NAryMatIterator it(arrays, my_planes);

    // ¬ этом месте у нас есть N-арный интератор. ƒалее мы вычисл€ем сумму
    // элементов в каждой плоскости и прибавл€ем ее к общему итогу.
    // Ќа каждой интерации it.planes[i] - текуща€ плоскость i-го массива из 'arrays'.
    //
    float s = 0.f;                      // сумма по всем плоскост€м
    int   n = 0;                        // число плоскостей
    for (int p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];
        n++;
    }
    std::cout << n;
}