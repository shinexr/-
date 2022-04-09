//
// Created by Raytine on 2022/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_myQtWidget.h" resolved


#include "ui_myQtWidget.h"
#include "myQtWidget.h"
#include "mySquare.h"


myQtWidget::myQtWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::myQtWidget)
{
    ui->setupUi(this);
}

myQtWidget::~myQtWidget()
{
    delete ui;
}

void myQtWidget::setScene(QGraphicsScene *graphicsScene)
{
    ui->graphicsView->setScene(graphicsScene);
}

