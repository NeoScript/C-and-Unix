#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> //the widget
#include <QtCore> //the timer to refresh th widget
#include <QFileDialog>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui; // the widget

private:
    QTimer *timer; // the timer that will refresh the widget
    VideoCapture capture;  // to capture video
    Mat frame; // the frame that we will copy readed images from video
    Mat overlayMat;
    Mat backup;

    double timeLastSet;

    /** Global variables */
    String face_cascade_name = "haarcascade_frontalface_alt.xml";
    String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    String window_name = "Capture - Face detection";


    void overlayImage(const Mat &background, const Mat &foreground, Mat &output, Point2i location);

    void detectAndDisplay(Mat &frame);
private slots:
    void displayFrame(); // the method that will display video
    void on_browseButton_clicked();
    void on_webcamPushButton_clicked();
    void on_videofilePushButton_clicked();
};

#endif // MAINWINDOW_H
