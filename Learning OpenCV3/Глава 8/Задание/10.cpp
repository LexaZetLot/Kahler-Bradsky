#include <opencv2/opencv.hpp>

using namespace std;

struct my_struct
{
    int x;
    cv::Point point;
    cv::Rect rect;
};

void write_my_struct(cv::FileStorage& fs, const string& name, const my_struct* ms);
void read_my_struct(const cv::FileStorage& fs, const cv::FileNode& ms_node, my_struct* ms);

int main(void)
{
    my_struct my_str[10] = { 10, cv::Point(234, 465), cv::Rect(32, 543, 424, 453) };
    my_struct my_str1[10];
    cv::FileStorage fs;
    fs.open("test.yml", cv::FileStorage::WRITE + cv::FileStorage::READ);
    write_my_struct(fs, "struct", my_str);
    cv::FileNode n_fs = fs["struct"];
    cout << (int)*n_fs.begin() << endl;
    read_my_struct(fs, n_fs, my_str1);
    for (int i = 0; i < 10; i++)
        cout << my_str1[i].x << " " << my_str1[i].point << " " << my_str1[i].rect << endl;

    return 0;
}

void write_my_struct(cv::FileStorage& fs, const string& name, const my_struct* ms)
{
    fs << name << "[";
    for (int i = 0; i < 10; i++)
        fs << (ms + i)->x << (ms + i)->point.x << (ms + i)->point.y << (ms + i)->rect.x << (ms + i)->rect.y << (ms + i)->rect.width << (ms + i)->rect.height;
    fs << "]";
}

void read_my_struct(const cv::FileStorage& fs, const cv::FileNode& ms_node, my_struct* ms)
{
    cv::FileNodeIterator it = ms_node.begin(), it_end = ms_node.end();
    cout << (int)*it << " " << (int)*ms_node.begin() << endl;
    for (int i = 0; it != it_end; ++it, i++)
    {

        switch (i % 7)
        {
        case 0:

            (ms + i / 7)->x = (int)*it;
            break;
        case 1:
            (ms + i / 7)->point.x = (int)*it;
            break;
        case 2:
            (ms + i / 7)->point.y = (int)*it;
            break;
        case 3:
            (ms + i / 7)->rect.x = (int)*it;
            break;
        case 4:
            (ms + i / 7)->rect.y = (int)*it;
            break;
        case 5:
            (ms + i / 7)->rect.width = (int)*it;
            break;
        case 6:
            (ms + i / 7)->rect.height = (int)*it;
            break;
        }
    }
}