//#include "opencv2/world.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include <iostream>
//
//#pragma comment(lib,"opencv_world412d.lib")
//
//using namespace  std;
//using namespace  cv;
//
//
//
//int main() {
//	resizeWindow("SourceImage", 800, 600);
//	cv::Mat templateImg;	
//	cv::Mat sourceImg=imread("MarkImg_0.bmp",IMREAD_GRAYSCALE);
//	Mat showSrc = sourceImg.clone();
//	resize(showSrc, showSrc, Size(), 0.2, 0.2);
//	imshow("SourceImage", showSrc);
//	waitKey(0);
//
//	templateImg.zeros(500,500,CV_8UC3);
//	Rect roi(Point(1500, 1500), Point(2000, 2000));
//	sourceImg(roi).copyTo(templateImg);
//	imshow("template",templateImg);
//	waitKey(0);
//
//	waitKey(0);	
//	int winsize = 500;
//	Mat tmpImg;
//	double d1 = 0;// 
//	double d2 = 0;// = matchShapes(im1, im2, CONTOURS_MATCH_I2, 0);
//	double d3 = 0;// =matchShapes(im1, im2, CONTOURS_MATCH_I3, 0);
//	double min1 = 1;
//	double min2 = 1;
//	double min3 = 1;
//	Point p1,p2,p3;
//	
//	
//	for (int i=0;i<sourceImg.cols-winsize-30;i+=30)
//	{
//		for (int j = 0; j < sourceImg.rows-winsize-30; j+=30)
//		{
//			sourceImg(Rect(Point(i, j), Point(i+winsize, j+winsize))).copyTo(tmpImg);
//			imshow("source", tmpImg);
//			waitKey(1);
//			d1 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I1, 0);
//			d2 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I2, 0);
//			d3 = matchShapes(tmpImg, templateImg, CONTOURS_MATCH_I3, 0);
//			if (d1<min1)
//			{
//				p1.x = i, p1.y = j;
//			}
//			if (d2 < min2)
//			{
//				p2.x = i, p2.y = j;
//			}
//			if (d3 < min3)
//			{
//				p3.x = i, p3.y = j;
//			}
//			min1 = min1 < d1 ? min1 : d1;
//			min2 = min2 < d2 ? min2 : d2;
//			min3 = min3 < d3 ? min3 : d3;
//			printf("dis:%f-%f-%f\nmin:%f-%f-%f\n", d1, d2, d3,min1,min2,min3);
//		}
//	}
//	sourceImg(Rect(p1, Point(p1.x+ winsize, p1.y + winsize))).copyTo(tmpImg);
//	printf("min:%f-%f-%f", min1, min2, min3);
//	imshow("match",tmpImg);
//	waitKey(0);
//	return 0;
//}





//特征匹配的函数需要包含contirbe
#include <opencv2/opencv.hpp>
//#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"
using namespace std;
using namespace cv;
//using namespace cv::xfeatures2d;

#pragma comment(lib,"opencv_world412d.lib")

const int MAX_FEATURES = 1500; 	//控制最多可以检测到的特征点对数
const float GOOD_MATCH_PERCENT = 0.15f;


//void alignImages(Mat &im1, Mat &im2, Mat &im1Reg, Mat &h)
//
//{
//
//	// Convert images to grayscale
//	Mat im1Gray, im2Gray;
//	cvtColor(im1, im1Gray, COLOR_BGR2GRAY);
//	cvtColor(im2, im2Gray, COLOR_BGR2GRAY);
//
//	// Variables to store keypoints and descriptors
//	std::vector<KeyPoint> keypoints1, keypoints2;
//	Mat descriptors1, descriptors2;
//
//	// Detect ORB features and compute descriptors.
//	Ptr<Feature2D> orb = ORB::create(MAX_FEATURES);
//	orb->detectAndCompute(im1Gray, Mat(), keypoints1, descriptors1);
//	orb->detectAndCompute(im2Gray, Mat(), keypoints2, descriptors2);
//
//	// Match features.
//	std::vector<DMatch> matches;
//	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
//	matcher->match(descriptors1, descriptors2, matches, Mat());
//
//	// Sort matches by score
//	std::sort(matches.begin(), matches.end());
//
//	// Remove not so good matches
//	const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
//	matches.erase(matches.begin() + numGoodMatches, matches.end());
//
//
//	// Draw top matches
//	Mat imMatches;
//	drawMatches(im1, keypoints1, im2, keypoints2, matches, imMatches);
//	imwrite("matches.jpg", imMatches);
//
//
//	// Extract location of good matches
//	std::vector<Point2f> points1, points2;
//
//	for (size_t i = 0; i < matches.size(); i++)
//	{
//		points1.push_back(keypoints1[matches[i].queryIdx].pt);
//		points2.push_back(keypoints2[matches[i].trainIdx].pt);
//	}
//
//	// Find homography
//	h = findHomography(points1, points2, RANSAC);
//
//	// Use homography to warp image
//	warpPerspective(im1, im1Reg, h, im2.size());
//
//}


int main1111(int argc, char **argv)
{
	//// Read reference image
	//string refFilename("dst.jpg");
	//cout << "Reading reference image : " << refFilename << endl;
	//Mat imReference = imread(refFilename);
	//imshow("ref",imReference);
	//waitKey(0);
	//resize(imReference, imReference, cv::Size(50,100));
	//imshow("ref", imReference);
	//waitKey(0);

	//// Read image to be aligned
	//string imFilename("src.jpg");
	//cout << "Reading image to align : " << imFilename << endl;
	//Mat im = imread(imFilename);
	//imshow("im", im);
	//waitKey(0);

	//// Registered image will be resotred in imReg. 
	//// The estimated homography will be stored in h. 
	//Mat imReg, h;

	//// Align images
	//cout << "Aligning images ..." << endl;
	//alignImages(im, imReference, imReg, h);

	//// Write aligned image to disk. 
	//string outFilename("aligned.jpg");
	//cout << "Saving aligned image : " << outFilename << endl;
	//imwrite(outFilename, imReg);
	//imshow("imreg", imReg);
	//waitKey(0);

	//// Print estimated homography
	//cout << "Estimated homography : \n" << h << endl;


	//for ()
	//{
	//}

	for (int i=9;i<11;i++)
	{
		
		string filePath=string("D:\\Code\\PAD_IMAGE\\NG_PAD\\")+ std::to_string(i)+string(".bmp");
		Mat threeChanelImg = cv::imread(filePath, CV_8UC1);
		if (threeChanelImg.empty())
		{
			return 1;
		}

		imshow("img", threeChanelImg);
		waitKey(0);
		bool bRtn = imwrite(filePath, threeChanelImg);
		if (!bRtn)
		{
			std::cout << "error" << std::endl;
		}
	}
	


	return 0;
}



#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;

void thresh_callback(int pos,void *) {}
int main11(int argc, char** argv)
{

	Mat src;

	string filePath = string("D:\\Code\\PAD_IMAGE\\Glue\\") + std::to_string(1) + string(".bmp");
	// the first command-line parameter must be a filename of the binary
	// (black-n-white) image
	if (!(src = imread(filePath, CV_8UC1)).data)
		return -1;
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	//src = src > 1;
	namedWindow("Source", 1);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	Mat threshd;
	int thresh=0;
	createTrackbar("thresh", "Source", &thresh, 255, thresh_callback);
	while (true)
	{

	}
	threshold(src, threshd,0, 230, THRESH_BINARY);
	imshow("thresh", threshd);
	waitKey(0);
	findContours(threshd, contours, hierarchy,
		RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	// iterate through all the top-level contours,
	// draw each connected component with its own random color
	int idx = 0;
	for (; idx >= 0; idx = hierarchy[idx][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, idx, color, FILLED, 8, hierarchy);
	}
	namedWindow("Components", 1);
	imshow("Components", dst);
	waitKey(0);
}