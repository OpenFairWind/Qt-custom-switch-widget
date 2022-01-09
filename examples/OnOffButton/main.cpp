#include <QApplication>
#include <qcswitchwidget.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchButton w;
    w.setStylesheet("../../../examples/OnOffButton/power_on.png", "../../../examples/OnOffButton/power_off.png");
    w.show();
    return a.exec();
}
