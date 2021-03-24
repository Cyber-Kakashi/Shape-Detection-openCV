#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	string path = "../Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCropped;

	Rect roi(100, 100, 200, 300);
	imgCropped = img(roi);
	cout << "Image size: " << img.size() << endl;
	resize(img, imgResize, Size(), 0.7, 0.7);
	cout << "Resized Image: " << imgResize.size();
	imshow("Image", img);
	imshow("Image Scale", imgResize);
	imshow("Cropped Image", imgCropped);


	waitKey(0);
}