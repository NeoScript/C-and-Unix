/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *videoLabel;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *browseButton;
    QPushButton *webcamPushButton;
    QPushButton *videofilePushButton;
    QPushButton *recordButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(986, 678);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(500, 500));
        centralWidget->setMaximumSize(QSize(1000, 1000));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 981, 671));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        videoLabel = new QLabel(verticalLayoutWidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        sizePolicy1.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy1);
        videoLabel->setMinimumSize(QSize(600, 600));
        videoLabel->setMaximumSize(QSize(1000, 800));
        videoLabel->setLayoutDirection(Qt::RightToLeft);
        videoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(videoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMaximumSize(QSize(200, 25));

        horizontalLayout->addWidget(comboBox);

        browseButton = new QPushButton(verticalLayoutWidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setMaximumSize(QSize(150, 25));
        browseButton->setFlat(false);

        horizontalLayout->addWidget(browseButton);

        webcamPushButton = new QPushButton(verticalLayoutWidget);
        webcamPushButton->setObjectName(QString::fromUtf8("webcamPushButton"));
        webcamPushButton->setMaximumSize(QSize(150, 25));
        webcamPushButton->setChecked(false);

        horizontalLayout->addWidget(webcamPushButton);

        videofilePushButton = new QPushButton(verticalLayoutWidget);
        videofilePushButton->setObjectName(QString::fromUtf8("videofilePushButton"));
        videofilePushButton->setMaximumSize(QSize(150, 25));

        horizontalLayout->addWidget(videofilePushButton);

        recordButton = new QPushButton(verticalLayoutWidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setMaximumSize(QSize(150, 25));

        horizontalLayout->addWidget(recordButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        videoLabel->setText(QApplication::translate("MainWindow", "Video goes here", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        webcamPushButton->setText(QApplication::translate("MainWindow", "Use Webcam", 0, QApplication::UnicodeUTF8));
        videofilePushButton->setText(QApplication::translate("MainWindow", "Use Video File", 0, QApplication::UnicodeUTF8));
        recordButton->setText(QApplication::translate("MainWindow", "Record", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
