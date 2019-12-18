#include "opencv2/world.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

#pragma comment(lib,"opencv_world412d.lib")

using namespace  std;
using namespace  cv;

int main() {
	resizeWindow("SourceImage", 800, 600);
	cv::Mat templateImg;	
	cv::Mat sourceImg=imread("MarkImg_0.bmp",IMREAD_GRAYSCALE);
	resizeWindow("SourceImage", 800, 600);
	imshow("SourceImage", sourceImg);
	waitKey(0);

	templateImg.zeros(100,100,CV_8UC3);
	Rect roi(Point(1500, 1500), Point(2000, 2000));
	sourceImg(roi).copyTo(templateImg);
	imshow("template",templateImg);
	waitKey(0);

	waitKey(0);	
	int winsize = 500;
	Mat tmpImg;
	double d1 = 0;// 
	double d2 = 0;// = matchShapes(im1, im2, CONTOURS_MATCH_I2, 0);
	double d3 = 0;// =matchShapes(im1, im2, CONTOURS_MATCH_I3, 0);
	double min1 = 1;
	double min2 = 1;
	double min3 = 1;
	Point p1,p2,p3;
	
	
	for (int i=0;i<sourceImg.cols-winsize-30;i+=30)
	{
		for (int j = 0; j < sourceImg.rows-winsize-30; j+=30)
		{
			sourceImg(Rect(Point(i, j), Point(i+winsize, j+winsize))).copyTo(tmpImg);
			imshow("source", tmpImg);
			waitKey(1);
			d1 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I1, 0);
			d2 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I2, 0);
			d3 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I3, 0);
			if (d1<min1)
			{
				p1.x = i, p1.y = j;
			}
			if (d2 < min2)
			{
				p2.x = i, p2.y = j;
			}
			if (d3 < min3)
			{
				p3.x = i, p3.y = j;
			}
			min1 = min1 < d1 ? min1 : d1;
			min2 = min2 < d2 ? min2 : d2;
			min3 = min3 < d3 ? min3 : d3;
			printf("dis:%f-%f-%f\nmin:%f-%f-%f\n", d1, d2, d3,min1,min2,min3);
		}
	}
	sourceImg(Rect(p1, Point(p1.x+ winsize, p1.y + winsize))).copyTo(tmpImg);
	printf("min:%f-%f-%f", min1, min2, min3);
	imshow("match",tmpImg);
	waitKey(0);
	return 0;
}