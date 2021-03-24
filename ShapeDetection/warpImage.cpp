#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp;
int main() {

	string path = "../Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {93, 633}, {64, 324}, {337, 279}, {400, 573} };
	Point2f dst[4] = { {0, h}, {0,0}, {w, 0}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Size(w, h));

	imshow("Image", img);
	imshow("Warp Image", imgWarp);
	waitKey(0);

	return 0;
}
