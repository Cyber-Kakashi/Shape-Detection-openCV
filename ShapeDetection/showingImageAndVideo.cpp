#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//int main() {
//	// showing image
//	
//	string path = "../Resources/test.png";
//	Mat img = imread(path);
//	imshow("This is some image", img);
//	waitKey(0);
//
//	return 0;
//}

int main() {
	VideoCapture vid(0);
	Mat img;

	while (true) {
		vid.read(img);
		imshow("Some video", img);
		waitKey(1);
	}

	return 0;
}