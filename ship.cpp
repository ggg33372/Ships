#include "ship.h"
#include <QPainterPath>
#include <QKeyEvent>
#include <QBrush>
#include <QPen>

Ship::Ship(qreal x, qreal y, bool direction):
	direction(direction)
{
	setFlag(ItemIsFocusable);
	int points[] = {0, 20, 35, 20, 40, 0, 65, 00, 80, 20, 100, 20, 95, 40, 5, 40, 0, 20};
	right.setPoints(9, points);

	for (int i=0; i<9; ++i)
		points[i*2]=100-points[i*2];
	left.setPoints(9, points);

	QPainterPath path;
	path.addPolygon(direction?right:left);

	setPen(QPen(Qt::blue));
	setBrush(QBrush(Qt::gray));
	setPath(path);
	setPos(x, y);
}

void Ship::moveUp(float shift)
{
	moveBy(0, -shift);
}

void Ship::moveDown(float shift)
{
	moveBy(0, shift);
}

void Ship::moveLeft(float shift)
{
	setDirection(false);
	moveBy(-shift, 0);
}

void Ship::moveRight(float shift)
{
	setDirection(true);
	moveBy(shift, 0);
}

void Ship::setDirection(bool rightDirection)
{
	direction =	rightDirection;
	QPainterPath path;
	path.addPolygon(rightDirection?right:left);
	setPath(path);
}

void Ship::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Up:
			moveUp(10);
			break;

		case Qt::Key_Down:
			moveDown(10);
			break;

		case Qt::Key_Left:
			moveLeft(10);
			break;

		case Qt::Key_Right:
			moveRight(10);
			break;
	}
}

void Ship::focusInEvent(QFocusEvent *event)
{
	setPen(QPen(Qt::green));
	setBrush(QBrush(Qt::lightGray));
	QPainterPath path;
	path.addPolygon(direction?right:left);
}

void Ship::focusOutEvent(QFocusEvent *event)
{
	setPen(QPen(Qt::blue));
	setBrush(QBrush(Qt::gray));
	QPainterPath path;
	path.addPolygon(direction?right:left);
}

