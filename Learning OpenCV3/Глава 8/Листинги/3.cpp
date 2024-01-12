#include <opencv2/opencv.hpp>

using namespace std;

int main(void)
{
    cv::FileStorage fs2("test.yml", cv::FileStorage::READ);

    // первый способ: использовать оператор приведения типа из класса FileNode.
    int frameCount = (int)fs2["frameCount"];

    // второй способ: использовать cv::FileNode::operator >>
    std::string date;
    fs2["calibrationDate"] >> date;

    cv::Mat cameraMatrix2, distCoeffs2;
    fs2["cameraMatrix"] >> cameraMatrix2;
    fs2["distCoeffs"] >> distCoeffs2;

    cout << "frameCount: " << frameCount << endl
        << "calibration date: " << date << endl
        << "camera matrix: " << cameraMatrix2 << endl
        << "distortion coeffs: " << distCoeffs2 << endl;

    cv::FileNode features = fs2["features"];
    cv::FileNodeIterator it = features.begin(), it_end = features.end();
    int idx = 0;
    std::vector<uchar> lbpval;

    // обойти последовательность с помощью FileNodeIterator
    for (; it != it_end; ++it, idx++) {

        cout << "feature #" << idx << ": ";
        cout << "x=" << (int)(*it)["x"]
            << ", y=" << (int)(*it)["y"]
            << ", lbp: (";

        // ( Примечание: без труда читаем массивы чисел с помощью 
        // оператора FileNode >> std::vector. )
        (*it)["lbp"] >> lbpval;
        for (int i = 0; i < (int)lbpval.size(); i++)
            cout << " " << (int)lbpval[i];
        cout << ")" << endl;
    }
    fs2.release();
}