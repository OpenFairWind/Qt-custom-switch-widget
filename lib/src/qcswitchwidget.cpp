//
// Created by Raffaele Montella on 18/09/21.
//


#include <QStyleOption>
#include "qcswitchwidget.hpp"

QcSwitchWidget::QcSwitchWidget(QWidget *parent) :
        QWidget(parent)
{
    setMinimumSize(250,250);

    mState = false;



    //connect(this, SIGNAL(clicked()), this, SLOT(quit()));
}

void QcSwitchWidget::paintEvent(QPaintEvent */*paintEvt*/)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    painter.setRenderHint(QPainter::Antialiasing);

    QString fileName="";

    if (mState) {
        fileName=":/resources/images/h_on.png";
    } else {
        fileName=":/resources/images/h_off.png";
    }

    QPixmap pixmap(fileName);

    painter.drawPixmap(0,0,284,88, pixmap);
}

bool QcSwitchWidget::getState() {
    return mState;
}

void QcSwitchWidget::setState(bool state) {
    mState=state;
    repaint();
    emit clicked();
}

void QcSwitchWidget::mousePressEvent(QMouseEvent *) {
    emit pressed();
}

void QcSwitchWidget::mouseReleaseEvent(QMouseEvent *) {
    mState = !mState;
    repaint();
    emit released();
    emit clicked();
}
