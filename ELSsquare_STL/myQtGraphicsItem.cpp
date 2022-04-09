//
// Created by shinexr on 2022/3/29.
//

#include "myQtGraphicsItem.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <Qt>
#include <QApplication>
#include "mySquare.h"

using namespace shinexr01;

QRectF myQtGraphicsItem::boundingRect() const
{
    qreal penWedth = 2;
    return QRectF(0 - penWedth / 2, 0 - penWedth / 2,
                  PlaceWedth + penWedth, PlaceHeigh + penWedth);
}

void myQtGraphicsItem::advance(int phase)
{
#if 1
    if(phase == 1)
    {
        m_squares.move(std::pair<dircetion,dircetion>(orgin,down) );
        update();
    }
#endif
}

void myQtGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->setBrush(Qt::red);

    for (auto itor = m_squares.getSquares().begin();
         itor != m_squares.getSquares().end(); ++itor)
    {
        painter->drawRect(itor->first * SquareWedth, itor->second * SquareHeigh,
                          SquareWedth, SquareHeigh);
    }
    painter->setBrush(Qt::darkBlue);
    for(auto  itor = m_squares.getFallSquares().begin(); itor != m_squares.getFallSquares().end(); ++itor)
    {
        painter->drawRect(itor->first * SquareWedth, itor->second * SquareHeigh,
                          SquareWedth, SquareHeigh);
    }

}

void myQtGraphicsItem::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_D:
        case Qt::Key_Right:
            m_squares.move(std::pair<int16_t,int16_t>(right,orgin));
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            m_squares.move(std::pair<int16_t,int16_t>(orgin,down));
            break;
        case Qt::Key_A:
        case Qt::Key_Left:
            m_squares.move(std::pair<dircetion,dircetion>(left,orgin));
            break;
        case Qt::Key_Space:
            m_squares.rotal();
        default:
            break;
    }
    update();
}
