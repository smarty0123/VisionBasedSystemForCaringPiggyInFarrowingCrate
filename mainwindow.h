#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "QMediaPlayer"

#include<QtCore>
#include<QLabel>

#include <settingdialog.h>
#include <choosecamera.h>
#include <featurematching.h>
#include <selectcaptureregiondialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

private slots:
    void processFrameAndUpdateGUI();

    void on_browsePathButton_clicked();

    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_pauseButton_clicked();

    void on_settingButton_clicked();

    void on_openCamButton_clicked();

    void on_selectCaptureRegionButton_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    long int frameCount;

    bool isPlaying = false;

    bool isPause = false;

    long long frameNumber = 0;

    Ui::MainWindow *ui;

    QString fileName;

    cv::VideoCapture capture[6];

    QTimer* qTimer;

    QImage convertOpenCVMatToQtQImage(cv::Mat mat);

    cv::Mat preprocessFrame(cv::Mat cvFrame);

    void createBGS();

    void destroyBGS();

    void createBlob();

    void destroyBlob();

    void createAudio();

    void destroyAudio();

    void exitProgram();

    cv::Mat cvBlob;

    void processFrame(cv::Mat cvFrame, int capIndex, long int count);

    cv::Mat mask;

    int fps;

    QMediaPlayer * alertSound;

    SettingDialog *settingDialog;

    SelectCaptureRegionDialog *selectCaptureRegionDialog;

    ChooseCamera *chooseCamera;

    FeatureMatching *featureMatching;

    void initDialog();

    QVector<QLabel*> cctvLabels;

    int countDevice;



};

#endif // MAINWINDOW_H
