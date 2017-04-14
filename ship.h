#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPathItem>
class Port;

class Ship : public QGraphicsPathItem
{
public:
    enum { Type = UserType + 1 };

    Ship(qreal x=0, qreal y=0, bool direction=true);

	void moveUp(float shift);
	void moveDown(float shift);
	void moveLeft(float shift);
	void moveRight(float shift);

	void setDirection(bool rightDirection);

    void load();
    void unload();
    bool isLoaded() const;

    static void createPolygons();

    // QGraphicsItem interface
    int type() const;

protected:
	// QGraphicsItem interface
	virtual void keyPressEvent(QKeyEvent *event);

	// QGraphicsItem interface
	virtual void focusInEvent(QFocusEvent *event);
	virtual void focusOutEvent(QFocusEvent *event);

private:
    bool     loaded;
	bool	 direction;

    static QPolygon right;
    static QPolygon left;
};

#endif // SHIP_H
