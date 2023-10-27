#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

string BASE_DIR = "../weeks_days/week1_day3/";

void MaskOp1();
void MaskOp2();

int main()
{
    // MaskOp1();
    MaskOp2();
}

void MaskOp1()
{
    Mat src = imread(BASE_DIR + "airplane.bmp", IMREAD_COLOR);
    Mat mask = imread(BASE_DIR + "mask_plane.bmp", IMREAD_GRAYSCALE);
    Mat dst = imread(BASE_DIR + "field.bmp", IMREAD_COLOR);

    if (src.empty() || mask.empty() || dst.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    imshow("background", dst);
    copyTo(src, dst, mask);
    // src.copyTo(dst, mask);

    imshow("src", src);
    imshow("mask", mask);
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
}

void MaskOp2()
{
    Mat src = imread(BASE_DIR + "cat.bmp", IMREAD_COLOR);
    // PNG 파일의 알파 채널을 살려야 하므로 IMREAD_UNCHANGED를 사용한다.
    Mat logo = imread(BASE_DIR + "opencv-logo-white.png", IMREAD_UNCHANGED);

    if (src.empty() || logo.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    // src 영상의 좌측 상단에서 로고 영상의 크기만큼 부분 영상을 추출(픽셀값이 원본 영상과 상호 참조됨)
    Mat crop = src(Rect(10, 10, logo.cols, logo.rows));

    // logo의 알파 채널을 이용해 마스크 영상 만들기
    vector<Mat> planes;
    split(logo, planes);
    Mat mask = planes[3];
    merge(vector<Mat>(planes.begin(), planes.begin() + 3), logo);

    imshow("crop", crop);
    imshow("mask", mask);
    imshow("logo", logo);

    // logo 영상과 crop 영상의 크기와 타입(BGR)이 같기 때문에
    // crop 영상은 새로 생성되는 것이 아니라
    // logo 영상을 기존 영상에서 mask 부분에만 복사함
    logo.copyTo(crop, mask);

    imshow("copy", crop);

    imshow("src", src);
    waitKey();
    destroyAllWindows();
}
