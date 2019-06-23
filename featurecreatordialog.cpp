#include "featurecreatordialog.h"
#include "ui_featurecreatordialog.h"
#include "opencv2/xfeatures2d.hpp"

using namespace cv::xfeatures2d;
using namespace cv;
using namespace std;

#define MIN_MATCH_COUNT 10

FeatureCreatorDialog::FeatureCreatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FeatureCreatorDialog)
{
    ui->setupUi(this);
    qTimer = new QTimer(this);
    capture.open(0);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
    qTimer->start(60);
    connect(ui->picLabel, SIGNAL(Mouse_pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->picLabel, SIGNAL(MousePressed()), this, SLOT(Mouse_pressed()));
}

FeatureCreatorDialog::~FeatureCreatorDialog()
{
    delete ui;
}

void FeatureCreatorDialog::processFrameAndUpdateGUI()
{
    if(!isPause){
        capture >> cvFrame;
        cv::resize(cvFrame, cvFrame, cv::Size(ui->picLabel->width(), ui->picLabel->height()));
        if(!cvFrame.empty()){
            QImage qtCCTV = convertOpenCVMatToQtQImage(cvFrame);
            ui->picLabel->setPixmap(QPixmap::fromImage(qtCCTV));
        }
    }else{
        qTimer->stop();
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////
QImage FeatureCreatorDialog::convertOpenCVMatToQtQImage(cv::Mat mat) {
    setMouseTracking(true);
    if(mat.channels() == 1) {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    } else if(mat.channels() == 3) {
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();
}

void FeatureCreatorDialog::Mouse_current_pos(){}

void FeatureCreatorDialog::Mouse_pressed()
{
    isPause = true;
    qTimer->stop();
    if(!isClicking){
        tempFrame = cvFrame.clone();
        drawFrame = tempFrame.clone();
        cv::cvtColor(drawFrame, drawFrame, cv::COLOR_RGB2GRAY);
        isClicking = true;
    }
    cv::Point point = cv::Point(ui->picLabel->x, ui->picLabel->y);
    points.push_back(point);
    circle(drawFrame, point, 1, Scalar(255, 255, 255), 1);
    cv::polylines(drawFrame, points, false, Scalar(255,255,255), 1);
    QImage qtCCTV = convertOpenCVMatToQtQImage(drawFrame);
    ui->picLabel->setPixmap(QPixmap::fromImage(qtCCTV));

}

void FeatureCreatorDialog::on_saveButton_clicked()
{
    if(!tempFrame.empty()){
        cv::Mat mask = cv::Mat::zeros(tempFrame.rows, tempFrame.cols, CV_8UC3);

        for(int i=0; i<mask.cols; i++)
            for(int j=0; j<mask.rows; j++)
                mask.at<uchar>(Point(i,j)) = 0;

        vector<Point> ROI_Poly;
        approxPolyDP(points, ROI_Poly, 1.0, true);

        fillConvexPoly(mask, &ROI_Poly[0], ROI_Poly.size(), Scalar(255,255,255), 0, 0);

        cv::bitwise_and(tempFrame, mask, tempFrame);

        cv::Rect rect = cv::boundingRect(points);

        tempFrame = tempFrame(rect);

        cvtColor(tempFrame, tempFrame, COLOR_BGR2GRAY);
        imwrite("feature image/feature.png", tempFrame);

        isPause = false;
        isClicking = false;
        points.clear();
        qTimer->start();
    }
}
