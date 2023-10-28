#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day3/";

int main(void)
{
    Mat src = imread(BASE_DIR + "lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 히스토그램
    // 256개 크기의 정수형 배열을 선언하고 각 배열값을 0으로 초기화
    int hist[256] = {};
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            // 영상의 모든 픽셀값을 참조하고
            // 이 픽셀값을 hist 배열의 인덱스로 지정하고
            // 해당 인덱스값을 하나씩 증가
            hist[src.at<uchar>(y, x)]++;
        }
    }

    // 정규화된 히스토그램
    int size = (int)src.total();
    float nhist[256] = {};
    for (int i = 0; i < 256; i++) {
        nhist[i] = (float)hist[i] / size;
    }

    // 히스토그램 그래프 그리기
    int histMax = 0;
    for (int i = 0; i < 256; i++) {
        if (hist[i] > histMax) histMax = hist[i];
    }

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        line(imgHist, Point(i, 100),
            Point(i, 100 - cvRound(hist[i] * 100 / histMax)), Scalar(0));
    }

    imshow("src", src);
    imshow("hist", imgHist);
    waitKey();
}