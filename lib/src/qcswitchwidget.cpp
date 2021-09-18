//
// Created by Raffaele Montella on 18/09/21.
//


#include <QStyleOption>
#include "qcswitchwidget.hpp"

QcSwitchWidget::QcSwitchWidget(QWidget *parent) :
        QWidget(parent)
{
    setMinimumSize(250,250);
}

void QcSwitchWidget::paintEvent(QPaintEvent */*paintEvt*/)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    painter.setRenderHint(QPainter::Antialiasing);
}
