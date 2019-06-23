#ifndef CHOOSECAMERA_H
#define CHOOSECAMERA_H

#include <QDialog>

namespace Ui {
class ChooseCamera;
}

class ChooseCamera : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseCamera(QWidget *parent = nullptr);
    ~ChooseCamera();
    QList<int> getCheckedDevice();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ChooseCamera *ui;
    int countCamera();
    int EnumeratorCam;
    QList<int> checkedDeviceList;
};

#endif // CHOOSECAMERA_H
