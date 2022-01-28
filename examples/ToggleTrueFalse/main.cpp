#include <QApplication>
#include <QHBoxLayout>
#include "qcswitchwidget.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget;
    QHBoxLayout layout;
    widget->setLayout(&layout);
    widget->setMinimumSize(100,50);
    ToggleButton* sbtn = new ToggleButton(widget, ToggleButton::Style::TRUEFALSE);
    layout.addWidget(sbtn);
    widget->show();
    return a.exec();

}

