#include "choosecamera.h"
#include "ui_choosecamera.h"
#include "opencv2/opencv.hpp"
#include "QDebug"

ChooseCamera::ChooseCamera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseCamera)
{
    EnumeratorCam = countCamera();
    qDebug() << "There is " << EnumeratorCam << " camera available.";

    ui->setupUi(this);

    QStringList columnTitleList;
    ui->tableWidget->setRowCount(EnumeratorCam);
    ui->tableWidget->setColumnCount(2);
    columnTitleList << "อุปกรณ์" << "สถานะ";
    ui->tableWidget->setHorizontalHeaderLabels(columnTitleList);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->hide();

    for(int i=0; i<EnumeratorCam; i++){
        QTableWidgetItem* deviceName = new QTableWidgetItem();
        deviceName->setText("กล้องที่ " + QString::number(i+1));
        deviceName->setFlags(deviceName->flags() | Qt::ItemIsUserCheckable);
        deviceName->setCheckState(Qt::Checked);

        QTableWidgetItem* deviceStatus = new QTableWidgetItem();
        deviceStatus->setText("ใช้งานได้");
        deviceStatus->setTextColor(QColor(0, 255, 0));
        deviceStatus->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0 , deviceName);
        ui->tableWidget->setItem(i, 1, deviceStatus);
    }

}

ChooseCamera::~ChooseCamera()
{
    delete ui;
}


void ChooseCamera::on_buttonBox_accepted()
{
    checkedDeviceList.clear();
    for(int i=0; i<EnumeratorCam; i++){
        if(ui->tableWidget->item(i, 0)->checkState()){
            qDebug() << "Camera " + QString::number(i+1) + " is checked.";
            checkedDeviceList.append(i);
        }
    }

}

int ChooseCamera::countCamera(){
    cv::VideoCapture temp_camera;
    int test = 30;
    for (int i = 0; i < test; i++){
      cv::VideoCapture temp_camera(i);
      bool isNotOpen = (!temp_camera.isOpened());
      temp_camera.release();
      if (isNotOpen){
        return i;
      }
    }
    return test;
}

QList<int> ChooseCamera::getCheckedDevice(){
    return checkedDeviceList;
}
