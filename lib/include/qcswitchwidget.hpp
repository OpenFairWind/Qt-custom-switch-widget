//
// Created by Raffaele Montella on 18/09/21.
//

#ifndef QCSWITCHWIDGET_HPP
#define QCSWITCHWIDGET_HPP

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QRectF>
#include <QtMath>



#if defined(QCSWITCH_COMPILE_LIBRARY)
#  define QCSWITCH_DECL  Q_DECL_EXPORT
#elif defined(QCSWITCH_USE_LIBRARY)
#  define QCSWITCH_DECL Q_DECL_IMPORT
#else
#  define QCSWITCH_DECL
#endif

class QcSwitchWidget;

class QCSWITCH_DECL QcSwitchWidget : public QWidget
{
Q_OBJECT
public:
    explicit QcSwitchWidget(QWidget *parent = 0);

    void setState(bool state);
    bool getState();

signals:
    void clicked();
    void released();
    void pressed();

public slots:

private:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);

private:
    bool mState;
};


#endif //QCSWITCHWIDGET_HPP
