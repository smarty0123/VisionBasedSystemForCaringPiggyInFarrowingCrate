/********************************************************************************
** Form generated from reading UI file 'featurecreatordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATURECREATORDIALOG_H
#define UI_FEATURECREATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_FeatureCreatorDialog
{
public:
    QDialogButtonBox *buttonBox;
    my_qlabel *picLabel;
    QPushButton *saveButton;

    void setupUi(QDialog *FeatureCreatorDialog)
    {
        if (FeatureCreatorDialog->objectName().isEmpty())
            FeatureCreatorDialog->setObjectName(QStringLiteral("FeatureCreatorDialog"));
        FeatureCreatorDialog->resize(670, 460);
        buttonBox = new QDialogButtonBox(FeatureCreatorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(570, 360, 81, 111));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        picLabel = new my_qlabel(FeatureCreatorDialog);
        picLabel->setObjectName(QStringLiteral("picLabel"));
        picLabel->setEnabled(true);
        picLabel->setGeometry(QRect(80, 30, 430, 360));
        picLabel->setMouseTracking(true);
        picLabel->setFrameShape(QFrame::Box);
        saveButton = new QPushButton(FeatureCreatorDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(560, 70, 91, 51));

        retranslateUi(FeatureCreatorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FeatureCreatorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FeatureCreatorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FeatureCreatorDialog);
    } // setupUi

    void retranslateUi(QDialog *FeatureCreatorDialog)
    {
        FeatureCreatorDialog->setWindowTitle(QApplication::translate("FeatureCreatorDialog", "Create Feature", nullptr));
        picLabel->setText(QString());
        saveButton->setText(QApplication::translate("FeatureCreatorDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeatureCreatorDialog: public Ui_FeatureCreatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATURECREATORDIALOG_H
