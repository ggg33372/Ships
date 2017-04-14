#include "base.h"
#include "ship.h"

#include <QPen>
#include <QBrush>

Base::Base(): QGraphicsRectItem(512, -32, 192, 96)
{
    setPen(QPen(Qt::magenta));
    setBrush(QBrush(Qt::darkGreen));
}

void Base::unload()
{
    QList<QGraphicsItem *> ships = collidingItems();
    for (QList<QGraphicsItem *>::ConstIterator it = ships.constBegin(); it!=ships.constEnd(); ++it)
    {
        Ship *ship = qgraphicsitem_cast<Ship *>(*it);
        if (ship && ship->isLoaded())
            ship->unload();
    }
}

int Base::type() const
{
    return Type;
}
