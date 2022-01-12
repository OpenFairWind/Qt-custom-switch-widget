#include <QApplication>
#include <qcswitchwidget.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchButton w;
    w.setIcons("../../../examples/OnOffButton/power_on.png", "../../../examples/OnOffButton/power_off.png");
    w.setStatus(false);
    w.show();
    return a.exec();
}
