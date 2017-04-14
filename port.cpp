#include "port.h"
#include "ship.h"

#include <QDebug>
#include <QPen>
#include <QBrush>


Port::Port(): QGraphicsRectItem(-512, 0, 128, 128)
{
    setPen(QPen(Qt::red));
    setBrush(QBrush(Qt::darkBlue));
}

void Port::load()
{
    QList<QGraphicsItem *> ships = collidingItems();
    for (QList<QGraphicsItem *>::ConstIterator it = ships.constBegin(); it!=ships.constEnd(); ++it)
    {
        qDebug() << "*it=" << *it;
        Ship *ship = qgraphicsitem_cast<Ship *>(*it);
        qDebug() << "ship=" << ship;
        if (ship && !ship->isLoaded())
            ship->load();
    }
}

int Port::type() const
{
    return Type;
}
