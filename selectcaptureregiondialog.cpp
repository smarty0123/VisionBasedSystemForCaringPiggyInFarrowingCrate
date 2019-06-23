#include "selectcaptureregiondialog.h"
#include "ui_selectcaptureregiondialog.h"
#include "QDebug"
#include "QMessageBox"

using namespace cv;
using namespace std;
SelectCaptureRegionDialog::SelectCaptureRegionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectCaptureRegionDialog)
{
    ui->setupUi(this);

    connect(ui->firstFrameLabel, SIGNAL(Mouse_pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->firstFrameLabel, SIGNAL(MousePressed()), this, SLOT(Mouse_pressed()));
}

SelectCaptureRegionDialog::~SelectCaptureRegionDialog()
{
    delete ui;
}

void SelectCaptureRegionDialog::setFirstFrame(cv::Mat frame)
{
    firstFrame = frame.clone();

    Mat tempFirstFrame = firstFrame.clone();

    if(!points.empty()){
        cv::polylines(tempFirstFrame, points, false, Scalar(0,0,255), 2);
    }

    //set widget size
    this->resize(tempFirstFrame.size().width+100, tempFirstFrame.size().height+200);

    //set button position
    ui->ConfirmButton->setGeometry(tempFirstFrame.size().width-ui->ConfirmButton->width(), 20,ui->ConfirmButton->width(), ui->ConfirmButton->height());
    ui->ClearMaskButton->setGeometry(tempFirstFrame.size().width-(ui->ConfirmButton->width()*2)-40, 20, ui->ClearMaskButton->width(), ui->ClearMaskButton->height());


    //set image size
    ui->firstFrameLabel->setGeometry(30, ui->ClearMaskButton->height()+40,tempFirstFrame.size().width, tempFirstFrame.size().height);
    QImage qtFirstFrame = convertOpenCVMatToQtQImage(tempFirstFrame);
    ui->firstFrameLabel->setPixmap(QPixmap::fromImage(qtFirstFrame));
}




QImage SelectCaptureRegionDialog::convertOpenCVMatToQtQImage(cv::Mat mat) {
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

void SelectCaptureRegionDialog::Mouse_current_pos(){}

void SelectCaptureRegionDialog::Mouse_pressed()
{
    tempFrame = firstFrame.clone();
    Point point = Point(ui->firstFrameLabel->x, ui->firstFrameLabel->y);
    tempPoints.push_back(point);
    circle(tempFrame, point, 1, Scalar(0, 0, 255), 2);
    cv::polylines(tempFrame, tempPoints, false, Scalar(0,0,255), 2);
    QImage qtCCTV = convertOpenCVMatToQtQImage(tempFrame);
    ui->firstFrameLabel->setPixmap(QPixmap::fromImage(qtCCTV));
}



void SelectCaptureRegionDialog::on_ClearMaskButton_clicked()
{
    tempPoints.clear();
    QImage qtFirstFrame = convertOpenCVMatToQtQImage(firstFrame);
    ui->firstFrameLabel->setPixmap(QPixmap::fromImage(qtFirstFrame));
}

void SelectCaptureRegionDialog::on_ConfirmButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Create Capture Region", "Are you sure to save?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        setCaptureRegionPoints(tempPoints);
        close();
    } else {
    }
}


void SelectCaptureRegionDialog::setCaptureRegionPoints(std::vector<Point> tempPoints)
{
    points = tempPoints;
}

std::vector<Point> SelectCaptureRegionDialog::getCaptureRegionPoints()
{
    return points;
}
