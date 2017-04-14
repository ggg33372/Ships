#ifndef PORT_H
#define PORT_H

#include <QGraphicsRectItem>

class Port : public QGraphicsRectItem
{
public:
    enum { Type = UserType + 2 };

    Port();

    void load();

    // QGraphicsItem interface
    int type() const;
};

#endif // PORT_H
