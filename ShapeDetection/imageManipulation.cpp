#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	string path = "../Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur1, imgBlur2, imgCanny1, imgCanny2, imgErode1, imgErode2, imgDil1, imgDil2;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur1, Size(3, 3), 1, 1);
	GaussianBlur(img, imgBlur2, Size(7, 7), 1, 1);
	Canny(img, imgCanny1, 25, 75);
	Canny(img, imgCanny2, 5, 150);

	Mat kernel1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(2, 5));
	dilate(imgCanny1, imgDil1, kernel1);
	dilate(imgCanny2, imgDil2, kernel2);
	erode(imgDil1, imgErode1, kernel1);
	erode(imgDil2, imgErode2, kernel2);

	imshow("Gray Scale", imgGray);
	imshow("Blur image", imgBlur1);
	imshow("Blur2 image", imgBlur2);
	imshow("canny1 image", imgCanny1);
	imshow("canny2 image", imgCanny2);
	imshow("erode1 image", imgErode1);
	imshow("erode2 image", imgErode2);
	imshow("dilate1 image", imgDil1);
	imshow("dilate2 image", imgDil2);

	waitKey(0);
}