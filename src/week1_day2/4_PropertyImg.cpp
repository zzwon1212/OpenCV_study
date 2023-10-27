#include <iostream>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("../weeks_days/week1_day2/lenna.bmp");

    cout << "Width: " << img.cols << endl;
    cout << "Height: " << img.rows << endl;
    cout << "Channels: " << img.channels() << endl;

    if (img.type() == CV_8UC1)
        cout << "img is a grayscale image." << endl;
    else if (img.type() == CV_8UC3)
        cout << "img is a truecolor image." << endl;
}
