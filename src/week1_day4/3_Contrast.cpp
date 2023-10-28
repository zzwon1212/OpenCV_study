#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day4/";

int main()
{
    Mat src = imread(BASE_DIR + "tiffany.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 1. 간단한 조절 방법
    // double s1 = 0.5;
    // Mat dst1 = src * s1;
    // double s2 = 2.0;
    // Mat dst2 = src * s2;

    // 2. (조금) 효과적인 조절 방법
    double alpha = 1.0;
    Mat dst = src + (src - 128) * alpha;

    // 3. 평균 밝기를 고려한 조절 방법
    // double alpha = 1.0;
    // int m = (int)mean(src)[0];
    // Mat dst = src + (src - m) * alpha;
    // cout << m << endl;

    imshow("src", src);
    // imshow("dst(\u03B1 = -0.5)", dst1);
    imshow("dst(\u03B1 = 1.0)", dst);
    waitKey();
}
