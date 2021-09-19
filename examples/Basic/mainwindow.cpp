//
// Created by Raffaele Montella on 18/09/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <qcswitchwidget.hpp>
#include "mainwindow.hpp"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Create the gauge widget
    auto switchWidget = new QcSwitchWidget;
    switchWidget->setState(false);

    ui->horizontalLayout->addWidget(switchWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

