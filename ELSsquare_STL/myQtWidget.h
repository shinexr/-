//
// Created by Raytine on 2022/3/31.
//

#ifndef ELSSQUARE_MYQTWIDGET_H
#define ELSSQUARE_MYQTWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class myQtWidget; }
QT_END_NAMESPACE

class myQtWidget : public QWidget
{
Q_OBJECT

public:
    explicit myQtWidget(QWidget *parent = nullptr);

    ~myQtWidget() override;

private:
    Ui::myQtWidget *ui;

public:
    void setScene(QGraphicsScene * graphicsScene);
};


#endif //ELSSQUARE_MYQTWIDGET_H
