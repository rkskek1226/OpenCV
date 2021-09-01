#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace cv;

int main()
{

	/*
	Mat img1;
	Mat img2(480, 640, CV_8UC1);
	Mat img3(480, 640, CV_8UC3);
	Mat img4(Size(640, 480), CV_8UC3);
	Mat img5(480, 640, CV_8UC1, Scalar(128));
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));

	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);

	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);

	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<uchar>({ 2,3 }, { 1,2,3,4,5,6 });

	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);

	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);


	Mat test1 = imread("lenna.bmp");
	Mat test2 = test1.clone();
	Mat test3;
	test1.copyTo(test3);
	*/


	/*
	Mat img1 = imread("cat.bmp");
	Mat img2 = img1(Rect(220, 120, 340, 240)).clone();
	img2 = ~img2;

	imshow("1", img1);
	imshow("2", img2);

	waitKey();
	*/


	/*
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int i = 0; i < mat1.rows; i++)
		for (int j = 0; j < mat1.cols; j++)
			mat1.at<uchar>(i, j)++;

	for (int i = 0; i < mat1.rows; i++)
	{
		uchar* p = mat1.ptr<uchar>(i);
		for (int j = 0; j < mat1.cols; j++)
			p[j]++;
	}

	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++)
		(*it)++;


	cout << mat1 << endl;
	*/

	/*
	Mat img1 = imread("lenna.bmp");
	cout << img1.cols << endl;
	cout << img1.rows << endl;
	cout << img1.channels() << endl;
	cout << img1.isContinuous() << endl;
	cout << img1.size() << endl;
	cout << img1.total() << endl;
	cout << img1.type() << endl;
	cout << img1 << endl;
	*/

	/*
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat1 : " << mat1 << endl;
	cout << "mat2 : " << mat2 << endl;

	cout << "mat1.t() : " << mat1.t() << endl;
	cout << "mat1+3 : " << mat1 + 3 << endl;
	cout << "mat1+mat2 : " << mat1 + mat2 << endl;
	cout << "mat1*mat2 : " << mat1 * mat2 << endl;
	*/

	/*
	uchar data[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Mat mat1(3, 4, CV_8UC1, data);
	Mat mat2 = mat1.reshape(0, 1);

	cout << mat1 << endl;
	cout << mat2 << endl;

	mat1.resize(5, 100);
	cout << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << mat1 << endl;

	mat3.pop_back(1);
	cout << mat3 << endl;
	*/

	/*
	Scalar gray = 128;
	cout << gray << endl;
	Scalar yellow(0, 255, 255);
	cout << yellow << endl;

	Mat img(256, 256, CV_8UC3, yellow);
	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl;
	*/

int num[] = { 2,4,1,5,3 };
sort(num, num + 5,greater<int>());

for(int n:num)
	cout<<n<<"   ";







	return 0;
	
}