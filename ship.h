#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPathItem>

class Ship : public QGraphicsPathItem
{
public:
	Ship(qreal x=0, qreal y=0, bool direction=true);

	void moveUp(float shift);
	void moveDown(float shift);
	void moveLeft(float shift);
	void moveRight(float shift);

	void setDirection(bool rightDirection);

protected:
	// QGraphicsItem interface
	virtual void keyPressEvent(QKeyEvent *event);

	// QGraphicsItem interface
	virtual void focusInEvent(QFocusEvent *event);
	virtual void focusOutEvent(QFocusEvent *event);

private:
	bool	 direction;
	QPolygon right;
	QPolygon left;
};

#endif // SHIP_H
