#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(256, 256), 255, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(100, 200), Point(412, 312), Scalar(255, 255, 255), FILLED);
	line(img, Point(100, 340), Point(412, 340), Scalar(255, 255, 255), 4);
	putText(img, "This is my text", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(255, 0, 0), 3);

	imshow("Image", img);

	waitKey(0);
}