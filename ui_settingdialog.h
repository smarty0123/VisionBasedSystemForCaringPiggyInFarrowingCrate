/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QLabel *label_6;
    QPushButton *addFeatureButton;
    QLineEdit *contrastThresholdLineEdit;
    QLabel *label_4;
    QPushButton *setAsDefaulButton;
    QPushButton *chooseFeatureModelButton;
    QCheckBox *saveAlertSnapshotCB;
    QCheckBox *saveSnapshotCB;
    QCheckBox *saveKeypointSnapshotCB;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *nFeaturesLineEdit;
    QLineEdit *nOctaveLayersLineEdit;
    QLineEdit *edgeThresholdLineEdit;
    QLineEdit *sigmaLineEdit;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *sleepThresholdLineEdit;
    QLabel *label_20;
    QLineEdit *MoveThresholdLineEdit;
    QFrame *frame_2;
    QLabel *label_5;
    QLabel *label_2;
    QSpinBox *lostPigMinSb;
    QLabel *label_3;
    QCheckBox *muteAlertCheckBox;
    QSpinBox *lostPigSecSB;
    QLabel *label;
    QLineEdit *frameSleepLineEdit;
    QRadioButton *usingTimeRadio;
    QRadioButton *usingFrameRadio;
    QLabel *label_16;
    QLineEdit *timeSleepLineEdit_2;
    QFrame *frame_3;
    QLabel *label_8;
    QCheckBox *OriginalDisplayCB;
    QCheckBox *showFeatureDetectedCB;
    QCheckBox *showFeatureMatchingResultCB;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(1086, 671);
        buttonBox = new QDialogButtonBox(SettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(690, 590, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(SettingDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(540, 30, 461, 511));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 19, 121, 21));
        QFont font;
        font.setPointSize(12);
        label_6->setFont(font);
        addFeatureButton = new QPushButton(frame);
        addFeatureButton->setObjectName(QStringLiteral("addFeatureButton"));
        addFeatureButton->setEnabled(true);
        addFeatureButton->setGeometry(QRect(290, 40, 0, 0));
        contrastThresholdLineEdit = new QLineEdit(frame);
        contrastThresholdLineEdit->setObjectName(QStringLiteral("contrastThresholdLineEdit"));
        contrastThresholdLineEdit->setGeometry(QRect(150, 130, 61, 20));
        contrastThresholdLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 70, 61, 21));
        setAsDefaulButton = new QPushButton(frame);
        setAsDefaulButton->setObjectName(QStringLiteral("setAsDefaulButton"));
        setAsDefaulButton->setGeometry(QRect(290, 450, 111, 31));
        QFont font1;
        font1.setPointSize(10);
        setAsDefaulButton->setFont(font1);
        chooseFeatureModelButton = new QPushButton(frame);
        chooseFeatureModelButton->setObjectName(QStringLiteral("chooseFeatureModelButton"));
        chooseFeatureModelButton->setGeometry(QRect(50, 450, 141, 31));
        chooseFeatureModelButton->setFont(font1);
        saveAlertSnapshotCB = new QCheckBox(frame);
        saveAlertSnapshotCB->setObjectName(QStringLiteral("saveAlertSnapshotCB"));
        saveAlertSnapshotCB->setGeometry(QRect(60, 360, 131, 17));
        saveSnapshotCB = new QCheckBox(frame);
        saveSnapshotCB->setObjectName(QStringLiteral("saveSnapshotCB"));
        saveSnapshotCB->setGeometry(QRect(60, 330, 101, 17));
        saveKeypointSnapshotCB = new QCheckBox(frame);
        saveKeypointSnapshotCB->setObjectName(QStringLiteral("saveKeypointSnapshotCB"));
        saveKeypointSnapshotCB->setGeometry(QRect(60, 390, 151, 17));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 100, 81, 16));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 130, 101, 16));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 160, 81, 16));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 190, 47, 13));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 40, 111, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setItalic(false);
        font2.setUnderline(true);
        label_12->setFont(font2);
        nFeaturesLineEdit = new QLineEdit(frame);
        nFeaturesLineEdit->setObjectName(QStringLiteral("nFeaturesLineEdit"));
        nFeaturesLineEdit->setEnabled(true);
        nFeaturesLineEdit->setGeometry(QRect(150, 70, 61, 20));
        nFeaturesLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nFeaturesLineEdit->setReadOnly(false);
        nOctaveLayersLineEdit = new QLineEdit(frame);
        nOctaveLayersLineEdit->setObjectName(QStringLiteral("nOctaveLayersLineEdit"));
        nOctaveLayersLineEdit->setGeometry(QRect(150, 100, 61, 20));
        nOctaveLayersLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edgeThresholdLineEdit = new QLineEdit(frame);
        edgeThresholdLineEdit->setObjectName(QStringLiteral("edgeThresholdLineEdit"));
        edgeThresholdLineEdit->setGeometry(QRect(150, 160, 61, 20));
        edgeThresholdLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sigmaLineEdit = new QLineEdit(frame);
        sigmaLineEdit->setObjectName(QStringLiteral("sigmaLineEdit"));
        sigmaLineEdit->setGeometry(QRect(150, 190, 61, 20));
        sigmaLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 300, 101, 21));
        label_13->setFont(font2);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 420, 101, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setUnderline(true);
        label_14->setFont(font3);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(270, 420, 171, 21));
        label_15->setFont(font3);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(250, 80, 47, 13));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 220, 101, 16));
        label_17->setFont(font3);
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 240, 81, 21));
        sleepThresholdLineEdit = new QLineEdit(frame);
        sleepThresholdLineEdit->setObjectName(QStringLiteral("sleepThresholdLineEdit"));
        sleepThresholdLineEdit->setGeometry(QRect(150, 240, 61, 20));
        sleepThresholdLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 270, 111, 21));
        MoveThresholdLineEdit = new QLineEdit(frame);
        MoveThresholdLineEdit->setObjectName(QStringLiteral("MoveThresholdLineEdit"));
        MoveThresholdLineEdit->setGeometry(QRect(150, 270, 61, 20));
        MoveThresholdLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_2 = new QFrame(SettingDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(30, 30, 471, 301));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 171, 31));
        label_5->setFont(font);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 50, 271, 21));
        label_2->setFont(font1);
        lostPigMinSb = new QSpinBox(frame_2);
        lostPigMinSb->setObjectName(QStringLiteral("lostPigMinSb"));
        lostPigMinSb->setGeometry(QRect(290, 120, 0, 0));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 120, 0, 0));
        label_3->setFont(font1);
        muteAlertCheckBox = new QCheckBox(frame_2);
        muteAlertCheckBox->setObjectName(QStringLiteral("muteAlertCheckBox"));
        muteAlertCheckBox->setGeometry(QRect(40, 150, 141, 41));
        muteAlertCheckBox->setFont(font1);
        muteAlertCheckBox->setChecked(false);
        lostPigSecSB = new QSpinBox(frame_2);
        lostPigSecSB->setObjectName(QStringLiteral("lostPigSecSB"));
        lostPigSecSB->setGeometry(QRect(370, 120, 0, 0));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 70, 47, 41));
        QFont font4;
        font4.setPointSize(8);
        label->setFont(font4);
        frameSleepLineEdit = new QLineEdit(frame_2);
        frameSleepLineEdit->setObjectName(QStringLiteral("frameSleepLineEdit"));
        frameSleepLineEdit->setEnabled(false);
        frameSleepLineEdit->setGeometry(QRect(160, 80, 113, 20));
        frameSleepLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        usingTimeRadio = new QRadioButton(frame_2);
        usingTimeRadio->setObjectName(QStringLiteral("usingTimeRadio"));
        usingTimeRadio->setGeometry(QRect(70, 110, 82, 17));
        usingTimeRadio->setChecked(true);
        usingFrameRadio = new QRadioButton(frame_2);
        usingFrameRadio->setObjectName(QStringLiteral("usingFrameRadio"));
        usingFrameRadio->setGeometry(QRect(70, 80, 82, 17));
        usingFrameRadio->setCheckable(true);
        usingFrameRadio->setChecked(false);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(290, 112, 47, 21));
        timeSleepLineEdit_2 = new QLineEdit(frame_2);
        timeSleepLineEdit_2->setObjectName(QStringLiteral("timeSleepLineEdit_2"));
        timeSleepLineEdit_2->setEnabled(false);
        timeSleepLineEdit_2->setGeometry(QRect(160, 110, 113, 20));
        timeSleepLineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_3 = new QFrame(SettingDialog);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(30, 370, 471, 171));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 121, 31));
        label_8->setFont(font);
        OriginalDisplayCB = new QCheckBox(frame_3);
        OriginalDisplayCB->setObjectName(QStringLiteral("OriginalDisplayCB"));
        OriginalDisplayCB->setGeometry(QRect(40, 40, 0, 0));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        OriginalDisplayCB->setFont(font5);
        OriginalDisplayCB->setChecked(false);
        showFeatureDetectedCB = new QCheckBox(frame_3);
        showFeatureDetectedCB->setObjectName(QStringLiteral("showFeatureDetectedCB"));
        showFeatureDetectedCB->setGeometry(QRect(40, 40, 151, 31));
        showFeatureMatchingResultCB = new QCheckBox(frame_3);
        showFeatureMatchingResultCB->setObjectName(QStringLiteral("showFeatureMatchingResultCB"));
        showFeatureMatchingResultCB->setGeometry(QRect(40, 60, 181, 51));

        retranslateUi(SettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Setting", nullptr));
        label_6->setText(QApplication::translate("SettingDialog", "Advance Setting", nullptr));
        addFeatureButton->setText(QApplication::translate("SettingDialog", "\340\271\200\340\270\236\340\270\264\340\271\210\340\270\241feature", nullptr));
        label_4->setText(QApplication::translate("SettingDialog", "nFeatures", nullptr));
        setAsDefaulButton->setText(QApplication::translate("SettingDialog", "Default Setting", nullptr));
        chooseFeatureModelButton->setText(QApplication::translate("SettingDialog", "Choose Feature Model", nullptr));
        saveAlertSnapshotCB->setText(QApplication::translate("SettingDialog", "Save Alert Snapshot", nullptr));
        saveSnapshotCB->setText(QApplication::translate("SettingDialog", "Save Snapshot", nullptr));
        saveKeypointSnapshotCB->setText(QApplication::translate("SettingDialog", "Save Keypoint Snapshot", nullptr));
        label_7->setText(QApplication::translate("SettingDialog", "nOctaveLayers", nullptr));
        label_9->setText(QApplication::translate("SettingDialog", "ContrastThreshold", nullptr));
        label_10->setText(QApplication::translate("SettingDialog", "edgeThreshold", nullptr));
        label_11->setText(QApplication::translate("SettingDialog", "Sigma", nullptr));
        label_12->setText(QApplication::translate("SettingDialog", "SIFT Parameter", nullptr));
        nFeaturesLineEdit->setText(QString());
        label_13->setText(QApplication::translate("SettingDialog", "Save to Storage", nullptr));
        label_14->setText(QApplication::translate("SettingDialog", "Feature Model", nullptr));
        label_15->setText(QApplication::translate("SettingDialog", "Reset to Default Setting", nullptr));
        label_18->setText(QString());
        label_17->setText(QApplication::translate("SettingDialog", "Threshold", nullptr));
        label_19->setText(QApplication::translate("SettingDialog", "Sleep Threshold", nullptr));
        label_20->setText(QApplication::translate("SettingDialog", "Piggy Move Threshold", nullptr));
        label_5->setText(QApplication::translate("SettingDialog", "Alert Setting", nullptr));
        label_2->setText(QApplication::translate("SettingDialog", "Alert after sleeping more than", nullptr));
        label_3->setText(QApplication::translate("SettingDialog", "\340\270\231\340\270\262\340\270\227\340\270\265 ", nullptr));
        muteAlertCheckBox->setText(QApplication::translate("SettingDialog", "Disable Sound", nullptr));
        label->setText(QApplication::translate("SettingDialog", "Frames", nullptr));
        usingTimeRadio->setText(QApplication::translate("SettingDialog", "Using Time", nullptr));
        usingFrameRadio->setText(QApplication::translate("SettingDialog", "Using Frame", nullptr));
        label_16->setText(QApplication::translate("SettingDialog", "Minutes", nullptr));
        label_8->setText(QApplication::translate("SettingDialog", "Display Setting", nullptr));
        OriginalDisplayCB->setText(QApplication::translate("SettingDialog", "\340\271\201\340\270\252\340\270\224\340\270\207\340\270\240\340\270\262\340\270\236\340\270\224\340\270\261\340\271\211\340\270\207\340\271\200\340\270\224\340\270\264\340\270\241", nullptr));
        showFeatureDetectedCB->setText(QApplication::translate("SettingDialog", "Show Feature Detected", nullptr));
        showFeatureMatchingResultCB->setText(QApplication::translate("SettingDialog", "Show Feature Matching Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
