#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QMouseEvent>
#include <QDebug>
#include <QLabel>

class my_qlabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_qlabel(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

    int x, y;

signals:
    void MousePressed();
    void Mouse_pos();

public slots:
};

#endif // MY_QLABEL_H
