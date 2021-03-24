#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img, imgHSV, imgMask;
int hmin = 0, hmax = 179, vmin = 0, vmax = 255, smin = 0, smax = 255;

int main() {
	string path = "../Resources/test.png";
	img = imread(path);
	VideoCapture vid(0);

	namedWindow("TrackBars", (640, 200));
	createTrackbar("H min", "TrackBars", &hmin, 179);
	createTrackbar("H max", "TrackBars", &hmax, 179);
	createTrackbar("S min", "TrackBars", &smin, 255);
	createTrackbar("S max", "TrackBars", &smax, 255);
	createTrackbar("V min", "TrackBars", &vmin, 255);
	createTrackbar("V max", "TrackBars", &vmax, 255);


	while (true) {
		vid.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		imshow("Original", img);
		imshow("HSV image", imgHSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, imgMask);
		imshow("Image Mask", imgMask);
		waitKey(1);
	}


	return 0;
}
