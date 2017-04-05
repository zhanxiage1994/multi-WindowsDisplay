#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

const int DISPLAYWINDOWS = 3;
const int ImageWidth = 1280;
const int ImageHeight = 800;

int main(int argc,char* argv[])
{
	Mat RImg = imread("R.bmp");
	Mat GImg = imread("G.bmp");
	Mat BImg = imread("B.bmp");
	Mat disLoop[DISPLAYWINDOWS] = {RImg,GImg,BImg};

	stringstream winName;
	for(int i = 0;i < DISPLAYWINDOWS;i++)
	{
		winName.clear();winName.str("");
		winName<<i;
		namedWindow(winName.str(),CV_WINDOW_NORMAL);
		cv::moveWindow(winName.str(),1920 + ImageWidth * i,0);
		setWindowProperty(winName.str(), CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN );
	}
	
	for(int i = 0;i < DISPLAYWINDOWS;i++)
	{
		winName.clear();winName.str("");
		winName<<i;
		imshow(winName.str(),disLoop[i]);
		waitKey(1);
	}
	while(waitKey() != 27);
	destroyAllWindows();

	system("pause");
	return 0;
}
