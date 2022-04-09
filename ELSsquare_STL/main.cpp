#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "myQtGraphicsItem.h"
#include "myqtwidget.h"
#include <qtimer.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    std::srand(std::time(NULL));
    QApplication a(argc, argv);
    myQtGraphicsItem *item = new myQtGraphicsItem;

    QGraphicsScene *myGS = new QGraphicsScene();
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();
    myGS->addItem(item);
    myQtWidget myWidget ;
    myWidget.setScene(myGS);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), myGS, SLOT(advance()));
    timer.start(1000);
    myWidget.show();
    return QApplication::exec();
}