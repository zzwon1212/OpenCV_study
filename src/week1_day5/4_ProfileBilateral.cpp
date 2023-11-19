#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day5/";

void on_trackbar(int, void*);

Mat src, src_clone, dst, profile;
int row = 0;

int main(void)
{
    src = imread(BASE_DIR + "lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    TickMeter tm;
    tm.start();
    Mat dst;
    // GaussianBlur(src, src, Size(), 5);
    // src_clone = src.clone();
    // bilateralFilter(src_clone, src, -1, 10, 5);
    tm.stop();
    cout << "Time: " << tm.getTimeMilli() << endl;

    namedWindow("dst");
    namedWindow("profile");

    profile.create(256, src.cols, CV_8UC1);

    createTrackbar("Profile", "dst", &row, src.rows - 1, on_trackbar);
    on_trackbar(0, 0);

    waitKey();
}

void on_trackbar(int, void*)
{
    src.copyTo(dst);
    profile.setTo(255);

    uchar* pSrc = src.ptr<uchar>(row);
    uchar* pDst = dst.ptr<uchar>(row);

    for (int i = 1; i < src.cols; i++) {
        line(profile, Point(i - 1, 255 - pSrc[i - 1]), Point(i, 255 - pSrc[i]), 0);
        pDst[i] = saturate_cast<uchar>(pSrc[i] + 50);
    }

    imshow("dst", dst);
    imshow("profile", profile);
}
