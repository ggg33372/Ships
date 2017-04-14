#ifndef BASE_H
#define BASE_H

#include <QGraphicsRectItem>

class Base : public QGraphicsRectItem
{
public:
    enum { Type = UserType + 3 };

    Base();

    void unload();

    // QGraphicsItem interface
    int type() const;
};

#endif // BASE_H
