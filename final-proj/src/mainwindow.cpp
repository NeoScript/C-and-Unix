#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief MainWindow::MainWindow
 * The constructor
 * instantiates the variables we need and loads in the files required to process faces.
 * @param parent parent widget (used for QT Applications)
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // create the widget

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n");};
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n");};

    ui->comboBox->addItem("<Select One>",QVariant::Int);
    ui->comboBox->addItem("Football",QVariant::Int);
    ui->comboBox->addItem("Smiley Face",QVariant::Int);
    ui->comboBox->addItem("Mad Face",QVariant::Int);
    ui->comboBox->addItem("Pikachu",QVariant::Int);
    ui->comboBox->addItem("Power Ranger",QVariant::Int);

    //-- 2. Read the video stream
    capture.open(0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayFrame())); // connect the timer to the widget and to the method that will execute after every refresh

    timer -> start(1000/24); // set the time of refreshment and start the timer

}
/**
 * This is perhaps the greatest template ever made.....
 */
template<class T>
inline T const& isValid(T const& a){
    return a;
}

/**
 * @brief MainWindow::displayFrame
 * This is the basic loop that will be called everytime the timer resets
 * It will read in a frame from the capture device and then process it
 * so that the output is how we would like before displaying it to the screen
 */
void MainWindow::displayFrame()
{
    bool canRead = capture.read(frame);
    if(!canRead){
        printError("Cannot read Webcam/inputVideo");
    }

    detectAndDisplay(frame);
    cv::resize(frame, frame, Size(ui->videoLabel->width(), ui->videoLabel->height()));

    //recording is handled here
    if(isValid(recording)){
       cout << "recording: " <<recorder.isOpened() << endl;
       recorder.write(frame);
    }
    // convert the Mat from BGR to RGB so that it looks normal
    cvtColor(frame,frame,CV_BGR2RGB);

    QImage img= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    QPixmap pix = QPixmap::fromImage(img);
    ui->videoLabel->setPixmap(pix);


    frame.release();

}
/**
 * @brief MainWindow::overlayImage
 * This method will overlay a given matrix over another matrix, and output it to the specified matrix/
 * @param background the background image
 * @param foreground the foreground image
 * @param output where to output the new image
 * @param location the position to overlay at (coordinates)
 */
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
      double opacity = ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])/ 255.;


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





/**
 * @brief MainWindow::detectAndDisplay
 * This function is used to detect the faces by using the OpenCV libaries, it then stores the faces into a vector
 * which is later traveresed and used to overlay the image
 * @param frame
 */
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

        if(!usingOverlay){
            ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        }

        //uncomment to re enable eye tracking
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

            if((curr - timeLastSet) > .1){
                overlayMat = backup;
                cv::resize(overlayMat, overlayMat, CvSize(w,h), 1,1, INTER_NEAREST);
                timeLastSet = time(0);
            }

        }

       overlayImage(frame, overlayMat, frame, overlaypoint);

    }


}
/**
 * @brief MainWindow::~MainWindow
 * Simple destructor to clear out pointers
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

/**
 * @brief MainWindow::on_browseButton_clicked
 * When the browse/custom image button is clicked it comes to this method
 *
 * It will check to see if an overlay is already being used, and if so it will clear it,
 * else it will open up a filedialog for the user to select a file
 */
void MainWindow::on_browseButton_clicked()
{
    if(usingOverlay){
        overlayMat.release();
        ui->browseButton->setText("Use Custom Image");
        usingOverlay = false;
    }else {
        timer->stop();
        QString filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "/home/",
                    "PNG files (*.png);; JPEG files (*.jpg);;");


        overlayMat = imread(filename.toStdString());

        timeLastSet = time(0);
        backup = overlayMat;
        usingOverlay = true;

        timer->start();
        ui->browseButton->setText("Clear");
    }

}


/**
 * @brief MainWindow::on_webcamPushButton_clicked
 * This method is called when the use webcam button
 * will open the webcam capture
 */
void MainWindow::on_webcamPushButton_clicked()
{
    capture.open(0);
}

/**
 * @brief MainWindow::on_videofilePushButton_clicked
 * This method is called when the use video file button is pushed.
 * It will open a file dialog and ask the user what file they would like to use for face detection.
 */
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

/**
 * @brief MainWindow::on_recordButton_clicked
 * will toggle the recording feature
 */
void MainWindow::on_recordButton_clicked()
{
    if(recording){
        //if recording -> stop recording
        recorder.release();
        ui->recordButton->setText("Start Recording");
        recording = false;

    }else{
        //if not recording -> start recording

        recorder.open("out.avi",CV_FOURCC('D','I','V','3'),24, Size(ui->videoLabel->width(),ui->videoLabel->height()));
        recording = true;

        cout << frame_width << frame_height<<(recorder.isOpened()? "yes":"no" )<< endl;

        ui->recordButton->setText("Stop Recording");
    }
}

/**
 * @brief MainWindow::on_comboBox_currentIndexChanged
 * called when the selected item in the dropdown box is changed
 * @param index the index of the new item
 */
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    cout << index << endl;

    usingOverlay = true;
    ui->browseButton->setText("Clear");
    switch(index){
        case 0: //default
            overlayMat = OverlayObject().getOverlay();
            usingOverlay = false;
            ui->browseButton->setText("Use Custom Image");
            break;

        case 1: //default
            overlayMat = FootballOverlay().getOverlay();
            break;

        case 2: //default
            overlayMat = SmileyOverlay().getOverlay();
            break;

        case 3: //default
            overlayMat = MadFaceOverlay().getOverlay();
            break;
        case 4: //default
            overlayMat = PikachuOverlay().getOverlay();
            break;
        case 5: //default
            overlayMat = PowerRangerOverlay().getOverlay();
            break;
    }

    backup = overlayMat;
}
