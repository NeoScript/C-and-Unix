#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // create the widget

    /*
    capture.open(0);  //open video  to openwebcam replace “1.mp4” by 0
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayFrame())); // connect the timer to the widget and to the method that will execute after every refresh
    timer -> start(40); // set the time of refreshment and start the timer
    */

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n");};
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n");};

    //-- 2. Read the video stream
    capture.open(0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayFrame())); // connect the timer to the widget and to the method that will execute after every refresh
    timer -> start(20); // set the time of refreshment and start the timer
    /*
    if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n");}

    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }

        //-- 3. Apply the classifier to the frame
        detectAndDisplay( frame );

        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
    */
}

void MainWindow::displayFrame()
{
// read one frame into frame
    capture >> frame;

    detectAndDisplay(frame);

// resize the Mat to the same size of the label
cv::resize(frame, frame, Size(ui->label->width(), ui->label->height()));
// convert the Mat from BGR to RGB
cvtColor(frame,frame,CV_BGR2RGB);
// create Qimage from Mat
QImage img= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
// create Qpixmap from Qimage
QPixmap pix = QPixmap::fromImage(img);
// display the pixmap on the label
ui->label->setPixmap(pix);
}


/** @function detectAndDisplay */
void MainWindow::detectAndDisplay( Mat &frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }
    //-- Show what you got
    //displayFrame(frame);


}

MainWindow::~MainWindow()
{
    delete ui;
}
