/********************************************************************************
** Form generated from reading UI file 'selectcaptureregiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCAPTUREREGIONDIALOG_H
#define UI_SELECTCAPTUREREGIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_SelectCaptureRegionDialog
{
public:
    QPushButton *ClearMaskButton;
    QPushButton *ConfirmButton;
    my_qlabel *firstFrameLabel;

    void setupUi(QDialog *SelectCaptureRegionDialog)
    {
        if (SelectCaptureRegionDialog->objectName().isEmpty())
            SelectCaptureRegionDialog->setObjectName(QStringLiteral("SelectCaptureRegionDialog"));
        SelectCaptureRegionDialog->resize(1000, 600);
        ClearMaskButton = new QPushButton(SelectCaptureRegionDialog);
        ClearMaskButton->setObjectName(QStringLiteral("ClearMaskButton"));
        ClearMaskButton->setGeometry(QRect(520, 10, 101, 41));
        QFont font;
        font.setPointSize(10);
        ClearMaskButton->setFont(font);
        ConfirmButton = new QPushButton(SelectCaptureRegionDialog);
        ConfirmButton->setObjectName(QStringLiteral("ConfirmButton"));
        ConfirmButton->setGeometry(QRect(650, 10, 101, 41));
        ConfirmButton->setFont(font);
        firstFrameLabel = new my_qlabel(SelectCaptureRegionDialog);
        firstFrameLabel->setObjectName(QStringLiteral("firstFrameLabel"));
        firstFrameLabel->setGeometry(QRect(20, 90, 731, 461));
        firstFrameLabel->setMouseTracking(true);
        firstFrameLabel->setFrameShape(QFrame::Box);

        retranslateUi(SelectCaptureRegionDialog);

        QMetaObject::connectSlotsByName(SelectCaptureRegionDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectCaptureRegionDialog)
    {
        SelectCaptureRegionDialog->setWindowTitle(QApplication::translate("SelectCaptureRegionDialog", "Select Capture Region", nullptr));
        ClearMaskButton->setText(QApplication::translate("SelectCaptureRegionDialog", "Clear Mask", nullptr));
        ConfirmButton->setText(QApplication::translate("SelectCaptureRegionDialog", "Confirm", nullptr));
        firstFrameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectCaptureRegionDialog: public Ui_SelectCaptureRegionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCAPTUREREGIONDIALOG_H
