 #-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T13:40:41
#
#-------------------------------------------------

QT       += core gui \
multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiggyCaringSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
        piggycarringsystem.cpp \
        settingdialog.cpp \
        choosecamera.cpp \
    my_qlabel.cpp \
    featurecreatordialog.cpp \
    featurematching.cpp \
    selectcaptureregiondialog.cpp


HEADERS += \
        mainwindow.h \
        settingdialog.h \
        choosecamera.h \
    my_qlabel.h \
    featurecreatordialog.h \
    featurematching.h \
    selectcaptureregiondialog.h

FORMS += \
        mainwindow.ui \
        settingdialog.ui \
        choosecamera.ui \
    featurecreatordialog.ui \
    selectcaptureregiondialog.ui

INCLUDEPATH += C:\opencv\opencv3.4.3\build\install\include

LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_core343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_highgui343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_imgcodecs343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_imgproc343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_features2d343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_calib3d343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_xfeatures2d343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_flann343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_videoio343.dll
LIBS += C:\opencv\opencv3.4.3\build\install\x86\mingw\bin\libopencv_video343.dll

RESOURCES += \
    res.qrc \
    res.qrc
