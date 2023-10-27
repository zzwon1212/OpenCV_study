#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string BASE_DIR = "../weeks_days/week1_day3/";

int main()
{
	// VideoCapture cap(0);
	VideoCapture cap(BASE_DIR + "test_video.mp4");

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return -1;
	}

	Mat frame;
	while (true) {
		cap >> frame;

		if (frame.empty()) {
			cerr << "Empty frame!" << endl;
			break;
		}

		Mat origin = frame.clone();

		line(frame, Point(570, 280), Point(0, 560), Scalar(255, 0, 0), 2);
		line(frame, Point(570, 280), Point(1024, 720), Scalar(255, 0, 0), 2);

		int pos = cvRound(cap.get(CAP_PROP_POS_FRAMES));
		String text = format("frame number: %d", pos);
		putText(frame, text, Point(20, 50), FONT_HERSHEY_SIMPLEX,
			0.7, Scalar(0, 0, 255), 1, LINE_AA);

		imshow("origin", origin);
		imshow("drawing", frame);

		if (waitKey(1) == 27)
			break;
	}

	cap.release();
	destroyAllWindows();
}
