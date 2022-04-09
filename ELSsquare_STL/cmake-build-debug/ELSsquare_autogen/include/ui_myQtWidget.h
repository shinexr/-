/********************************************************************************
** Form generated from reading UI file 'myQtWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTWIDGET_H
#define UI_MYQTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myQtWidget
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *myQtWidget)
    {
        if (myQtWidget->objectName().isEmpty())
            myQtWidget->setObjectName(QString::fromUtf8("myQtWidget"));
        myQtWidget->resize(410, 442);
        graphicsView = new QGraphicsView(myQtWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 256, 192));

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
