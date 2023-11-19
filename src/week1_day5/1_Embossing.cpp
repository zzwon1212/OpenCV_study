#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day5/";

int main(void)
{
    Mat src = imread(BASE_DIR + "rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    float data[] = {-1.f, -1.f, 0.f, -1.f, 0.f, 1.f, 0.f, 1.f, 1.f};
    Mat kernel(3, 3, CV_32FC1, data);

    Mat dst;
    filter2D(src, dst, -1, kernel, Point(-1, -1), 128);

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
}
