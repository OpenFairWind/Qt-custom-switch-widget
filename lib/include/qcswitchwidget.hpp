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

    void setDrawBezel(bool drawBezel);
    bool getDrawBezel();

    void setTextPosition(int textPosition);
    int getTextPosition() const;

    void setTextPen(QPen pen);
    QPen getTextPen();

    void setTextFont(QFont font);
    QFont getTextFont();

    void setBazelPen(QPen pen);
    QPen getBazelPen();

    void setTrueFilename(QString trueFilename);
    QString getTrueFilename();

    void setFalseFilename(QString falseFilename);
    QString getFalseFilename();

    void setBazelRadius(int bazelRadius);
    int getBazelRadius() const;

    void setLabel(QString label);
    QString getLabel();

    void setState(bool state);
    bool getState() const;

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
    bool mDrawBezel;

    int mTextPosition;

    bool mState;
    QString mLabel;
    int mBazelRadius;
    QString mTrueFilename;
    QString mFalseFilename;

    QPen mTextPen;
    QPen mBazelPen;
    QFont mTextFont;
    int mXBackgroundOffset;
    int mYBackgroundOffset;

    void drawBezel(bool drawBezel);
};


#endif //QCSWITCHWIDGET_HPP
