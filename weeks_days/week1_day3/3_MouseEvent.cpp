#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

std::string BASE_DIR = "../weeks_days/week1_day3/";
Mat src;
Point ptOld;

void on_mouse(int event, int x, int y, int flags, void*);

int main()
{
	src = imread(BASE_DIR + "lenna.bmp");

	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", src);
	waitKey();
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			cout << "EVENT_MOUSEMOVE: " << x << ", " << y << endl;
			// circle(src, Point(x, y), 2, Scalar(0, 255, 255), -1, LINE_AA);
			line(src, ptOld, Point(x, y), Scalar(0, 255, 255), 3, LINE_AA);
			ptOld = Point(x, y);
			imshow("src", src);
		}
		break;
	default:
		break;
	}
}
