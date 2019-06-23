#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QFileDialog>
#include<QInputDialog>
#include<QMouseEvent>
#include<QEvent>
#include <iostream>

using namespace cv;
////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cctvLabels.append(ui->lblCCTV1);
    frameCount = 0;
    initDialog();
    setMouseTracking(true);
    qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
}

/////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::exitProgram() {
    if(qTimer->isActive()) qTimer->stop();
    QApplication::quit();
}

////////////////////////////////////////////////////////////
void MainWindow::initDialog(){
    settingDialog = new SettingDialog(this);
    chooseCamera = new ChooseCamera(this);
    selectCaptureRegionDialog = new SelectCaptureRegionDialog(this);
}

/////////////////////////////////////////////////////////////////
void MainWindow::createAudio(){
    alertSound = new QMediaPlayer();
    alertSound->setMedia(QUrl("qrc:/sounds/res/alert.mp3"));
}
/////////////////////////////////////////////////////////////////
void MainWindow::destroyAudio(){
    delete alertSound;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::processFrameAndUpdateGUI() {
    if(isPlaying){
        if(!isPause){
            for(int i=0;i<countDevice;i++){
                Mat cvFrame;
                capture[i] >> cvFrame;
                if(!cvFrame.empty()){
                    processFrame(cvFrame, i, frameCount);
                    frameCount++;
                }else{
                    isPlaying = false;
                    destroyAudio();
                    capture[i].release();
                    if(qTimer->isActive()){
                        qTimer->stop();
                    }
                    std::cout<<"End()"<<std::endl;
                }
            }
        }
    }

}
//////////////////////////////////////////////////////////////////////////////////////////
cv::Mat MainWindow::preprocessFrame(const Mat cvFrameSmall){
    //convert to image grayscale
    Mat cvFrameGray;
    Mat cvFrameBlur;
    cvtColor(cvFrameSmall, cvFrameGray, CV_BGR2GRAY);
    GaussianBlur(cvFrameGray, cvFrameBlur, Size(5,5), 3, 3);
    return cvFrameBlur;
}

///////////////////////////////////////////////////////////////////
void MainWindow::processFrame(Mat cvFrame, int capIndex, long int frameCount){
    if(frameCount == 0){
        if(!selectCaptureRegionDialog->getCaptureRegionPoints().empty()){
            featureMatching = new FeatureMatching(selectCaptureRegionDialog->getCaptureRegionPoints());
        }else{
            featureMatching = new FeatureMatching();
        }

    }
    Mat cvFrameResult;
    if(ui->showMaskRegionCheckBox->isChecked()){
        cvFrameResult = featureMatching->process(cvFrame, frameCount, true, settingDialog, fps);
    }else{
        cvFrameResult = featureMatching->process(cvFrame, frameCount, false, settingDialog, fps);
    }

    if(featureMatching->isAlert()){
        if(!settingDialog->getIsNotAlert()){
            alertSound->play();
        }else{
            alertSound->stop();
        }
    }else{
        alertSound->stop();
    }

    cv::resize(cvFrameResult, cvFrameResult, cv::Size(cctvLabels[capIndex]->width(), cctvLabels[capIndex]->height()));
    QImage qtCCTV = convertOpenCVMatToQtQImage(cvFrameResult);
    cctvLabels[capIndex]->setPixmap(QPixmap::fromImage(qtCCTV));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
QImage MainWindow::convertOpenCVMatToQtQImage(Mat mat) {
    setMouseTracking(true);
    if(mat.channels() == 1) {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    } else if(mat.channels() == 3) {
        cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_browsePathButton_clicked(){
    destroyAllWindows();
    QString filter = "Video Files (*.mp4 *.avi *.mov *.wmv);; Image Files (*.png *.jpg *.bmp) ;; All File (*.*)";
    fileName = QFileDialog::getOpenFileName(this, "Open File", "A://Learning/DatasetImage/Piggy", filter);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_playButton_clicked(){
    if(!isPause){
        settingDialog = new SettingDialog(this);
        if(!chooseCamera->getCheckedDevice().empty()){
            countDevice = chooseCamera->getCheckedDevice().length();
        }else{
            countDevice = 0;
        }
        if(countDevice != 0){
            isPlaying = true;
            cctvLabels[0]->clear();
            capture[0].open(0);
            fps = 10;
            createAudio();
            qTimer->start(20);
        }else{
            isPlaying = true;
            std::string videoFileName = fileName.toStdString();
            qDebug() << videoFileName.c_str();
            std::cout << "Openning: " << videoFileName << std::endl;
            capture[0].open(videoFileName.c_str());
            fps = static_cast<int>(capture[0].get(CV_CAP_PROP_FPS));
            countDevice++;
            createAudio();
            qTimer->start(20);
        }
    }else{
        isPause = false;
    }


}

//////////////////////////////////////////////////////////
void MainWindow::on_pauseButton_clicked()
{
    if(isPlaying){
        isPause = true;
        alertSound->pause();
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_stopButton_clicked(){
    if(isPlaying){
        delete settingDialog;
        delete featureMatching;
        frameCount = 0;
        qTimer->stop();
        destroyAllWindows();
        if(cctvLabels.size() != 0){
            for(int i=0;i<cctvLabels.size();i++){
                cctvLabels[i]->clear();
                capture[i].release();
                cctvLabels[i]->setText("Display");
            }
        }
        isPlaying = false;
        isPause = false;
        destroyAudio();
    }
}

////////////////////////////////////////////////////////
void MainWindow::on_settingButton_clicked()
{
    settingDialog = new SettingDialog(this, isPlaying);
    settingDialog->show();
}

////////////////////////////////////////////////////////
void MainWindow::on_openCamButton_clicked()
{
    chooseCamera->show();
}

////////////////////////////////////////////////////////////////
void MainWindow::on_selectCaptureRegionButton_clicked()
{
    if(!fileName.isNull()){
        VideoCapture video(fileName.toStdString());

        video.set(CV_CAP_PROP_POS_FRAMES, 0);
        Mat firstFrame;

        bool success = video.read(firstFrame);
        if (success){
            selectCaptureRegionDialog->setFirstFrame(firstFrame);
            selectCaptureRegionDialog->show();
        }else{
            qDebug() << "Cannot read frame ";
        }

    }else{
        if(countDevice != 0){
            Mat frame;
            capture[0].open(0);
            capture[0] >> frame;
            if(!frame.empty()){
                Mat firstFrame;
                selectCaptureRegionDialog->setFirstFrame(frame);
                selectCaptureRegionDialog->show();
            }
        }

    }

}
