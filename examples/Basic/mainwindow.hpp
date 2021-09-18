//
// Created by Raffaele Montella on 18/09/21.
//

#ifndef QCGAUGEWIDGET_MAINWINDOW_HPP
#define QCGAUGEWIDGET_MAINWINDOW_HPP

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //QCGAUGEWIDGET_MAINWINDOW_HPP
