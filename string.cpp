#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace cv;

int main()
{

	// ���ڿ� ���
	/*
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));
	putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));   // (20, 50)�� FONT_HERSHEY_SIMPLEX �۾�ü�� ���������� ���ڿ� ���
	*/

	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));
	Size textSize = getTextSize("Hello OpenCV", FONT_HERSHEY_TRIPLEX, 2.0, 1, 0);   // Hello OpenCV ���ڿ� ����� ���� �簢�� ������ ũ�⸦ ����
	Size imgSize = img.size();

	Point org((imgSize.width - textSize.width) / 2, (imgSize.height + textSize.height) / 2);   // ���ڿ��� �߾ӿ� ����ϱ� ���� ��ǥ
	putText(img, "Hello OpenCV", org, FONT_HERSHEY_TRIPLEX, 2.0, Scalar(255, 0, 0), 1);   // �߾ӿ� ���ڿ� ���
	rectangle(img, org, org + Point(textSize.width, -textSize.height), Scalar(255, 0, 0), 1);   //  ���ڿ��� ���δ� �簢�� �׸�

	imshow("img", img);
	waitKey();










	return 0;
}