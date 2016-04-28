#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return the value returned by the application's execution
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
