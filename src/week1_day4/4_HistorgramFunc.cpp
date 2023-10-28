#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day4/";

// 히스토그램을 반환
Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = {graylevel};

    // &img: img 변수의 주소
    // 1: 영상 1장
    // channels: 값으로 0 하나를 가지는 배열
    // Mat(): 마스크가 없기 때문에 영상 전체에 대해서 히스토그램을 계산
    // hist: 비어있는 Mat 객체의 이름 -> 256x1 CV_32FC1의 2차원 행렬이 만들어짐
    // dims: 출력 히스토그램의 차원
    // histSize: 그레이스케일 값의 단계, 256 값을 가지는 배열의 이름
    // ranges: 0번 채널의 최솟값/최댓값을 가지는 배열의 이름을 인자로 받는 배열의 이름
    calcHist(&img, 1, channels, Mat(), hist, dims, histSize, ranges);

    return hist;
}

// 히스토그램 영상을 반환
Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax = 0.;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        line(imgHist, Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i) * 100 / histMax)), 0);
    }

    return imgHist;
}

int main(void)
{
    Mat src = imread(BASE_DIR + "lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 원본
    // Mat src_hist = calcGrayHist(src);
    // Mat src_imgHist = getGrayHistImage(src_hist);
    // imshow("src", src);
    // imshow("src_hist", src_imgHist);

    // 밝기 감소
    // Mat bright_down = src - 30;
    // Mat bright_down_hist = calcGrayHist(bright_down);
    // Mat bright_down_imgHist = getGrayHistImage(bright_down_hist);\
    // imshow("bright_down", bright_down);
    // imshow("bright_down_hist", bright_down_imgHist);

    // 밝기 증가
    // Mat bright_up = src + 30;
    // Mat bright_up_hist = calcGrayHist(bright_up);
    // Mat bright_up_imgHist = getGrayHistImage(bright_up_hist);\
    // imshow("bright_up", bright_up);
    // imshow("bright_up_hist", bright_up_imgHist);

    // 명도 감소
    double alpha_down = -0.3;
    Mat contrast_down = src + (src - 128) * alpha_down;
    Mat contrast_down_hist = calcGrayHist(contrast_down);
    Mat contrast_down_imgHist = getGrayHistImage(contrast_down_hist);\
    imshow("contrast_down", contrast_down);
    imshow("contrast_down_hist", contrast_down_imgHist);

    // 명도 증가
    double alpha_up = 0.3;
    Mat contrast_up = src + (src - 128) * alpha_up;
    Mat contrast_up_hist = calcGrayHist(contrast_up);
    Mat contrast_up_imgHist = getGrayHistImage(contrast_up_hist);\
    imshow("contrast_up", contrast_up);
    imshow("contrast_up_hist", contrast_up_imgHist);

    waitKey();
}
