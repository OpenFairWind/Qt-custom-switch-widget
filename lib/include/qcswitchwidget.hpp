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
#include <QPropertyAnimation>
#include <QAbstractButton>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPushButton>
#include <QLabel>



#if defined(QCSWITCH_COMPILE_LIBRARY)
#  define QCSWITCH_DECL  Q_DECL_EXPORT
#elif defined(QCSWITCH_USE_LIBRARY)
#  define QCSWITCH_DECL Q_DECL_IMPORT
#else
#  define QCSWITCH_DECL
#endif

class QcSwitchWidget;
class SwitchBackground;
class SwitchCircle;
class SwitchButton;
class ToggleButton;

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

class QCSWITCH_DECL SwitchBackground : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchBackground(QWidget* parent = nullptr, QColor color = QColor(154, 205, 50), bool rect = false);
    ~SwitchBackground() override;
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);

private:
    bool            _rect;
    int             _borderradius;
    QColor          _color;
    QColor          _pencolor;
    QLinearGradient _gradient;
    QLinearGradient _gdisabled;

    bool _enabled;
};

class QCSWITCH_DECL SwitchCircle : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchCircle(QWidget* parent = nullptr, QColor color = QColor(255, 255, 255), bool rect = false);
    ~SwitchCircle() override;
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);

private:
    bool            _rect;
    int             _borderradius;
    QColor          _color;
    QColor          _pencolor;
    QRadialGradient _radGradient;
    QLinearGradient _gradient;
    QLinearGradient _gdisabled;

    bool _enabled;
};

class QCSWITCH_DECL SwitchButton : public QWidget
{
    Q_OBJECT
public:
    enum Style
    {
        YESNO,
        ONOFF,
        TRUEFALSE,
        EMPTY
    };

public:
    SwitchButton(QWidget *parent = nullptr, Style style = Style::ONOFF, bool startValue = false);
    ~SwitchButton();

    void mousePressEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);
    void setValue(bool);
    bool value() const;

private:
    bool _value;
    int  _duration;

    QLinearGradient _gradient1;
    QLinearGradient _gradient2;
    QLinearGradient _gdisabled;

    QColor _pencolor;
    QColor _offcolor;
    QColor _oncolor;
    int    _tol;
    int    _borderradius;

    QLabel*           _labeloff;
    SwitchBackground* _background;
    QLabel*           _labelon;
    SwitchCircle*     _circle;

    bool _enabled=true;

    QPropertyAnimation* __btn_move;
    QPropertyAnimation* __back_move;
    void _update();
};

static QCSWITCH_DECL void setStylesheet(QWidget*, QString );

class QCSWITCH_DECL ToggleButton :public QWidget
{
    Q_OBJECT
public:
    explicit ToggleButton(QWidget* parent = nullptr);
    ~ToggleButton();
    void setStylesheet(QString, QString);
    QLabel* addLabel(float);

private:
    QPushButton* pushButton;
};

#endif //QCSWITCHWIDGET_HPP
