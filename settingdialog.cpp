#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "QDebug"
#include<QFileDialog>

#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

SettingDialog::SettingDialog(bool isFromFeatureMatching){
    loadConfig();
}


SettingDialog::SettingDialog(QWidget *parent, bool isPlaying) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{

    loadConfig();

    ui->setupUi(this);
    ui->lostPigMinSb->setValue(timeLostMinute);
    ui->lostPigSecSB->setValue(timeLostSecond);

    if(isNotAlert){
        ui->muteAlertCheckBox->setChecked(true);
    }

    if(isOriginalDisplay){
        ui->OriginalDisplayCB->setChecked(true);
    }
    if(isShowFeatureDetected){
        ui->showFeatureDetectedCB->setChecked(true);
    }
    if(isShowFeatureMatchingResult){
        ui->showFeatureMatchingResultCB->setChecked(true);
    }
    if(isSaveSnapshot){
        ui->saveSnapshotCB->setChecked(true);
    }
    if(isSaveAlertSnapshot){
        ui->saveAlertSnapshotCB->setChecked(true);
    }
    if(isSaveKeypointSanpshot){
        ui->saveKeypointSnapshotCB->setChecked(true);
    }


    ui->nFeaturesLineEdit->setText(QString::number(nfeatures));
    ui->nOctaveLayersLineEdit->setText(QString::number(nOctaveLayers));
    ui->contrastThresholdLineEdit->setText(QString::number((double)contrastThreshold));
    ui->edgeThresholdLineEdit->setText(QString::number((double)edgeThreshold));
    ui->sigmaLineEdit->setText(QString::number((double)sigma));
    if(isPlaying){
        ui->nFeaturesLineEdit->setDisabled(true);
        ui->nOctaveLayersLineEdit->setDisabled(true);
        ui->contrastThresholdLineEdit->setDisabled(true);
        ui->edgeThresholdLineEdit->setDisabled(true);
        ui->sigmaLineEdit->setDisabled(true);
    }
    if(isUsingFrame){
        ui->usingFrameRadio->setChecked(true);
        ui->frameSleepLineEdit->setDisabled(false);
        ui->frameSleepLineEdit->setText(QString::number(frameSleep));
    }
    if(isUsingTime){
        ui->usingTimeRadio->setChecked(true);
        ui->timeSleepLineEdit_2->setDisabled(false);
        ui->timeSleepLineEdit_2->setText(QString::number(timeSleep));
    }

    ui->sleepThresholdLineEdit->setText(QString::number(sleepThreshold));

    ui->MoveThresholdLineEdit->setText(QString::number(moveThreshold));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}


void SettingDialog::on_buttonBox_accepted()
{
    timeLostMinute = ui->lostPigMinSb->value();
    timeLostSecond = ui->lostPigSecSB->value();

    isNotAlert = ui->muteAlertCheckBox->isChecked();
    isOriginalDisplay = ui->OriginalDisplayCB->isChecked();

    isShowFeatureDetected = ui->showFeatureDetectedCB->isChecked();
    isShowFeatureMatchingResult = ui->showFeatureMatchingResultCB->isChecked();

    isSaveSnapshot = ui->saveSnapshotCB->isChecked();
    isSaveAlertSnapshot = ui->saveAlertSnapshotCB->isChecked();
    isSaveKeypointSanpshot = ui->saveKeypointSnapshotCB->isChecked();

    nfeatures = ui->nFeaturesLineEdit->text().split(" ")[0].toInt();
    nOctaveLayers = ui->nOctaveLayersLineEdit->text().split(" ")[0].toInt();
    contrastThreshold = ui->contrastThresholdLineEdit->text().split(" ")[0].toDouble();
    edgeThreshold = ui->edgeThresholdLineEdit->text().split(" ")[0].toDouble();
    sigma = ui->sigmaLineEdit->text().split(" ")[0].toDouble();


    frameSleep = ui->frameSleepLineEdit->text().split(" ")[0].toInt();
    timeSleep = ui->timeSleepLineEdit_2->text().split(" ")[0].toInt();

    if(ui->usingTimeRadio->isChecked()){
        isUsingTime = true;
        isUsingFrame = false;
    }

    if(ui->usingFrameRadio->isChecked()){
        isUsingFrame = true;
        isUsingTime = false;
    }

    sleepThreshold = ui->sleepThresholdLineEdit->text().split(" ")[0].toInt();

    moveThreshold = ui->MoveThresholdLineEdit->text().split(" ")[0].toInt();

    saveConfig();
}

void SettingDialog::saveConfig()
{
    CvFileStorage* fs = cvOpenFileStorage("config/Setting.xml", 0, CV_STORAGE_WRITE);

    cvWriteString(fs, "featureImage", fileName.toLocal8Bit().constData());
    cvWriteInt(fs, "timeLostMinute", timeLostMinute);
    cvWriteInt(fs, "timeLostSecond", timeLostSecond);
    cvWriteInt(fs, "muteAlertSound", isNotAlert);
    cvWriteInt(fs, "originalDisplay", isOriginalDisplay);
    cvWriteInt(fs, "isShowFeatureDetected", isShowFeatureDetected);
    cvWriteInt(fs, "isShowFeatureMatchingResult", isShowFeatureMatchingResult);
    cvWriteInt(fs, "isSaveSnapshot", isSaveSnapshot);
    cvWriteInt(fs, "isSaveAlertSnapshot", isSaveAlertSnapshot);
    cvWriteInt(fs, "isSaveKeypointSanpshot", isSaveKeypointSanpshot);

    cvWriteInt(fs, "nfeatures", nfeatures);
    cvWriteInt(fs, "nOctaveLayers", nOctaveLayers);
    cvWriteReal(fs, "contrastThreshold", contrastThreshold);
    cvWriteReal(fs, "edgeThreshold", edgeThreshold );
    cvWriteReal(fs, "sigma", sigma);

    cvWriteInt(fs, "frameSleep", frameSleep);
    cvWriteInt(fs, "timeSleep", timeSleep);

    cvWriteInt(fs, "isUsingFrame", isUsingFrame);
    cvWriteInt(fs, "isUsingTime", isUsingTime);

    cvWriteInt(fs, "sleepThreshold", sleepThreshold);

    cvWriteInt(fs, "moveThreshold", moveThreshold);

    cvReleaseFileStorage(&fs);
}

void SettingDialog::loadConfig()
{
    CvFileStorage* fs = cvOpenFileStorage("config/Setting.xml", 0, CV_STORAGE_READ);

    totalPig = cvReadIntByName(fs, 0, "totalPig");
    timeLostMinute = cvReadIntByName(fs, 0, "timeLostMinute");
    timeLostSecond = cvReadIntByName(fs, 0, "timeLostSecond");
    isNotAlert = cvReadIntByName(fs, 0, "muteAlertSound");
    isOriginalDisplay = cvReadIntByName(fs, 0, "originalDisplay");

    isShowFeatureDetected = cvReadIntByName(fs, 0, "isShowFeatureDetected");
    isShowFeatureMatchingResult = cvReadIntByName(fs, 0, "isShowFeatureMatchingResult");

    isSaveSnapshot = cvReadIntByName(fs, 0, "isSaveSnapshot");
    isSaveAlertSnapshot = cvReadIntByName(fs, 0, "isSaveAlertSnapshot");
    isSaveKeypointSanpshot = cvReadIntByName(fs, 0, "isSaveKeypointSanpshot");
    fileName = cvReadStringByName(fs, 0, "featureImage");

    nfeatures = cvReadIntByName(fs, 0, "nfeatures");
    nOctaveLayers = cvReadIntByName(fs, 0, "nOctaveLayers");
    contrastThreshold = cvReadRealByName(fs, 0, "contrastThreshold");
    edgeThreshold = cvReadRealByName(fs, 0, "edgeThreshold");
    sigma = cvReadRealByName(fs, 0, "sigma");

    frameSleep = cvReadIntByName(fs, 0, "frameSleep");
    timeSleep = cvReadIntByName(fs, 0, "timeSleep");

    isUsingTime = cvReadIntByName(fs, 0, "isUsingTime");
    isUsingFrame = cvReadIntByName(fs, 0, "isUsingFrame");

    sleepThreshold = cvReadIntByName(fs, 0, "sleepThreshold");

    moveThreshold = cvReadIntByName(fs, 0, "moveThreshold");

    cvReleaseFileStorage(&fs);
}

int SettingDialog::getMoveThreshold() const
{
    return moveThreshold;
}

void SettingDialog::setMoveThreshold(int value)
{
    moveThreshold = value;
}

int SettingDialog::getSleepThreshold() const
{
    return sleepThreshold;
}

void SettingDialog::setSleepThreshold(int value)
{
    sleepThreshold = value;
}

bool SettingDialog::getIsUsingTime() const
{
    return isUsingTime;
}

void SettingDialog::setIsUsingTime(bool value)
{
    isUsingTime = value;
}

bool SettingDialog::getIsUsingFrame() const
{
    return isUsingFrame;
}

void SettingDialog::setIsUsingFrame(bool value)
{
    isUsingFrame = value;
}

bool SettingDialog::getIsNotAlert() const
{
    return isNotAlert;
}

void SettingDialog::setIsNotAlert(bool value)
{
    isNotAlert = value;
}

int SettingDialog::getTimeSleep() const
{
    return timeSleep;
}

void SettingDialog::setTimeSleep(int value)
{
    timeSleep = value;
}

int SettingDialog::getFrameSleep() const
{
    return frameSleep;
}

void SettingDialog::setFrameSleep(int value)
{
    frameSleep = value;
}

double SettingDialog::getSigma() const
{
    return sigma;
}

void SettingDialog::setSigma(double value)
{
    sigma = value;
}

double SettingDialog::getEdgeThreshold() const
{
    return edgeThreshold;
}

void SettingDialog::setEdgeThreshold(double value)
{
    edgeThreshold = value;
}

double SettingDialog::getContrastThreshold() const
{
    return contrastThreshold;
}

void SettingDialog::setContrastThreshold(double value)
{
    contrastThreshold = value;
}

int SettingDialog::getNOctaveLayers() const
{
    return nOctaveLayers;
}

void SettingDialog::setNOctaveLayers(int value)
{
    nOctaveLayers = value;
}

int SettingDialog::getNfeatures() const
{
    return nfeatures;
}

void SettingDialog::setNfeatures(int value)
{
    nfeatures = value;
}

QString SettingDialog::getFileName() const
{
    return fileName;
}

void SettingDialog::setFileName(const QString &value)
{
    fileName = value;
}

bool SettingDialog::getIsSaveKeypointSanpshot() const
{
    return isSaveKeypointSanpshot;
}

void SettingDialog::setIsSaveKeypointSanpshot(bool value)
{
    isSaveKeypointSanpshot = value;
}

bool SettingDialog::getIsSaveAlertSnapshot() const
{
    return isSaveAlertSnapshot;
}

void SettingDialog::setIsSaveAlertSnapshot(bool value)
{
    isSaveAlertSnapshot = value;
}

bool SettingDialog::getIsSaveSnapshot() const
{
    return isSaveSnapshot;
}

void SettingDialog::setIsSaveSnapshot(bool value)
{
    isSaveSnapshot = value;
}

bool SettingDialog::getIsShowFeatureMatchingResult() const
{
    return isShowFeatureMatchingResult;
}

void SettingDialog::setIsShowFeatureMatchingResult(bool value)
{
    isShowFeatureMatchingResult = value;
}

bool SettingDialog::getIsShowFeatureDetected() const
{
    return isShowFeatureDetected;
}

void SettingDialog::setIsShowFeatureDetected(bool value)
{
    isShowFeatureDetected = value;
}

int::SettingDialog::getTotalPig(){
    return totalPig;
}

int::SettingDialog::getTimeLostMinute(){
    return timeLostMinute;
}

int::SettingDialog::getTimeLostSecond(){
    return timeLostSecond;
}

bool::SettingDialog::getAlertStatus(){
    return isNotAlert;
}

bool::SettingDialog::getOriginalDisplayStatus(){
    return isOriginalDisplay;
}


void SettingDialog::on_addFeatureButton_clicked()
{
    featureCreator = new FeatureCreatorDialog(this);
    featureCreator->show();
    qDebug() <<  "feature setting Clicked";

}

void SettingDialog::on_chooseFeatureModelButton_clicked()
{
    QString filter = "Image Files (*.png *.jpg *.bmp);;";
    fileName = QFileDialog::getOpenFileName(this, "Open File", "./feature image", filter);
}

void SettingDialog::on_usingFrameRadio_clicked()
{
    ui->frameSleepLineEdit->setDisabled(false);
    ui->frameSleepLineEdit->setText(QString::number(frameSleep));

    ui->timeSleepLineEdit_2->setDisabled(true);

}

void SettingDialog::on_usingTimeRadio_clicked()
{
    ui->timeSleepLineEdit_2->setDisabled(false);
    ui->timeSleepLineEdit_2->setText(QString::number(timeSleep));

    ui->frameSleepLineEdit->setDisabled(true);
}

void SettingDialog::on_setAsDefaulButton_clicked()
{
    CvFileStorage* fs = cvOpenFileStorage("config/DefaultSetting.xml", 0, CV_STORAGE_READ);

    totalPig = cvReadIntByName(fs, 0, "totalPig");
    timeLostMinute = cvReadIntByName(fs, 0, "timeLostMinute");
    timeLostSecond = cvReadIntByName(fs, 0, "timeLostSecond");
    isNotAlert = cvReadIntByName(fs, 0, "muteAlertSound");
    isOriginalDisplay = cvReadIntByName(fs, 0, "originalDisplay");

    isShowFeatureDetected = cvReadIntByName(fs, 0, "isShowFeatureDetected");
    isShowFeatureMatchingResult = cvReadIntByName(fs, 0, "isShowFeatureMatchingResult");

    isSaveSnapshot = cvReadIntByName(fs, 0, "isSaveSnapshot");
    isSaveAlertSnapshot = cvReadIntByName(fs, 0, "isSaveAlertSnapshot");
    isSaveKeypointSanpshot = cvReadIntByName(fs, 0, "isSaveKeypointSanpshot");
    fileName = cvReadStringByName(fs, 0, "featureImage");

    nfeatures = cvReadIntByName(fs, 0, "nfeatures");
    nOctaveLayers = cvReadIntByName(fs, 0, "nOctaveLayers");
    contrastThreshold = cvReadRealByName(fs, 0, "contrastThreshold");
    edgeThreshold = cvReadRealByName(fs, 0, "edgeThreshold");
    sigma = cvReadRealByName(fs, 0, "sigma");

    frameSleep = cvReadIntByName(fs, 0, "frameSleep");
    timeSleep = cvReadIntByName(fs, 0, "timeSleep");

    cvReleaseFileStorage(&fs);

    if(isNotAlert){
        ui->muteAlertCheckBox->setChecked(true);
    }else{
        ui->muteAlertCheckBox->setChecked(false);
    }

    if(isOriginalDisplay){
        ui->OriginalDisplayCB->setChecked(true);
    }else{
        ui->OriginalDisplayCB->setChecked(false);
    }
    if(isShowFeatureDetected){
        ui->showFeatureDetectedCB->setChecked(true);
    }else{
        ui->showFeatureDetectedCB->setChecked(false);
    }
    if(isShowFeatureMatchingResult){
        ui->showFeatureMatchingResultCB->setChecked(true);
    }else{
        ui->showFeatureMatchingResultCB->setChecked(false);
    }
    if(isSaveSnapshot){
        ui->saveSnapshotCB->setChecked(true);
    }else{
        ui->saveSnapshotCB->setChecked(false);
    }
    if(isSaveAlertSnapshot){
        ui->saveAlertSnapshotCB->setChecked(true);
    }else{
        ui->saveAlertSnapshotCB->setChecked(false);
    }
    if(isSaveKeypointSanpshot){
        ui->saveKeypointSnapshotCB->setChecked(true);
    }else{
        ui->saveKeypointSnapshotCB->setChecked(false);
    }


    ui->nFeaturesLineEdit->setText(QString::number(nfeatures));
    ui->nOctaveLayersLineEdit->setText(QString::number(nOctaveLayers));
    ui->contrastThresholdLineEdit->setText(QString::number((double)contrastThreshold));
    ui->edgeThresholdLineEdit->setText(QString::number((double)edgeThreshold));
    ui->sigmaLineEdit->setText(QString::number((double)sigma));

    ui->usingTimeRadio->setChecked(true);

    if(ui->usingTimeRadio->isChecked()){
        ui->timeSleepLineEdit_2->setDisabled(false);
        ui->timeSleepLineEdit_2->setText(QString::number(timeSleep));
    }

    ui->sleepThresholdLineEdit->setText(QString::number(7));

    ui->MoveThresholdLineEdit->setText(QString::number(5));
}
