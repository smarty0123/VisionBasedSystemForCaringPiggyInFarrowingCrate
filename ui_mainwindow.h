/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *browsePathButton;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    QLabel *lblCCTV1;
    QPushButton *settingButton;
    QPushButton *openCamButton;
    QPushButton *selectCaptureRegionButton;
    QCheckBox *showMaskRegionCheckBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 700);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        browsePathButton = new QPushButton(centralWidget);
        browsePathButton->setObjectName(QStringLiteral("browsePathButton"));
        browsePathButton->setGeometry(QRect(460, 20, 171, 61));
        QFont font;
        font.setPointSize(12);
        browsePathButton->setFont(font);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(1050, 90, 101, 51));
        playButton->setFont(font);
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(true);
        stopButton->setGeometry(QRect(1050, 250, 101, 51));
        stopButton->setFont(font);
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(1050, 170, 101, 51));
        pauseButton->setFont(font);
        lblCCTV1 = new QLabel(centralWidget);
        lblCCTV1->setObjectName(QStringLiteral("lblCCTV1"));
        lblCCTV1->setGeometry(QRect(50, 90, 891, 551));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        lblCCTV1->setFont(font1);
        lblCCTV1->setCursor(QCursor(Qt::ArrowCursor));
        lblCCTV1->setMouseTracking(true);
        lblCCTV1->setFrameShape(QFrame::Box);
        lblCCTV1->setFrameShadow(QFrame::Plain);
        lblCCTV1->setLineWidth(1);
        lblCCTV1->setMidLineWidth(0);
        lblCCTV1->setAlignment(Qt::AlignCenter);
        settingButton = new QPushButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        settingButton->setGeometry(QRect(800, 20, 141, 61));
        settingButton->setFont(font);
        openCamButton = new QPushButton(centralWidget);
        openCamButton->setObjectName(QStringLiteral("openCamButton"));
        openCamButton->setGeometry(QRect(250, 20, 181, 61));
        openCamButton->setFont(font);
        selectCaptureRegionButton = new QPushButton(centralWidget);
        selectCaptureRegionButton->setObjectName(QStringLiteral("selectCaptureRegionButton"));
        selectCaptureRegionButton->setGeometry(QRect(50, 20, 171, 61));
        selectCaptureRegionButton->setFont(font);
        showMaskRegionCheckBox = new QCheckBox(centralWidget);
        showMaskRegionCheckBox->setObjectName(QStringLiteral("showMaskRegionCheckBox"));
        showMaskRegionCheckBox->setGeometry(QRect(1040, 370, 181, 31));
        showMaskRegionCheckBox->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        browsePathButton->setText(QApplication::translate("MainWindow", "Import Video/Image", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        lblCCTV1->setText(QApplication::translate("MainWindow", "Display", nullptr));
        settingButton->setText(QApplication::translate("MainWindow", "Setting", nullptr));
        openCamButton->setText(QApplication::translate("MainWindow", "Select Capture Device", nullptr));
        selectCaptureRegionButton->setText(QApplication::translate("MainWindow", "Select Capture Region", nullptr));
        showMaskRegionCheckBox->setText(QApplication::translate("MainWindow", "Show Masked Region", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
