/********************************************************************************
** Form generated from reading UI file 'myQtWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTWIDGET_H
#define UI_MYQTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>
#include "mySquare.h"
using namespace shinexr01;
QT_BEGIN_NAMESPACE

class Ui_myQtWidget
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *myQtWidget)
    {
        if (myQtWidget->objectName().isEmpty())
            myQtWidget->setObjectName(QString::fromUtf8("myQtWidget"));
        myQtWidget->resize(300, 450);
        myQtWidget->setMinimumSize(QSize(300, 450));
        myQtWidget->setMaximumSize(QSize(300, 450));
        graphicsView = new QGraphicsView(myQtWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, PlaceWedth, PlaceHeigh));
        graphicsView->setMinimumSize(QSize(PlaceWedth, PlaceHeigh));
        graphicsView->setMaximumSize(QSize(PlaceWedth, PlaceHeigh));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSceneRect(QRectF(0, 0, PlaceWedth, PlaceHeigh));

        retranslateUi(myQtWidget);

        QMetaObject::connectSlotsByName(myQtWidget);
    } // setupUi

    void retranslateUi(QWidget *myQtWidget)
    {
        myQtWidget->setWindowTitle(QCoreApplication::translate("myQtWidget", "myQtWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myQtWidget: public Ui_myQtWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTWIDGET_H
