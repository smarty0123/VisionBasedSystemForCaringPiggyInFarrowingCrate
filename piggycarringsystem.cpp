#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Piggy Caring System");
    mainWindow.show();

    return qApplication.exec();
}
