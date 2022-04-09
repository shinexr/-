//
// Created by shinexr on 2022/3/29.
//

#ifndef UNTITLED_MYQTGRAPHICSITEM_H
#define UNTITLED_MYQTGRAPHICSITEM_H
#include <QGraphicsItem>
#include "mySquare.h"
using namespace shinexr01;
class myQtGraphicsItem : public QGraphicsItem {

private :
    squares<int16_t,int16_t> m_squares;
protected:
    void keyPressEvent(QKeyEvent *event)override;
public:
    explicit myQtGraphicsItem(): QGraphicsItem(),m_squares(){}

    QRectF boundingRect() const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};


#endif //UNTITLED_MYQTGRAPHICSITEM_H
