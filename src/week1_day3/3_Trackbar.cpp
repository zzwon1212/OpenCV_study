#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata);

int main(void)
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");
	// 세번째 인자는 트랙바의 위치값을 받아올 정수형 변수의 주소를 지정한다.
	// 아래처럼 NULL 값을 지정할 경우에는 반드시 트랙바 콜백 함수를 지정해야 한다.
	// 트랙바 콜백 함수의 첫번째 인자로 현재 트랙바의 위치가 전달된다.
	// userdata에서는 void 포인터 타입 형식으로 로컬 변수 img의 주소값을 전달한다.
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	imshow("image", img);
	waitKey();
}

void on_level_change(int pos, void* userdata)
{
	// img의 주소값이 트랙바 콜백 함수의 userdata쪽으로 전달된다.
	// 전달되는 시점은 사용자가 트랙바를 움직인 경우에 트랙바 콜백 함수가 호출되고
	// userdata는 void 포인터 타입으로 전달됐지만 Mat 클래스의 포인터(트티)? 형식으로 변환하고
	// 다시 *를 이용해서 img 변수를 참조한다. 이렇게 할 경우
	// main 함수의 img와 여기의 img는 완전히 동일한 영상 데이터를 가리킨다.
	Mat img = *(Mat*)userdata;

	// pos라는 정수값은 0부터 16 사이로 설정이 될 수 있는데,
	// img 영상의 모든 픽셀값을 pos에 16을 곱한 값으로 설정한다.
	img.setTo(pos * 16);
	imshow("image", img);
}
