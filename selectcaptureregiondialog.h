#ifndef SELECTCAPTUREREGIONDIALOG_H
#define SELECTCAPTUREREGIONDIALOG_H

#include <QDialog>

#include "my_qlabel.h"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"

namespace Ui {
class SelectCaptureRegionDialog;
}

class SelectCaptureRegionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectCaptureRegionDialog(QWidget *parent = nullptr);
    ~SelectCaptureRegionDialog();

    void setFirstFrame(cv::Mat firstFrame);

    void setCaptureRegionPoints(std::vector<cv::Point>);
    std::vector<cv::Point> getCaptureRegionPoints();

private slots:
    void on_ClearMaskButton_clicked();

    void Mouse_current_pos();
    void Mouse_pressed();

    void on_ConfirmButton_clicked();

private:
    Ui::SelectCaptureRegionDialog *ui;

    QImage convertOpenCVMatToQtQImage(cv::Mat mat);

    cv::Mat firstFrame;

    cv::Mat tempFrame;

    std::vector<cv::Point> points;

    std::vector<cv::Point> tempPoints;
};

#endif // SELECTCAPTUREREGIONDIALOG_H
