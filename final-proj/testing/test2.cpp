// This does motion tracking by comparing two subsequent frames


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	int erosion_size=5;
	Mat frame1,frame2;
	Mat grayImage1,grayImage2;
	Mat differnceImage;
	Mat thresholdImage;
	namedWindow("Webcam Video");
	//default webcam device id=0;

	//check if the webcam was opened properly
	Mat element = getStructuringElement( MORPH_RECT,Size( 2*erosion_size + 1, 2*erosion_size+1 ),Point( erosion_size, erosion_size ) );

	VideoCapture cap(0);

	while (1)
	{
		//  cap.open(0);
		if(!cap.isOpened())
		{
			cout<<"Webcam can't be opened"<<endl;
			getchar();
			return -1;
		}

		cap.read(frame1);
		cvtColor(frame1,grayImage1,CV_RGB2GRAY);

		cap.read(frame2);
		cvtColor(frame2,grayImage2,CV_RGB2GRAY);

		absdiff(grayImage1,grayImage2,differnceImage);
		threshold(differnceImage,thresholdImage,5,255,CV_THRESH_BINARY);
		blur(thresholdImage,thresholdImage,Size(30,30));
		threshold(differnceImage,thresholdImage,5,255,CV_THRESH_BINARY);
		erode(thresholdImage,thresholdImage,element,Point(-1,-1));
		imshow("Theshold",thresholdImage);

		imshow("Webcam Video",frame1);

		switch(waitKey(10))
		{
			case 27:
				return -1;
				break;

		}


	}
}