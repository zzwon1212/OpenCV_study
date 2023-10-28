#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../src/week1_day3/";

int main()
{
    Mat src = imread(BASE_DIR + "lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 1. 밝기
    // 여기서 +-는 단순 사칙연산 기호가 아니라 OpenCV에서 지원한 연산자 오버로딩이다.
    // Mat - int 형태지만 자동으로 Mat - Scalar(int) 형태로 변형되고 연산자 오버로딩이 실행된다.
    // 아래 코드는 같은 결과를 출력한다.
    // Mat dst = src + 50;
    // Mat dst;
    // add(src, 50, dst);

    // 2. 반전
    Mat dst = 255 - src;

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
}
