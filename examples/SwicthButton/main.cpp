#include <QApplication>
#include "qcswitchwidget.hpp"
#include "iostream"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchButton w;
    w.setIcons("../../../examples/SwicthButton/toggle_on.png", "../../../examples/SwicthButton/toggle_off.png");
    w.setStatus(false);
    w.show();
    return a.exec();
}
