//
// Created by Raffaele Montella on 18/09/21.
//


#include <QStyleOption>
#include <utility>
#include "qcswitchwidget.hpp"

QcSwitchWidget::QcSwitchWidget(QWidget *parent) :
        QWidget(parent)
{
    mDrawBezel = true;
    mTextPosition = 0;

    mBazelRadius = 0;
    mState = false;

    mFalseFilename=":/resources/images/h_off.png";
    mTrueFilename=":/resources/images/h_on.png";

    mXBackgroundOffset = 0;
    mYBackgroundOffset = 0;

    mBazelPen = QColorConstants::White;
    mTextPen = QColorConstants::White;
    mTextFont = this->font();
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
        fileName=mTrueFilename;
    } else {
        fileName=mFalseFilename;
    }
    QPixmap pixmap(fileName);

    if (mTextPosition<3) {
        this->setFixedSize(pixmap.size());
    } else {
        this->setFixedSize(pixmap.width()*2,pixmap.height());
    }

    painter.setFont(mTextFont);
    QFontMetrics fontMetrics(painter.font());
    auto boundingRect = fontMetrics.boundingRect(mLabel);
    int xOffset = (this->width()-boundingRect.width())/2;
    int yOffset = boundingRect.height();

    if (mDrawBezel) {
        mXBackgroundOffset = 5;
        mYBackgroundOffset = 5;
        painter.setPen(mBazelPen);
        painter.drawRoundedRect(0, 0, this->width(), this->height(), mBazelRadius, mBazelRadius, Qt::AbsoluteSize);
    }

    switch (mTextPosition) {
        case 1:
            painter.drawPixmap(
                    mXBackgroundOffset, yOffset,
                    this->width() - 2 * mXBackgroundOffset,
                    this->height() - yOffset - mYBackgroundOffset,
                    pixmap);
            painter.setPen(mTextPen);
            painter.drawText(xOffset, yOffset, mLabel);
            break;

        case 2:
            painter.drawPixmap(
                    mXBackgroundOffset, mYBackgroundOffset,
                    this->width() - 2 * mXBackgroundOffset,
                    this->height() - yOffset - 2 * mYBackgroundOffset,
                    pixmap);
            painter.setPen(mTextPen);
            painter.drawText(xOffset, height()-yOffset/2, mLabel);
            break;

        case 3:
            painter.drawPixmap(
                    this->width()/2+mXBackgroundOffset,
                    mYBackgroundOffset,
                    this->width()/2-2*mXBackgroundOffset,
                    this->height()-2*mYBackgroundOffset,
                    pixmap);
            painter.setPen(mTextPen);
            painter.drawText(mXBackgroundOffset,  this->height()/2, mLabel);
            break;

        case 4:
            painter.drawPixmap(
                    mXBackgroundOffset,
                    mYBackgroundOffset,
                    this->width()/2-2*mXBackgroundOffset,
                    this->height()-2*mYBackgroundOffset,
                    pixmap);
            painter.setPen(mTextPen);
            painter.drawText(this->width()/2+mXBackgroundOffset,  this->height()/2, mLabel);
            break;

        default:
            painter.drawPixmap(
                    mXBackgroundOffset, mYBackgroundOffset,
                    this->width() - 2 * mXBackgroundOffset,
                    this->height() - 2 * mYBackgroundOffset,
                    pixmap);
            painter.setPen(mTextPen);
            painter.drawText(xOffset, this->height()/2, mLabel);
            break;
    }

}

bool QcSwitchWidget::getState() const {
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

void QcSwitchWidget::setLabel(QString label) {
    mLabel=std::move(label);
    repaint();
}

QString QcSwitchWidget::getLabel() {
    return mLabel;
}

void QcSwitchWidget::setBazelRadius(int bazelRadius) {
    mBazelRadius = bazelRadius;
    repaint();
}

int QcSwitchWidget::getBazelRadius() const {
    return mBazelRadius;
}

void QcSwitchWidget::setTrueFilename(QString trueFilename) {
    mTrueFilename = std::move(trueFilename);
    repaint();
}

QString QcSwitchWidget::getTrueFilename() {
    return mTrueFilename;
}

void QcSwitchWidget::setFalseFilename(QString falseFilename) {
    mFalseFilename = std::move(falseFilename);
    repaint();
}

QString QcSwitchWidget::getFalseFilename() {
    return mFalseFilename;
}

void QcSwitchWidget::setTextPen(QPen pen) {
    mTextPen = std::move(pen);
    repaint();
}

void QcSwitchWidget::setTextFont(QFont font) {
    mTextFont = std::move(font);
    repaint();
}

void QcSwitchWidget::setBazelPen(QPen pen) {
    mBazelPen = std::move(pen);
    repaint();
}

void QcSwitchWidget::setTextPosition(int textPosition) {
    mTextPosition = textPosition;
    repaint();
}

int QcSwitchWidget::getTextPosition() const {
    return  mTextPosition;
}

QPen QcSwitchWidget::getTextPen() {
    return mTextPen;
}

QFont QcSwitchWidget::getTextFont() {
    return mTextFont;
}

QPen QcSwitchWidget::getBazelPen() {
    return mBazelPen;
}

bool QcSwitchWidget::getDrawBezel() {
    return mDrawBezel;
}

void QcSwitchWidget::setDrawBezel(bool drawBezel) {
    mDrawBezel = drawBezel;
}


