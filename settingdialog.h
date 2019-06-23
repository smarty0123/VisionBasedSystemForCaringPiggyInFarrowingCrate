#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <iostream>
#include <opencv2/opencv.hpp>

#include <featurecreatordialog.h>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    SettingDialog(bool isFromFeatureMatching);
    explicit SettingDialog(QWidget *parent = nullptr, bool isPlaying = false);
    ~SettingDialog();
    int getTotalPig();
    int getTimeLostMinute();
    int getTimeLostSecond();


    bool getAlertStatus();
    bool getOriginalDisplayStatus();
    bool getProcessResult();


    bool getIsShowFeatureDetected() const;
    void setIsShowFeatureDetected(bool value);

    bool getIsShowFeatureMatchingResult() const;
    void setIsShowFeatureMatchingResult(bool value);

    bool getIsSaveSnapshot() const;
    void setIsSaveSnapshot(bool value);

    bool getIsSaveAlertSnapshot() const;
    void setIsSaveAlertSnapshot(bool value);

    bool getIsSaveKeypointSanpshot() const;
    void setIsSaveKeypointSanpshot(bool value);

    QString getFileName() const;
    void setFileName(const QString &value);

    int getNfeatures() const;
    void setNfeatures(int value);

    int getNOctaveLayers() const;
    void setNOctaveLayers(int value);

    double getContrastThreshold() const;
    void setContrastThreshold(double value);

    double getEdgeThreshold() const;
    void setEdgeThreshold(double value);

    double getSigma() const;
    void setSigma(double value);


    int getFrameSleep() const;
    void setFrameSleep(int value);

    int getTimeSleep() const;
    void setTimeSleep(int value);

    bool getIsNotAlert() const;
    void setIsNotAlert(bool value);

    bool getIsUsingFrame() const;
    void setIsUsingFrame(bool value);

    bool getIsUsingTime() const;
    void setIsUsingTime(bool value);

    int getSleepThreshold() const;
    void setSleepThreshold(int value);

    int getMoveThreshold() const;
    void setMoveThreshold(int value);

private slots:
    void on_buttonBox_accepted();

    void on_addFeatureButton_clicked();

    void on_chooseFeatureModelButton_clicked();

    void on_usingFrameRadio_clicked();

    void on_usingTimeRadio_clicked();

    void on_setAsDefaulButton_clicked();

private:
    Ui::SettingDialog *ui;

    void saveConfig();
    void loadConfig();

    int totalPig;
    int timeLostMinute;
    int timeLostSecond;
    bool isNotAlert;
    bool isOriginalDisplay;

    bool isShowFeatureDetected;
    bool isShowFeatureMatchingResult;

    bool isSaveSnapshot;
    bool isSaveAlertSnapshot;
    bool isSaveKeypointSanpshot;

    FeatureCreatorDialog *featureCreator;

    QString fileName;

    int nfeatures;
    int nOctaveLayers;
    double contrastThreshold;
    double edgeThreshold;
    double sigma;

    int frameSleep;
    int timeSleep;

    bool isUsingFrame;
    bool isUsingTime;

    int sleepThreshold;

    int moveThreshold;
};

#endif // SETTINGDIALOG_H
