#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<opencv2\opencv.hpp>
#include<gl/glut.h>

using namespace std;
using namespace cv;

const GLint ImageWidth = 1280;
const GLint ImageHeight = 800;

static GLubyte* PixelData1;
static GLubyte* PixelData2;

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(ImageWidth,ImageHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData1);
	glutSwapBuffers();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(ImageWidth,ImageHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData2);
	glutSwapBuffers();
}

int main(int argc,char* argv[])
{
	
	Mat RImg = imread("R.bmp");
	Mat GImg = imread("G.bmp");
	PixelData1 = RImg.data;
	PixelData2 = GImg.data;

	int window1 = 0,window2 = 0;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(ImageWidth,ImageHeight);

	glutInitWindowPosition(1920,0);
	window1 = glutCreateWindow("1");
	glutDisplayFunc(display1);

	glutInitWindowPosition(1920+1280,0);
	window2 = glutCreateWindow("2");
	glutDisplayFunc(display2);

	glutMainLoop();

	system("pause");
	return 0;
}




//static GLubyte* PixelData;
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glDrawPixels(ImageWidth*3,ImageHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData);
//	glutSwapBuffers();
//}
//
//int main(int argc,char* argv[])
//{
//	
//	Mat RImg = imread("R.bmp");
//	Mat GImg = imread("G.bmp");
//	Mat BImg = imread("B.bmp");
//	Mat SynImg = Mat::zeros(ImageHeight,ImageWidth*3,CV_8UC3);
//	RImg.copyTo(SynImg(Rect(0,0,ImageWidth,ImageHeight)));
//	GImg.copyTo(SynImg(Rect(ImageWidth,0,ImageWidth,ImageHeight)));
//	BImg.copyTo(SynImg(Rect(ImageWidth*2,0,ImageWidth,ImageHeight)));
//	imwrite("Sys.bmp",SynImg);
//	PixelData = SynImg.data;
//
//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(0,0);
//	glutInitWindowSize(ImageWidth*3,ImageHeight);
//	glutCreateWindow("1");
//	glutDisplayFunc(display);
//	glutMainLoop();
//
//	system("pause");
//	return 0;
//}