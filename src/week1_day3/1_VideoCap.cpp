#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	// VideoCapture cap(0);
	VideoCapture cap("../src/week1_day3/test_video.mp4");

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return -1;
	}

	// cap.set(CAP_PROP_FRAME_WIDTH, 1280);
	// cap.set(CAP_PROP_FRAME_HEIGHT, 720);
	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);
	cout << "w x h: " << w << "x" << h << endl;
	cout << "fps: " << fps << endl;

	Mat frame, edge;
	while (true) {
		cap >> frame;

		if (frame.empty()) {
			cerr << "Empty frame!" << endl;
			break;
		}

		Canny(frame, edge, 50, 150);
		imshow("frame", frame);
		imshow("edge", edge);

		if (waitKey(1) == 27)
			break;
	}

	cap.release();
	destroyAllWindows();
}
