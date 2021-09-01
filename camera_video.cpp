#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace cv;

int main()
{

	// ī�޶� �Է� ó��
	/*
	VideoCapture cap(0);   // VideoCapture cap; cap.open(0);�� �����
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


	// ������ ���� ó��
	/*
	VideoCapture cap("video.mp4");   // VideoCapture cap; cap.open("video.mp4");�� �����
	if (!cap.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}
	
	cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;	
	
	double fps = cap.get(CAP_PROP_FPS);   // ������ FPS �� Ȯ��
	cout << fps << endl;

	int delay = cvRound(1000 / fps);   // ������ ������ �ð� ���� ���

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


	// �ý��� �⺻ ī�޶�κ����� �������� ���Ϸ� ����
	/*
	VideoCapture cap(0);   // �ý��� �⺻ ī�޶� �̿�
	if (!cap.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));   // ī�޶� �������� ���� ũ�� ������
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));   // ī�޶� �������� ���� ũ�� ������
	double fps = cap.get(CAP_PROP_FPS);   // ī�޶� �������� FPS �� ������

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');   // DivX MPEG-4 �ڵ��� �ش��ϴ� fourcc �ڵ� ����
	int delay = cvRound(1000 / fps);   // ������ ������ �ð� ������ ms ������ ���

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));   // output.avi �̸����� ����
	if (!outputVideo.isOpened())
	{
		cout << "Open Error" << endl;
		return 0;
	}

	Mat frame, inversed;
	while (1)
	{
		cap >> frame;   // ī�޶�κ��� �� �������� �޾ƿ� frame�� ����
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


	// ����, ��Ŀ �׸���
	/*
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));   // 400x400ũ��, 3ä��, ���

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));   // (50, 50)���� (200, 50)���� ������ ���� �β� 1�� �׸�
	line(img, Point(50, 100), Point(200, 100), Scalar(0, 255, 0), 3);   // (50, 100)���� (200, 100)���� �ʷϻ� ���� �β� 3���� �׸�
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);   // (50, 150)���� (200, 150)���� �Ķ��� ���� �β� 10���� �׸�

	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);   // (250, 50)���� (350, 100)���� ������ ���� LINE_4 Ÿ��(4���� ����)���� �׸�
	line(img, Point(250, 70), Point(350, 120), Scalar(0, 255, 0), 1, LINE_8);   // (250, 70)���� (350, 120)���� �ʷϻ� ���� LINE_8 Ÿ��(8���� ����)���� �׸�
	line(img, Point(250, 90), Point(350, 150), Scalar(255, 0, 0), 1, LINE_AA);   // (250, 90)���� (350, 150)���� ������ ���� LINE_AA Ÿ��(��Ƽ���ϸ����)���� �׸�

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);   // (50, 200)���� (150, 200)���� ������ ���� �β� 1�� �׸�
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(0, 255, 0), 1);   // (50, 250)���� (350, 250)���� �ʷϻ� ���� �β� 1�� �׸�
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);   // (50, 300)���� (350, 300)���� �Ķ��� ���� �β� 1�� LINE_8 Ÿ������ ��� ������ 0���� ȭ��ǥ ������ ������ 0.05�� �׸�

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);   // (50, 350)���� ������ + �׸�
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);   // (50, 350)���� ������ x �׸�
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);   // (150, 350)���� ������ * �׸�
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);   // (200, 350)���� ������ �� �׸�
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);   // (250, 350)���� ������ �� �׸�
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);   // (300, 350)���� ������ �� �׸�
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);   // (350, 350)���� ������ �� �׸�

	imshow("img", img);
	waitKey();
	*/


	// �簢��, �� �׸���
	/*
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), -2);   // (50, 50)�� ���������� �β��� 2�� �簢��
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 255), -1);   // (50, 150)�� ���������� ���ΰ� ä���� �簢��

	circle(img, Point(300, 120), 30, Scalar(0, 255, 0), -1, LINE_AA);   // (300, 120)�� �������� 30�� ���ΰ� ä���� �ʷϻ� ��
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);   // (300, 120)�� �������� 60�� �β��� 3�� �Ķ��� ��
	*/


	return 0;
}