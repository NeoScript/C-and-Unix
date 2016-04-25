#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // create the widget

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n");};
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n");};

    //-- 2. Read the video stream
    capture.open(0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayFrame())); // connect the timer to the widget and to the method that will execute after every refresh
    timer -> start(1000/24); // set the time of refreshment and start the timer

}

void MainWindow::displayFrame()
{
// read one frame into frame
    capture >> frame;

    detectAndDisplay(frame);
// resize the Mat to the same size of the videoLabel
cv::resize(frame, frame, Size(ui->videoLabel->width(), ui->videoLabel->height()));
// convert the Mat from BGR to RGB
cvtColor(frame,frame,CV_BGR2RGB);
// create Qimage from Mat
QImage img= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
// create Qpixmap from Qimage
QPixmap pix = QPixmap::fromImage(img);
// display the pixmap on the videoLabel
ui->videoLabel->setPixmap(pix);

    frame.release();
}

void MainWindow::overlayImage(const Mat &background, const Mat &foreground, Mat &output, Point2i location)
{
  background.copyTo(output);


  // start at the row indicated by location, or at row 0 if location.y is negative.
  for(int y = std::max(location.y , 0); y < background.rows; ++y)
  {
    int fY = y - location.y; // because of the translation

    // we are done of we have processed all rows of the foreground image.
    if(fY >= foreground.rows)
      break;

    // start at the column indicated by location,

    // or at column 0 if location.x is negative.
    for(int x = std::max(location.x, 0); x < background.cols; ++x)
    {
      int fX = x - location.x; // because of the translation.

      // we are done with this row if the column is outside of the foreground image.
      if(fX >= foreground.cols)
        break;

      // determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
      double opacity = 1;
              //        ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])/ 255.;


      // and now combine the background and foreground pixel, using the opacity,

      // but only if opacity > 0.
      for(int c = 0; opacity > 0 && c < output.channels(); ++c)
      {
        unsigned char foregroundPx =
          foreground.data[fY * foreground.step + fX * foreground.channels() + c];
        unsigned char backgroundPx =
          background.data[y * background.step + x * background.channels() + c];
        output.data[y*output.step + output.channels()*x + c] =
          backgroundPx * (1.-opacity) + foregroundPx * opacity;
      }
    }
  }
}




/** @function detectAndDisplay */
void MainWindow::detectAndDisplay( Mat &frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray,
                                   faces,
                                   1.1,
                                   2,
                                   0|CASCADE_SCALE_IMAGE,
                                   Size(30, 30) );

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        Point overlaypoint(faces[i].x, faces[i].y);

        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        /**
        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI,
                                       eyes,
                                       1.1,
                                       2,
                                       0 |CASCADE_SCALE_IMAGE,
                                       Size(30, 30) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
        */


        int h=faces[i].height;
        int w=faces[i].width;

        if(!overlayMat.empty()){
            clock_t curr = time(0);

            if((curr - timeLastSet) > 1){
                overlayMat = backup;
                cv::resize(overlayMat, overlayMat, CvSize(w,h), 0,0, INTER_NEAREST);
                timeLastSet = time(0);
            }

        }

       overlayImage(frame, overlayMat, frame, overlaypoint);

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    timer->stop();
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/home/",
                "PNG files (*.png);; JPEG files (*.jpg);;");


    overlayMat = imread(filename.toStdString());

    timeLastSet = time(0);
    backup = overlayMat;
    timer->start();
}


void MainWindow::on_webcamPushButton_clicked()
{
    capture.open(0);
}

void MainWindow::on_videofilePushButton_clicked()
{
    timer-> stop();
    QString capfileString = QFileDialog::getOpenFileName(
                this,
                tr("Open Video File"),
                "/home/",
                "MP4 Files (*.mp4);; AVI Files (*.avi);;");
    std::string capfile = capfileString.toStdString();

    timer-> start();
    capture.open(capfile);
}
