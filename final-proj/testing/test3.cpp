//
// Created by nasir on 3/28/16.
//


#include <highgui.h>
#include <opencv2/videoio.hpp>
#include <cv.hpp>

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;

void trackbarMove(int, void*){};
void showTrackbars(){
	std::string winName = "Trackbars";
	cv::namedWindow(winName.c_str(), CV_WINDOW_NORMAL);

	cv::createTrackbar("H_MIN", winName.c_str(), &H_MIN, H_MAX, trackbarMove);
	cv::createTrackbar("H_MAX", winName.c_str(), &H_MAX, H_MAX, trackbarMove);

	cv::createTrackbar("S_MIN", winName.c_str(), &S_MIN, S_MAX, trackbarMove);
	cv::createTrackbar("S_MAX", winName.c_str(), &S_MAX, S_MAX, trackbarMove);

	cv::createTrackbar("V_MIN", winName.c_str(), &V_MIN, V_MAX, trackbarMove);
	cv::createTrackbar("V_MAX", winName.c_str(), &V_MAX, V_MAX, trackbarMove);
}
int main(){
	cv::namedWindow("main 1", CV_WINDOW_AUTOSIZE);

	cv::Mat img;
	cv::VideoCapture cap(0);
	cv::waitKey(33);

	if(!cap.isOpened()){
		return -1;
	}

	showTrackbars();
	while(cvWaitKey(33)){
		cv::Mat currFrame;
		cap >> currFrame;
		cv::imshow("main 1", currFrame);
	}
}