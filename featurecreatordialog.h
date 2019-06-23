#ifndef FEATURECREATORDIALOG_H
#define FEATURECREATORDIALOG_H

#include <QDialog>
#include <QtCore>
#include "my_qlabel.h"
#include "QDebug"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <vector>

namespace Ui {
class FeatureCreatorDialog;
}

class FeatureCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FeatureCreatorDialog(QWidget *parent = nullptr);
    ~FeatureCreatorDialog();

private slots:
    void Mouse_current_pos();
    void Mouse_pressed();
    void processFrameAndUpdateGUI();
    void on_saveButton_clicked();

private:
    Ui::FeatureCreatorDialog *ui;

    QImage convertOpenCVMatToQtQImage(cv::Mat mat);

    QTimer* qTimer;

    cv::VideoCapture capture;

    bool isPause = false;

    cv::Mat cvFrame;

    cv::Mat tempFrame;

    cv::Mat drawFrame;

    bool isClicking = false;

    std::vector<cv::Point> points;

};

#endif // FEATURECREATORDIALOG_H
