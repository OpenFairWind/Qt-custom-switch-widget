//
// Created by Raffaele Montella on 18/09/21.
//


#include <QStyleOption>
#include <utility>
#include "qcswitchwidget.hpp"
#include <QVBoxLayout>

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

ToggleBackground::ToggleBackground(QWidget* parent, QColor color, bool rect)
        : QWidget(parent)
        , _rect(rect)
        , _borderradius(12)
        , _pencolor(color)
{
    if (_rect)
        _borderradius = 0;

}
ToggleBackground::~ToggleBackground()
{
}
void ToggleBackground::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->setBrush(_pencolor);
    painter->drawRoundedRect(0, 0
             , width(), height()
             , 10, 10);
    painter->end();
}

ToggleCircle::ToggleCircle(QWidget* parent, QColor color, bool rect)
        : QWidget(parent)
        , _rect(rect)
        , _borderradius(12)
        , _color(color)
        , _pencolor(QColor(120, 120, 120))
{
    _radGradient = QRadialGradient(static_cast<int>(width() / 2), static_cast<int>(height() / 2), 12);
    _radGradient.setColorAt(0, QColor(255, 255, 255));
    _radGradient.setColorAt(0.6, QColor(255, 255, 255));
    _radGradient.setColorAt(1, QColor(205, 205, 205));

    _gradient = QLinearGradient(3, 18, 20, 4);
    _gradient.setColorAt(0, QColor(255, 255, 255));
    _gradient.setColorAt(0.55, QColor(230, 230, 230));
    _gradient.setColorAt(0.72, QColor(255, 255, 255));
    _gradient.setColorAt(1, QColor(255, 255, 255));

}
ToggleCircle::~ToggleCircle()
{
}
void ToggleCircle::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->setBrush(_pencolor);

    painter->drawEllipse(0, 0, 20, 20);
    painter->setBrush(_radGradient);
    painter->drawEllipse(1, 1, 18, 18);

    painter->setBrush(QColor(210, 210, 210));
    painter->drawEllipse(2, 2, 16, 16);

    painter->setBrush(_gradient);
    painter->drawEllipse(3, 3, 14, 14);


    painter->end();
}

ToggleButton::ToggleButton(QWidget* parent, Style style, bool startValue, QColor background)
        : QWidget(parent)
        , _value(startValue)
        , _duration(100)
        , _oncolor(background)
{
    _pencolor = QColor(Qt::lightGray);

    _gradient1 = QLinearGradient(35, 30, 35, 0);
    _gradient1.setColorAt(0, QColor(210, 210, 210));
    _gradient1.setColorAt(0.25, QColor(255, 255, 255));
    _gradient1.setColorAt(0.82, QColor(255, 255, 255));
    _gradient1.setColorAt(1, QColor(210, 210, 210));

    _offcolor = Qt::black;
    _tol = 0;
    _borderradius = 12;
    _labeloff = new QLabel(this);
    _background = new ToggleBackground(this, _oncolor);
    _labelon = new QLabel(this);
    _circle = new ToggleCircle(this, _offcolor);
    __btn_move = new QPropertyAnimation(this);
    __back_move = new QPropertyAnimation(this);

    __btn_move->setTargetObject(_circle);
    __btn_move->setPropertyName("pos");
    __back_move->setTargetObject(_background);
    __back_move->setPropertyName("size");

    setWindowFlags(Qt::FramelessWindowHint);
   // setAttribute(Qt::WA_TranslucentBackground);

    _labeloff->setText("Off");
    _labelon->setText("On");
    _labeloff->move(30, 3);
    _labelon->move(6, 3);
    setFixedHeight(24);
    setMinimumWidth(70);
    if (style == Style::YESNO)
    {
        _labeloff->setText("No");
        _labelon->setText("Yes");
        _labeloff->move(33, 3);
        _labelon->move(8, 3);
    }
    else if (style == Style::TRUEFALSE)
    {
        _labeloff->setText("False");
        _labelon->setText("True");
        _labeloff->move(38, 3);
        _labelon->move(7, 3);
    }
    if (style == Style::EMPTY)
    {
        _labeloff->setText("");
        _labelon->setText("");
    }

    _labeloff->setStyleSheet("color: rgb(120, 120, 120); background-color: rgb(255, 255, 255); font-weight: bold;");
    _labelon->setStyleSheet("color: rgb(255, 255, 255); font-weight: bold;");

    _background->resize(20, 20);

    _background->move(2, 2);
    _circle->move(2, 2);
}

ToggleButton::~ToggleButton()
{
    delete _circle;
    delete _background;
    delete _labeloff;
    delete _labelon;
    delete __btn_move;
    delete __back_move;
}
void ToggleButton::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);

    painter->setBrush(_pencolor);
    painter->drawRoundedRect(0, 0, width(), height(), 12, 12);

    painter->setBrush(_gradient1);
    painter->drawRoundedRect(1, 1, width() - 2, height() - 2, 10, 10);

    painter->end();
}
void ToggleButton::mousePressEvent(QMouseEvent*)
{
    __btn_move->stop();
    __back_move->stop();
    __btn_move->setDuration(_duration);
    __back_move->setDuration(_duration);

    int hback = 20;
    QSize initial_size(hback, hback);
    QSize final_size(width() - 4, hback);

    int xi = 2;
    int y  = 2;
    int xf = width() - 22;

    if (_value)
    {
        final_size = QSize(hback, hback);
        initial_size = QSize(width() - 4, hback);

        xi = xf;
        xf = 2;
    }

    __btn_move->setStartValue(QPoint(xi, y));
    __btn_move->setEndValue(QPoint(xf, y));

    __back_move->setStartValue(initial_size);
    __back_move->setEndValue(final_size);

    __btn_move->start();
    __back_move->start();

    // Assigning new current value
    _value = !_value;
   // emit valueChanged(_value);
}

void ToggleButton::setValue(bool flag)
{
    if (flag == value())
        return;
    else
    {
        _value = flag;
        _update();
    }
}
bool ToggleButton::value() const
{
    return _value;
}
void ToggleButton::_update()
{
    int hback = 20;
    QSize final_size(width() - 4, hback);

    int y = 2;
    int xf = width() - 22;

    if (_value)
    {
        final_size = QSize(hback, hback);
        xf = 2;
    }
    _circle->move(QPoint(xf, y));
    _background->resize(final_size);
}

SwitchButton::SwitchButton(QWidget* parent): QWidget(parent)
{
    QVBoxLayout* vLay = new QVBoxLayout(this);
    pushButton = new QPushButton(this);
    pushButton->setObjectName("pushButton");
    pushButton->setCheckable(true);
    pushButton->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    vLay->addWidget(pushButton);
    this->setLayout(vLay);
}

SwitchButton::~SwitchButton()
{}
//max-width: 180px;
void SwitchButton::setStylesheet(QString iconCheckPath, QString iconUncheckPath)
{
    QFile fileIconCheck(iconCheckPath);
    QFile fileIconUnCheck(iconUncheckPath);
    if(!fileIconCheck.exists() || !fileIconUnCheck.exists())
        qDebug("File doesn't exists. Please check input file path!.");
    else {
        QString styleSheet = "QPushButton#" + pushButton->objectName() +
                             "{ border:0px;";
        styleSheet.append("border-image: url(");
        styleSheet.append(iconCheckPath);
        styleSheet.append(") 0 0 0 0 stretch stretch;margin-left:1px;margin-right:1px;padding: 0px;background-color:none;}");

        styleSheet.append("QPushButton#" + pushButton->objectName() + ":checked{border-image: url(");
        styleSheet.append(iconUncheckPath);
        styleSheet.append(") 0 0 0 0 stretch stretch;}");

        this->setStyleSheet(styleSheet);
    }
}

QLabel* SwitchButton::addLabel(float position)
{
    auto item = new QLabel(this);
    return item;
}

static void setStylesheet(QWidget* widget,QString styleSheet)
{
    widget->setStyleSheet(styleSheet);
}


