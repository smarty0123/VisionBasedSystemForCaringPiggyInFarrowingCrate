/********************************************************************************
** Form generated from reading UI file 'choosecamera.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECAMERA_H
#define UI_CHOOSECAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseCamera
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ChooseCamera)
    {
        if (ChooseCamera->objectName().isEmpty())
            ChooseCamera->setObjectName(QStringLiteral("ChooseCamera"));
        ChooseCamera->resize(356, 372);
        buttonBox = new QDialogButtonBox(ChooseCamera);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(ChooseCamera);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 40, 218, 261));

        retranslateUi(ChooseCamera);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChooseCamera, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChooseCamera, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChooseCamera);
    } // setupUi

    void retranslateUi(QDialog *ChooseCamera)
    {
        ChooseCamera->setWindowTitle(QApplication::translate("ChooseCamera", "Choose Camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseCamera: public Ui_ChooseCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECAMERA_H
