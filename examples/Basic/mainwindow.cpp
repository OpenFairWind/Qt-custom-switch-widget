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


    // Create the switch widget

    auto cabinLights1SwitchWidget = new QcSwitchWidget;
    cabinLights1SwitchWidget->setDrawBezel(false);
    cabinLights1SwitchWidget->setTextPosition(0);
    cabinLights1SwitchWidget->setState(false);
    cabinLights1SwitchWidget->setLabel("Cabin Lights 1");
    ui->horizontalLayout->addWidget(cabinLights1SwitchWidget);

    auto cabinLights2SwitchWidget = new QcSwitchWidget;
    cabinLights2SwitchWidget->setDrawBezel(false);
    cabinLights2SwitchWidget->setTextPosition(1);
    cabinLights2SwitchWidget->setState(false);
    cabinLights2SwitchWidget->setLabel("Cabin Lights 2");
    ui->horizontalLayout->addWidget(cabinLights2SwitchWidget);

    auto cabinLights3SwitchWidget = new QcSwitchWidget;
    cabinLights3SwitchWidget->setDrawBezel(false);
    cabinLights3SwitchWidget->setTextPosition(2);
    cabinLights3SwitchWidget->setState(false);
    cabinLights3SwitchWidget->setLabel("Cabin Lights 3");
    ui->horizontalLayout->addWidget(cabinLights3SwitchWidget);

    auto keelBilgePumpSwitchWidget = new QcSwitchWidget;
    keelBilgePumpSwitchWidget->setTextPosition(3);
    keelBilgePumpSwitchWidget->setState(false);
    keelBilgePumpSwitchWidget->setBazelRadius(10);
    keelBilgePumpSwitchWidget->setLabel("Keel Bilge Pump");
    ui->horizontalLayout->addWidget(keelBilgePumpSwitchWidget);

    auto anchorWindlassSwitchWidget = new QcSwitchWidget;
    anchorWindlassSwitchWidget->setTextPosition(4);
    anchorWindlassSwitchWidget->setState(false);
    anchorWindlassSwitchWidget->setBazelRadius(10);
    anchorWindlassSwitchWidget->setLabel("Anchor Windlass");
    ui->horizontalLayout->addWidget(anchorWindlassSwitchWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

