#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day5/";

int main(void)
{
    Mat src = imread(BASE_DIR + "lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

#if 0 // 1. 평균값 필터
    imshow("src", src);

    // 1.1. filter2D()를 이용한 평균값 필터
    // Mat kernel = Mat::ones(3, 3, CV_32FC1) / 9.f;
    // Mat dst;
    // filter2D(src, dst, -1, kernel);

    // 1.2. 블러링 함수 blur()를 이용한 평균값 필터(3x3, 5x5, 7x7)
    Mat dst;
    for (int ksize = 3; ksize <= 7; ksize += 2) {
        blur(src, dst, Size(ksize, ksize));

        String desc = format("Mean: %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }
#else // 2. 가우시안 필터
    Mat dst;
    for (int sigma = 1; sigma <= 5; sigma++) {
        TickMeter tm;
        tm.start();

        // src의 타입이 uchar일 경우 시그마x가 1이면 커널 사이즈는 7x7(6시그마+1)이 된다.
        GaussianBlur(src, dst, Size(), sigma);

        tm.stop();
        cout << "sigma: " << sigma << ", time: " << tm.getTimeMilli() << " ms." << endl;

        String desc = format("Sigma = %d", sigma);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }
#endif
}
