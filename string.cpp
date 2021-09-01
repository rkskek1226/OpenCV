#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace cv;

int main()
{

	// 문자열 출력
	/*
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));
	putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));   // (20, 50)에 FONT_HERSHEY_SIMPLEX 글씨체를 빨간색으로 문자열 출력
	*/

	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));
	Size textSize = getTextSize("Hello OpenCV", FONT_HERSHEY_TRIPLEX, 2.0, 1, 0);   // Hello OpenCV 문자열 출력을 위한 사각형 영역의 크기를 측정
	Size imgSize = img.size();

	Point org((imgSize.width - textSize.width) / 2, (imgSize.height + textSize.height) / 2);   // 문자열을 중앙에 출력하기 위한 좌표
	putText(img, "Hello OpenCV", org, FONT_HERSHEY_TRIPLEX, 2.0, Scalar(255, 0, 0), 1);   // 중앙에 문자열 출력
	rectangle(img, org, org + Point(textSize.width, -textSize.height), Scalar(255, 0, 0), 1);   //  문자열을 감싸는 사각형 그림

	imshow("img", img);
	waitKey();










	return 0;
}