/**
* @file Threshold.cpp
* @brief Sample code that shows how to use the diverse threshold options offered by OpenCV
* @author OpenCV team
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
using std::cout;

/// Global variables

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int max_binary_value = 255;

Mat src, src_gray, dst;
const char* window_name = "Threshold Demo";

const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";


int RangeValueThresh(cv::Mat &src, cv::Mat &dst,unsigned int iMin/*=0*/, unsigned int iMax/*=255*/)
{

	int bRtn = true;
	if (src.empty())
	{
		return false;
	}
	if (dst.size!=src.size)
	{
		src.copyTo(dst);
	}

	uchar iValue = 0;
	for (int x = 0; x < src.rows; x++)
	{
		for (int y = 0; y < src.cols; y++)
		{
			iValue = src.at<uchar>(x, y);
			if (iValue > iMin && src.at<uchar>(x, y) < iMax)
			{
				//dst.at<uchar>(x, y) = 255;
			}
			else
			{
				dst.at<uchar>(x, y) = 0;
			}
		}
	}

	return bRtn;
}
//![Threshold_Demo]
/**
* @function Threshold_Demo
*/
static void Threshold_Demo(int, void*)
{
	/* 0: Binary
	1: Binary Inverted
	2: Threshold Truncated
	3: Threshold to Zero
	4: Threshold to Zero Inverted
	*/
	//threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
	RangeValueThresh(src_gray, dst, threshold_value, max_binary_value);
	
	vector<vector<cv::Point>> cvContours;
	vector<vector<cv::Point>> cvContoursInRange;//过滤掉小轮廓后
	vector<cv::Vec4i> cvHierarchy;
	findContours(dst, cvContours, cvHierarchy, 0, 0, cv::Point(0,0));
	double dArea = 0, dLength = 0;
	for (int contourIndex = 0; contourIndex < cvContours.size(); contourIndex++)  //计算每个轮廓的面积
	{
		dArea = cv::contourArea(cvContours[contourIndex]) + (rand() % 10000) / 10000.0;
		if (dArea < 100)
		{
			continue;
		}
		cvContoursInRange.push_back(cvContours[contourIndex]);
	}
	drawContours(dst, cvContours, -1, Scalar(255, 10, 10), -1);
	imshow(window_name, dst);
}
static void Threshold_Demo1(int, void*)
{
	/* 0: Binary
	1: Binary Inverted
	2: Threshold Truncated
	3: Threshold to Zero
	4: Threshold to Zero Inverted
	*/
	//threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
	RangeValueThresh(src_gray, dst, threshold_value, max_binary_value);
	imshow(window_name, dst);
}
//![Threshold_Demo]

/**
* @function main
*/
int main_test(int argc, char** argv)
{
	using namespace std;
	string filePath = string("D:\\Code\\PAD_IMAGE\\Glue\\") + std::to_string(1) + string(".bmp");

	src = imread(samples::findFile(filePath), IMREAD_COLOR); // Load an image
	

	if (src.empty())
	{
		cout << "Cannot read the image: " << filePath << std::endl;
		return -1;
	}
	
	cvtColor(src, src_gray, COLOR_BGR2GRAY); // Convert the image to Gray
											 //! [load]

											 //! [window]
	namedWindow(window_name, WINDOW_AUTOSIZE); // Create a window to display results
											   //! [window]

											   //! [trackbar]
	createTrackbar(trackbar_type,
		window_name, &threshold_type,
		max_type, Threshold_Demo); // Create a Trackbar to choose type of Threshold

	createTrackbar(trackbar_value,
		window_name, &threshold_value,
		max_value, Threshold_Demo); // Create a Trackbar to choose Threshold value
									//! [trackbar]
	createTrackbar("thresh_big",
		window_name, &max_binary_value,
		max_value, Threshold_Demo1); // Create a Trackbar to choose Threshold value

	Threshold_Demo(0, 0); // Call the function to initialize

						  /// Wait until the user finishes the program
	waitKey();
	return 0;
}
