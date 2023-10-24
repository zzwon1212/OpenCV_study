#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("../weeks_days/week1_day2/lenna.bmp", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imwrite("../weeks_days/week1_day2/lenna.png", img);

    // namedWindow("image", WINDOW_NORMAL);
    imshow("image", img); // Mat은 unsigned char를 가지는 것이 바람직
    while (true) {
        if (waitKey() == 27) // ESC
            break;
    }
    // waitKey(5000); // imshow() 함수 호출 후에 waitKey() 함수를 호출해야 영상이 화면에 나타나므로 대부분의 경우 둘은 세트
    // destroyAllWindows();

    return 0;
}
