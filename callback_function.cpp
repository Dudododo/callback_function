#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

string Window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;

	threshold(src, dst, th, 255, 0);
	imshow(Window_name, dst);
}

int main()
{
	Mat srcMat;
	Mat gryMat;

	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("C:\\Users\\duzhi\\Pictures\\Saved Pictures\\1.jpg");
	if (!srcMat.data)
	{
		cout << "wrong" << endl;
		return 0;
	}

	cvtColor(srcMat, gryMat, COLOR_BGR2GRAY);

	imshow(Window_name, gryMat);
	createTrackbar("threshold",
							Window_name,
							&lowTh,
							maxTh,
							threshod_Mat,
							&gryMat
							);
	waitKey(0);
	return 0;
}

