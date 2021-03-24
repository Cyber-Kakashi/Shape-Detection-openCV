#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img, imgBlur, imgGray, imgCanny, imgDil;

int main() {

	string path = "../Resources/shapes.png";
	img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
	Canny(imgBlur, imgCanny, 20, 70);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
	dilate(imgCanny, imgDil, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDil);
	waitKey(0);

	return 0;

}
