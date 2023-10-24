#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

std::string BASE_DIR = "/home/jiwon/workspace/OpenCV_study/weeks_days/week1_day2/";

void MatOp1();
void MatOp2();
void MatOp3();
void MatOp4();
void MatOp5();

int main()
{
    // MatOp1();
    // MatOp2();
    // MatOp3();
    // MatOp4();
    MatOp5();
}

// # 영상의 생성과 초기화
void MatOp1()
{
    Mat img1;   // empty matrix

    Mat img2(480, 640, CV_8UC1);    // unsigned char, 1-channel
    Mat img3(480, 640, CV_8UC3);    // unsigned char, 3-channels
    Mat img4(Size(640, 480), CV_8UC3);  // Size(width, height)

    Mat img5(480, 640, CV_8UC1, Scalar(128));   // initial values, 128
    Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255)); // initial values, red

    Mat mat1 = Mat::zeros(3, 3, CV_32SC1);  // 0's matrix
    Mat mat2 = Mat::ones(3, 3, CV_32FC1);   // 1's matrix
    Mat mat3 = Mat::eye(3, 3, CV_32FC1);    // identify matrix

    // 24바이트의 메모리 공간을 사용하고, 그 시작 주소를 data라는 배열 이름으로 참조
    float data[] = {1, 2, 3, 4, 5, 6};
    // mat4가 data 주소를 참조하기 때문에 data나 mat4의 원소값을 변경하면 다른쪽도 똑같이 변경된다.
    Mat mat4(2, 3, CV_32FC1, data);
    data[0] = 100;
    cout << mat4 << endl;

    // 임의의 초기값을 가지고 있는 작은 크기의 행렬을 만들 때 유용함
    Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
    Mat mat6 = Mat_<uchar>({2, 3}, {1, 2, 3, 4, 5, 6});

    mat4.create(256, 256, CV_8UC3); // uchar, 3-channels
    mat5.create(4, 4, CV_32FC1);    // float, 1-channel

    mat4 = Scalar(255, 0, 0);
    mat5.setTo(1.f);
}

// # 영상의 참조와 복사
// = 연산자는 참조(얕은 복사)를 수행
// Mat::clone() 또는 Mat::copyTo() 함수를 이용하여 깊은 복사를 수행
void MatOp2()
{
    Mat img1 = imread(BASE_DIR + "dog.bmp");

    // img1을 생성자 인자로 전달해서 img2가 img1과 동일한 메모리 공간을 가리키도록 함
    // =는 생성자 인자 또는 초기화를 위한 연산자
    Mat img2 = img1; // -> Mat img2(img1);
    Mat img3;
    // =는 대입
    img3 = img1;
    // 위 방식들은 참조 형태로 동작
    // 즉, 메모리 공간에 dob.bmp 내용을 채워두고 img1 객체의 data 멤버 변수가 가리키도록 설정

    // clone()과 copyTo()는 동일한 동작을 수행
    Mat img4 = img1.clone();
    Mat img5;
    img1.copyTo(img5);
    // 위 방식들은 깊은 복사로 동작
    // 즉, 새로운 메모리 공간을 할당해서 img1의 data를 복사함

    img1.setTo(Scalar(0, 255, 255));    // yellow

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);

    waitKey();
    destroyAllWindows();
}

// # 부분 영상 추출
// Mat 객체에 대해 () 연산자를 이용하여 부분 영상 추출 가능
// () 연산자 안에는 Rect 객체를 지정하여 부분 영상의 위치와 크기를 지정
// 참조를 활용하여 ROI 연산 수행 가능
void MatOp3()
{
    Mat img1 = imread(BASE_DIR + "cat.bmp");

    // 예외 처리
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    // (x, y)는 좌측 상단
    Mat img2 = img1(Rect(220, 120, 340, 240));
    Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

    img2 = ~img2;

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);

    waitKey();
    destroyAllWindows();
}

// # Mat 영상의 픽셀 값 접근하기
// OpenCV에서 제공하는 기능이 아니라 자신만의 새로운 기능을 추가해야 하는 경우에 유용
// 기본적으로 Mat::data 멤버 변수가 픽셀 데이터 메모리 공간을 가리키지만, Mat 클래스 멤버 함수를 사용하는 방법을 권장
void MatOp4()
{
    Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

    for (int y = 0; y < mat1.rows; y++) {
        for (int x = 0; x < mat1.cols; x++) {
            // Mat은 일반적인 클래스인 것과 달리 at은 함수는 템플릿을 이용함
            // 그래서 현재 사용하고 있는 Mat 클래스 객체의 원소의 데이터 타입을 템플릿 인자로 지정해야 함
            // 반환 값은 참조이기 때문에 값을 받는 것뿐만 아니라 설정도 가능함
            mat1.at<uchar>(y, x)++;
        }
    }

    for (int y = 0; y < mat1.rows; y++) {
        // 템플릿을 사용하기 때문에 Mat 클래스 객체의 원소의 데이터 타입을 템플릿 인자로 지정해야 함
        // 지정한 타입에 대한 포인터 주소 값을 반환함
        // y행의 첫번째 원소의 주소를 반환하고 그 위치를 유캐릭터포인터P가 가리킴
        // 배열과 같은 형태로 [0]과 같이 접근할 수도 있고 아래와 같이
        // *(p + 0), *(p + 1)처럼 포인터 연산 형식으로 사용해도 됨
        uchar* p = mat1.ptr<uchar>(y);

        for (int x = 0; x < mat1.cols; x++) {
            p[x]++;
        }
    }

    // OpenCV는 Mat 클래스와 함께 사용할 수 있는 반복자 클래스 템플릿 MatIterator_를 제공
    // Mat::begin() 함수는 행렬의 첫번째 원소 위치를 반환
    // Mat::end() 함수는 행렬의 마지막 원소 바로 다음 위치를 반환
    // iterator 변수 it를 begin 함수가 반환하는 값으로 초기화를 하고,
    // 이 값이 end 함수가 반환하는 값과 같지 않을 때까지 iterator 값을 하나씩 증가시키면서
    // iterator가 가리키고 있는 위치의 값을 1씩 증가시킨다.
    for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
        (*it)++;
    }

    cout << "mat1:\n" << mat1 << endl;
}

// # 기초 행렬 연산
void MatOp5()
{
    float data[] = {1, 1, 2, 3};
    Mat mat1(2, 2, CV_32FC1, data);
    cout << "mat1:\n" << mat1 << endl;

    Mat mat2 = mat1.inv();
    cout << "mat2:\n" << mat2 << endl;

    cout << "mat1.t():\n" << mat1.t() << endl;
    cout << "mat1 + 3:\n" << mat1 + 3 << endl;
    cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
    cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}