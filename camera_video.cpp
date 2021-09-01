#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace cv;

int main()
{

	// 카메라 입력 처리
	/*
	VideoCapture cap(0);   // VideoCapture cap; cap.open(0);을 축약함
	if (!cap.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}

	cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	Mat frame, inversed;

	while (1)
	{
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27)
			break;
	}
	*/


	// 동영상 파일 처리
	/*
	VideoCapture cap("video.mp4");   // VideoCapture cap; cap.open("video.mp4");을 축약함
	if (!cap.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}
	
	cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;	
	
	double fps = cap.get(CAP_PROP_FPS);   // 동영상 FPS 값 확인
	cout << fps << endl;

	int delay = cvRound(1000 / fps);   // 프레임 사이의 시간 간격 계산

	Mat frame, inversed;
	while (1)
	{
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}
	*/


	// 시스템 기본 카메라로부터의 동영상을 파일로 저장
	/*
	VideoCapture cap(0);   // 시스템 기본 카메라 이용
	if (!cap.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));   // 카메라 프레임의 가로 크기 가져옴
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));   // 카메라 프레임의 세로 크기 가져옴
	double fps = cap.get(CAP_PROP_FPS);   // 카메라 프레임의 FPS 값 가져옴

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');   // DivX MPEG-4 코덱에 해당하는 fourcc 코드 생성
	int delay = cvRound(1000 / fps);   // 프레임 사이의 시간 간격을 ms 단위로 계산

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));   // output.avi 이름으로 저장
	if (!outputVideo.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}

	Mat frame, inversed;
	while (1)
	{
		cap >> frame;   // 카메라로부터 한 프레임을 받아와 frame에 저장
		if (frame.empty())
			break;

		inversed = ~frame;
		outputVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}
	*/


	// 직선, 마커 그리기
	/*
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));   // 400x400크기, 3채널, 흰색

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));   // (50, 50)에서 (200, 50)까지 빨간색 선을 두께 1로 그림
	line(img, Point(50, 100), Point(200, 100), Scalar(0, 255, 0), 3);   // (50, 100)에서 (200, 100)까지 초록색 선을 두께 3으로 그림
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);   // (50, 150)에서 (200, 150)까지 파랑색 선을 두께 10으로 그림

	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);   // (250, 50)에서 (350, 100)까지 빨간색 선을 LINE_4 타입(4방향 연결)으로 그림
	line(img, Point(250, 70), Point(350, 120), Scalar(0, 255, 0), 1, LINE_8);   // (250, 70)에서 (350, 120)까지 초록색 선을 LINE_8 타입(8방향 연결)으로 그림
	line(img, Point(250, 90), Point(350, 150), Scalar(255, 0, 0), 1, LINE_AA);   // (250, 90)에서 (350, 150)까지 빨간색 선을 LINE_AA 타입(안티에일리어싱)으로 그림

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);   // (50, 200)에서 (150, 200)까지 빨간색 선을 두께 1로 그림
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(0, 255, 0), 1);   // (50, 250)에서 (350, 250)까지 초록색 선을 두께 1로 그림
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);   // (50, 300)에서 (350, 300)까지 파랑색 선을 두께 1로 LINE_8 타입으로 축소 비율은 0으로 화살표 길이의 비율은 0.05로 그림

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);   // (50, 350)에서 빨간색 + 그림
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);   // (50, 350)에서 빨간색 x 그림
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);   // (150, 350)에서 빨간색 * 그림
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);   // (200, 350)에서 빨간색 ◇ 그림
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);   // (250, 350)에서 빨간색 □ 그림
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);   // (300, 350)에서 빨간색 △ 그림
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);   // (350, 350)에서 빨간색 ▽ 그림

	imshow("img", img);
	waitKey();
	*/


	// 사각형, 원 그리기
	/*
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), -2);   // (50, 50)에 빨간색으로 두께가 2인 사각형
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 255), -1);   // (50, 150)에 빨간색으로 내부가 채워진 사각형

	circle(img, Point(300, 120), 30, Scalar(0, 255, 0), -1, LINE_AA);   // (300, 120)에 반지름이 30인 내부가 채워진 초록색 원
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);   // (300, 120)에 반지름이 60인 두께가 3인 파랑색 원
	*/


	return 0;
}