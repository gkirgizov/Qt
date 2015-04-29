#include "gungraphicsitem.h"

#include <QVector>

GunGraphicsItem::GunGraphicsItem(QGraphicsItem *parent) :
	QGraphicsItem(parent) {}

GunGraphicsItem::GunGraphicsItem(qreal left, qreal top, qreal width, qreal height, qreal angle, QGraphicsItem *parent) :
	QGraphicsItem(parent),
	left_(left),
	top_(top),
	width_(width),
	height_(height)
{
	this->setTransformOriginPoint(left, top);
	this->setRotation(angle);
}

QRectF GunGraphicsItem::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(left_ - penWidth / 2, top_ - penWidth / 2,
				  width_ + penWidth, height_ + penWidth);
}

void GunGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QVector<QRectF> rects;
	rects.push_back(QRectF(left_, top_, width_ / 2, height_));
	rects.push_back(QRectF(left_ + width_ / 2, top_ + height_ / 4, width_ / 2, height_ / 2));
	painter->drawRects(rects);
}

QPointF GunGraphicsItem::fireFrom()
{
	return (this->boundingRect().topRight() + this->boundingRect().bottomRight()) / 2;
}

qreal GunGraphicsItem::left() { return left_; }
qreal GunGraphicsItem::top() { return top_; }
qreal GunGraphicsItem::width() { return width_; }
qreal GunGraphicsItem::height() { return height_; }
