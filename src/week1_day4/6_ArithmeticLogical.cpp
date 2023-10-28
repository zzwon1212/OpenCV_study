#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day4/";

int main(void)
{
    Mat src1 = imread(BASE_DIR + "lenna256.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread(BASE_DIR + "square.bmp", IMREAD_GRAYSCALE);

    if (src1.empty() || src2.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    if (src1.size() != src2.size() || src1.type() != src2.type()) {
        cerr << "The images are different in size or type!" << endl;
    }

    imshow("src1", src1);
    imshow("src2", src2);

    Mat dst1, dst2, dst3, dst4;

    // 1. 산술 연산
    // add(src1, src2, dst1);
    // addWeighted(src1, 0.5, src2, 0.5, 0, dst2);
    // subtract(src1, src2, dst3);
    // absdiff(src1, src2, dst4);

    // 2. 논리 연산
    bitwise_and(src1, src2, dst1);
    bitwise_or(src1, src2, dst2);
    bitwise_xor(src1, src2, dst3);
    // bitwise_not(src1, dst4);
    dst4 = ~src1;

    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("dst4", dst4);
    waitKey();
}
