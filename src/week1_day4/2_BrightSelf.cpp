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

#if 0
    Mat dst = src + 50;
#else
    Mat dst(src.rows, src.cols, src.type());

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            // at은 템플릿으로 정의되어 있기 때문에 영상에서 사용되는 데이터 타입을 지정해줘야 함
            // src의 x, y 좌표 픽셀값을 참조 형태로 uchar 타입으로 반환함
            // uchar + int = int. uchar에 260을 저장하려고 하면 256을 뺀 값인 4를 저장함
            // int v = src.at<uchar>(y, x) + 50;
            // if (v < 0) v = 0;
            // if (v > 255) v = 255;
            // if 두 번보다는 삼항 연산자를 이용해보자.
            // v = (v > 255) ? 255 : (v < 0) ? 0 : v;
            dst.at<uchar>(y, x) = saturate_cast<uchar>(src.at<uchar>(y, x) + 50);
        }
    }
#endif

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
}
