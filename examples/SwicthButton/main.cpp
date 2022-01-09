#include <QApplication>
#include "qcswitchwidget.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchButton w;
    w.setStylesheet("../../../examples/SwicthButton/toggle_on.png", "../../../examples/SwicthButton/toggle_off.png");
    w.show();
    return a.exec();
}
